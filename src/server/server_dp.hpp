#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantListener.hpp>
#include "../types/data_typePubSubTypes.h"
#include "../types/data_type.h"

class DiscoveryServer
{
public:
	DiscoveryServer();
	virtual ~DiscoveryServer();
	void run();
	bool init();
 
private:
	eprosima::fastdds::dds::DomainParticipant* participant_;
};