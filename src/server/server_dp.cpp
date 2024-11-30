#include "server_dp.hpp"
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>
#include <fastdds/dds/publisher/qos/PublisherQos.hpp>
#include <fastdds/rtps/transport/shared_mem/SharedMemTransportDescriptor.h>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/Topic.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/core/condition/Condition.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastdds::rtps;

DiscoveryServer::DiscoveryServer():
    participant_(nullptr) {}

bool DiscoveryServer::init() {
    DomainParticipantFactory::get_instance()->load_XML_profiles_file("../../../profiles/profile.xml");

    participant_ = DomainParticipantFactory::get_instance()->create_participant_with_profile(0, "server");
    if (participant_ == nullptr) {
        return false;
    }

    return true;
}

DiscoveryServer::~DiscoveryServer()
{
	if (participant_ != nullptr)
	{
		DomainParticipantFactory::get_instance()->delete_participant(participant_);
	}
}

void DiscoveryServer::run() {
    std::cout << "Server running. Please press enter to stop the server" << std::endl;
    std::cin.ignore();
}