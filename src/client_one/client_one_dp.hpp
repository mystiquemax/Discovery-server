#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>


#include "../types/data_type.h"
#include "../types/data_typePubSubTypes.h"

using namespace eprosima::fastdds::dds;

class ClientOne {
public:
	ClientOne();
	virtual ~ClientOne();
	bool init();
	bool publish(bool waitForListener = true);
	void run(uint32_t n, uint32_t sleep);

private:
	discovery_server sample;
	DomainParticipant* participant_;
	Publisher* publisher_;
	DataWriter* dw_;

	bool stop;

    class PubListener : public DataWriterListener
    {
    public:

        PubListener()
            : n_matched(0)
        {
        }

        ~PubListener()
        {
        }

        void on_publication_matched(DataWriter* dataWriter, const PublicationMatchedStatus& info);
        int n_matched;
    }
    listener;
    void runThread(uint32_t n, uint32_t sleep);

};