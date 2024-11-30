#include <chrono>
#include <random>
#include <thread>
#include <fastdds/rtps/transport/TCPv4TransportDescriptor.h>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/qos/DomainParticipantQos.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/qos/PublisherQos.hpp>
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>

#include "client_one_dp.hpp"

ClientOne::ClientOne() 
	: participant_(nullptr)
	, publisher_(nullptr)
	, dw_(nullptr)
{
}

void ClientOne::PubListener::on_publication_matched(DataWriter* /*pub*/, const PublicationMatchedStatus& info)
{
    if (info.current_count_change == 1)
    {
        n_matched = info.current_count;
        std::cout << "DataWriter matched." << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        n_matched = info.current_count;
        std::cout << "DataWriter unmatched." << std::endl;
    }
}

ClientOne::~ClientOne()
{
	participant_->delete_contained_entities();
	DomainParticipantFactory::get_instance()->delete_participant(participant_);
}

bool ClientOne::init() {
    DomainParticipantFactory::get_instance()->load_XML_profiles_file("../../../profiles/profile.xml");

    participant_ = DomainParticipantFactory::get_instance()->create_participant_with_profile(0, "client1");
    if (participant_ == nullptr) {
        std::cout << "participant failed" << std::endl;
        return false;
    }
  
    TypeSupport ts(new discovery_serverPubSubType());

    ts.register_type(participant_);
    Topic* topic = participant_->create_topic_with_profile("ExampleTopic", ts.get_type_name(), "topic");
    if (topic == nullptr) {
        std::cout << "topic failed" << std::endl;
        return false;
    }
    
    publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT);

    dw_ = publisher_->create_datawriter_with_profile(topic, "dw", &listener);

    if (dw_ == nullptr) {
        std::cout << "dw failed" << std::endl;
        return false;
    }

    return true;
}

void ClientOne::runThread(
    uint32_t samples,
    uint32_t sleep)
{
    if (samples == 0)
    {
        
        while (!stop)
        {
            if (publish(false))
            {
                std::cout << "Message: " << sample.msg() << " with index: " << sample.id() << " SENT" <<
                    std::endl;
            }
            std::this_thread::sleep_for(std::chrono::duration<uint32_t, std::milli>(sleep));
        }
    }
    else
    {
        for (uint32_t i = 0; i < samples; ++i)
        {
            if (!publish())
            {
                --i;
            }
            else
            {
                std::cout << "Message: " << sample.msg() << " with index: " << sample.id() << " SENT" <<
                    std::endl;
            }
            std::this_thread::sleep_for(std::chrono::duration<uint32_t, std::milli>(sleep));
        }
    }
}


void ClientOne::run(uint32_t samples,uint32_t sleep)
{
    stop = false;
    std::thread thread(&ClientOne::runThread, this, samples, sleep);
    if (samples == 0)
    {
        std::cout << "Publisher running. Please press enter to stop the Publisher at any time." << std::endl;
        std::cin.ignore();
        stop = true;
    }
    else
    {
        std::cout << "Publisher running " << samples << " samples." << std::endl;
    }
    thread.join();
}

bool ClientOne::publish(bool waitForListener)
{
    if (!waitForListener || listener.n_matched > 0)
    {
        sample.id(sample.id() + 1);
        dw_->write((void*)&sample);
        return true;
    }
    return false;
}

