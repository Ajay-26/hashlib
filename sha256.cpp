#include "utils.hpp"
#include "sha256.hpp"

SHA256::SHA256(){
	this->hash = new uint32_t(8);
	this->block_size = 512;
	this->digest_size = 256;
	this->word_size = 32;
}

std::string SHA256::to_binary(std::string message){
	/*
		Takes a hex message string and converts to binary
	*/
	std::string new_str;
	int n = message.size();
	int i;
	std::map<char,std::string> hex_to_bin = {{'0',std::string("0000")},{'1',std::string("0001")},{'2',std::string("0010")},
							{'3',std::string("0011")},{'4',std::string("0100")},{'5',std::string("0101")},{'6',std::string("0110")},{'7',std::string("0111")},
							{'8',std::string("1000")},{'9',std::string("1001")},{'a',std::string("1010")},{'A',std::string("1010")},{'b',std::string("1011")},
							{'B',std::string("1011")},{'c',std::string("1100")},{'C',std::string("1100")},{'d',std::string("1101")},{'D',std::string("1101")},
							{'e',std::string("1110")},{'E',std::string("1110")},{'f',std::string("1111")},{'F',std::string("1111")}
						};

	for(i=0;i<n;i++){
		new_str = new_str + hex_to_bin[message[i]];
	}
	return new_str;
}

void SHA256::pad(std::string& message){
	/*
		Accepts a message string which is binary and pads it
	*/
	int n = message.size();
	int k = 0;
	if(n%this->block_size == 0){
		return;
	}else{
		message = message + "1";
		while((n + k + 1)%512 < 448 ){
			message = message + "0";
			k++;
		}
		message = message + to_bits(n);
		return;
	}
}