#include "utils.hpp"
#include "sha256.hpp"

int main(int argc, char ** argv){
	std::cout << "Hi " << std::endl;
	std::cout << to_bits(24) << std::endl;
	std::cout << bin_to_num(std::string("00000000000000000000000000011001")) << std::endl;
	std::cout << string_to_bin(std::string("geeks")) << std::endl;
	std::cout << "Time to hash!" << std::endl;
	SHA256 hash;
	uint32_t* h = hash.hash_message(std::string("Hey man"),STR);
	print_hash(h);
	return 0;
}