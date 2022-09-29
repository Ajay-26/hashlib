#include "utils.hpp"

std::string to_bits(int n){
	//Gets binary representation of n
	std::string bits;
	int counter = 0;
	while(n != 0){
		if(n &1){
			bits = "1" + bits;
		}else{
			bits = "0" + bits;
		}

		n = n>>1;
		counter++;
	}
	return bits;
}