#include "server_dp.hpp"

int main(int argc, char** argv) {
	
	std::cout << "Starting server" << std::endl;

	DiscoveryServer server;

	if (server.init()) {
		server.run();
	}
}