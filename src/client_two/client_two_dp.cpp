#include <fastdds/rtps/transport/TCPv4TransportDescriptor.h>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/qos/DomainParticipantQos.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/qos/SubscriberQos.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include "client_two_dp.hpp"


using namespace eprosima::fastdds;
using namespace eprosima::fastrtps::rtps;
using namespace eprosima::fastdds::rtps;
using namespace eprosima::fastdds::dds;

ClientTwo::ClientTwo()
	: participant_(nullptr)
	, subscriber_(nullptr)
	, dr(nullptr) {}

ClientTwo::~ClientTwo()
{
	participant_->delete_contained_entities();
	DomainParticipantFactory::get_instance()->delete_participant(participant_);
}

void ClientTwo::SubListener::on_subscription_matched(
    DataReader* /*sub*/,
    const SubscriptionMatchedStatus& info)
{
    if (info.current_count_change == 1)
    {
        n_matched = info.current_count;
        std::cout << "Subscriber matched" << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        n_matched = info.current_count;
        std::cout << "Subscriber unmatched" << std::endl;
    }
}

void ClientTwo::SubListener::on_data_available(
    DataReader* sub)
{
    if (sub->take_next_sample((void*)&sample, &m_info) == 0)
    {
        if (m_info.sample_state == NOT_READ_SAMPLE_STATE)
        {
            this->n_samples++;
            std::cout << "Message " << sample.msg() << " " << sample.id() << " RECEIVED" << std::endl;
        }
    }

}

bool ClientTwo::init() {
    DomainParticipantFactory::get_instance()->load_XML_profiles_file("../../../profiles/profile.xml");

    participant_ = DomainParticipantFactory::get_instance()->create_participant_with_profile(0, "client2");
    if (participant_ == nullptr) {
        return false;
    }

    std::cout << "Before" << std::endl;
    TypeSupport ts(new discovery_serverPubSubType());
    std::cout << "After" << std::endl;


    ts.register_type(participant_);

    subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT);

    Topic* topic = participant_->create_topic_with_profile("ExampleTopic", ts.get_type_name(), "topic");
    if (topic == nullptr) {
        return false;
    }

    dr = subscriber_->create_datareader_with_profile(topic, "dr", &listener);

    if (dr == nullptr) {
        return false;
    }

    return true;
}

void ClientTwo::run()
{
    std::cout << "Subscriber running. Please press enter to stop the Subscriber" << std::endl;
    std::cin.ignore();
}

void ClientTwo::run(uint32_t n)
{
    std::cout << "Subscriber running until " << n << "samples have been received" << std::endl;
    while (n > this->listener.n_samples)
    {
        std::this_thread::sleep_for(std::chrono::duration<uint32_t, std::milli>(500));
    }
}
