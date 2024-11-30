#include "client_two_dp.hpp"

int main(int argc, char** argv) {

	std::cout << "Starting client2" << std::endl;

	ClientTwo client_two;

	if (client_two.init()) {
		client_two.run();
	}
}