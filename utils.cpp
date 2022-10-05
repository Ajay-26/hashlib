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

std::string hex_to_bin(std::string hex){
	/*
		Takes a hex message string and converts to binary
	*/
	std::string new_str;
	int n = hex.size();
	int i;
	std::map<char,std::string> hex_to_bin = {{'0',std::string("0000")},{'1',std::string("0001")},{'2',std::string("0010")},
							{'3',std::string("0011")},{'4',std::string("0100")},{'5',std::string("0101")},{'6',std::string("0110")},{'7',std::string("0111")},
							{'8',std::string("1000")},{'9',std::string("1001")},{'a',std::string("1010")},{'A',std::string("1010")},{'b',std::string("1011")},
							{'B',std::string("1011")},{'c',std::string("1100")},{'C',std::string("1100")},{'d',std::string("1101")},{'D',std::string("1101")},
							{'e',std::string("1110")},{'E',std::string("1110")},{'f',std::string("1111")},{'F',std::string("1111")}
						};

	for(i=0;i<n;i++){
		new_str = new_str + hex_to_bin[hex[i]];
	}
	return new_str;
}

uint32_t bin_to_num(std::string bits){
	//Converts binary string to number
	int n = bits.size();
	assert(n == 32);
	int i;
	uint32_t num = 0;
	for(i=0;i<n;i++){
		//std::cout << bits[i] << std::endl;
		num = (num<<1) ^ (static_cast<int>(bits[i]) - static_cast<int>('0'));
	}
	return num;
}

uint32_t hex_to_num(std::string hex){
	return bin_to_num(hex_to_bin(hex));
}

std::string string_to_bin(std::string str){
	int n = str.size();
	int i;
	int val;
	std::string ans;
	for(i=0;i<n;i++){
		val = static_cast<int>(str[i]);
		ans = ans + to_bits(val);
	}
	return ans;
}

uint32_t rotate_left(uint32_t x, int n){
	int w = 32;
	return (x >> n) | (x << (w - n));
}

uint32_t rotate_right(uint32_t x, int n){
	int w = 32;
	return (x << n) | (x >> (w - n));
}

uint32_t alpha0(uint32_t x){
	return rotate_right(x,7) ^ rotate_right(x,18) ^ rotate_right(x,3);
}

uint32_t alpha1(uint32_t x){
	return rotate_right(x,17) ^ rotate_right(x,19) ^ rotate_right(x,10);
}

uint32_t sigma0(uint32_t x){
	return rotate_right(x,2) ^ rotate_right(x,13) ^ rotate_right(x,22);
}

uint32_t sigma1(uint32_t x){
	return rotate_right(x,6) ^ rotate_right(x,11) ^ rotate_right(x,25);
}

uint32_t ch(uint32_t x,uint32_t y, uint32_t z){
	return (x & y) ^ ((!x) & z);
}

uint32_t maj(uint32_t x,uint32_t y, uint32_t z){
	return (x&y) ^ (y&z) ^ (x&z);	
}

void print_hash(uint32_t *h){
	//h has 8 elements
	int n = 8;
	int i;
	for(i=0;i<n;i++){
		std::cout << h[i];
	}
	std::cout  << std::endl;
	return;
}