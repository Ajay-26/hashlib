#include "utils.hpp"
#include "sha256.hpp"

int main(int argc, char ** argv){
	std::chrono::steady_clock::time_point begin,end;
	std::cout << "Hi " << std::endl;
	std::cout << to_bits(24) << std::endl;
	std::cout << bin_to_num(std::string("00000000000000000000000000011001")) << std::endl;
	std::cout << string_to_bin(std::string("geeks")) << std::endl;
	std::cout << "Time to hash!" << std::endl;
	SHA256 hash;
	begin = get_time();
	uint32_t* h = hash.hash_message(std::string("Hey man"),STR);
	end = get_time();
	print_hash(h);
	print_time_diff(begin,end);
	return 0;
}