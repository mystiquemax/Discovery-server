#include "client_one_dp.hpp"

int main(int argc, char** argv) {

	std::cout << "Starting client1" << std::endl;

	ClientOne client_one;

	if (client_one.init()) {
		client_one.run(20,2);
	}
}