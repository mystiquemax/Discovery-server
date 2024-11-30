#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

#include "../types/data_type.h"
#include "../types/data_typePubSubTypes.h"

using namespace eprosima::fastdds::dds;

class ClientTwo {
public:
	ClientTwo();
	virtual ~ClientTwo();
	bool init();
	void run();
	void run(uint32_t n);

    class SubListener : public DataReaderListener
    {
    public:

        SubListener()
            : n_matched(0)
            , n_samples(0)
        {
        }

        ~SubListener()
        {
        }

        void on_subscription_matched(DataReader* sub, const SubscriptionMatchedStatus& info);
        void on_data_available(DataReader* sub);
        discovery_server sample;
        SampleInfo m_info;
        int n_matched;
        uint32_t n_samples;
    }
    listener;


private:
	DomainParticipant* participant_;
	Subscriber* subscriber_;
	DataReader* dr;
};