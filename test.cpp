#include "utils.hpp"
#include "sha256.hpp"

int main(int argc, char ** argv){
	std::cout << "Hi " << std::endl;
	std::cout << to_bits(24) << std::endl;
	std::cout << bin_to_num(std::string("00000000000000000000000000011001")) << std::endl;
	return 0;
}