#include "utils.hpp"
#include "sha256.hpp"

SHA256::SHA256(){
	this->hash = new uint32_t[8];
	this->block_size = 512;
	this->digest_size = 256;
	this->word_size = 32;
	this->initial_hash = new uint32_t[8];
	this->initial_hash[0] = hex_to_num(std::string("6a09e667"));
	this->initial_hash[1] = hex_to_num(std::string("bb67ae85"));
	this->initial_hash[2] = hex_to_num(std::string("3c6ef372"));
	this->initial_hash[3] = hex_to_num(std::string("a54ff53a"));
	this->initial_hash[4] = hex_to_num(std::string("510e527f"));
	this->initial_hash[5] = hex_to_num(std::string("9b05688c"));
	this->initial_hash[6] = hex_to_num(std::string("1f83d9ab"));
	this->initial_hash[7] = hex_to_num(std::string("5be0cd19"));

	this->constants = new uint32_t[64]{hex_to_num(std::string("428a2f98")),hex_to_num(std::string("71374491")),hex_to_num(std::string("b5c0fbcf")),hex_to_num(std::string("e9b5dba5")),hex_to_num(std::string("3956c25b")),hex_to_num(std::string("59f111f1")),hex_to_num(std::string("923f82a4")),hex_to_num(std::string("ab1c5ed5")),hex_to_num(std::string("d807aa98")),hex_to_num(std::string("12835b01")),
										hex_to_num(std::string("243185be")),hex_to_num(std::string("550c7dc3")),hex_to_num(std::string("72be5d74")),hex_to_num(std::string("80deb1fe")),hex_to_num(std::string("9bdc06a7")),hex_to_num(std::string("c19bf174")),hex_to_num(std::string("e49b69c1")),hex_to_num(std::string("efbe4786")),hex_to_num(std::string("0fc19dc6")),hex_to_num(std::string("240ca1cc")),
										hex_to_num(std::string("2de92c6f")),hex_to_num(std::string("4a7484aa")),hex_to_num(std::string("5cb0a9dc")),hex_to_num(std::string("76f988da")),hex_to_num(std::string("983e5152")),hex_to_num(std::string("a831c66d")),hex_to_num(std::string("b00327c8")),hex_to_num(std::string("bf597fc7")),hex_to_num(std::string("c6e00bf3")),hex_to_num(std::string("d5a79147")),
										hex_to_num(std::string("06ca6351")),hex_to_num(std::string("14292967")),hex_to_num(std::string("27b70a85")),hex_to_num(std::string("2e1b2138")),hex_to_num(std::string("4d2c6dfc")),hex_to_num(std::string("53380d13")),hex_to_num(std::string("650a7354")),hex_to_num(std::string("766a0abb")),hex_to_num(std::string("81c2c92e")),hex_to_num(std::string("92722c85")),										
										hex_to_num(std::string("a2bfe8a1")),hex_to_num(std::string("a81a664b")),hex_to_num(std::string("c24b8b70")),hex_to_num(std::string("c76c51a3")),hex_to_num(std::string("d192e819")),hex_to_num(std::string("d6990624")),hex_to_num(std::string("f40e3585")),hex_to_num(std::string("106aa070")),hex_to_num(std::string("19a4c116")),hex_to_num(std::string("1e376c08")),
										hex_to_num(std::string("2748774c")),hex_to_num(std::string("34b0bcb5")),hex_to_num(std::string("391c0cb3")),hex_to_num(std::string("4ed8aa4a")),hex_to_num(std::string("5b9cca4f")),hex_to_num(std::string("682e6ff3")),hex_to_num(std::string("748f82ee")),hex_to_num(std::string("78a5636f")),hex_to_num(std::string("84c87814")),hex_to_num(std::string("8cc70208")),
										hex_to_num(std::string("90befffa")),hex_to_num(std::string("a4506ceb")),hex_to_num(std::string("bef9a3f7")),hex_to_num(std::string("c67178f2"))};

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
		Accepts a message string which is binary and pads it till it's length is divisible by this->block_size = 512
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

void SHA256::parse(std::string message){
	/*
		Takes in a binary padded message string and divides it into blocks. Those blocks are block_size bits long and divided further into words are saved to this->padded_message
	*/
	//So, the messsage is divided into blocks (num of blocks depends on its length) and each block is divided into (block_size/word_size, which is 512/32 = 16) words. 
	//Each word is essentially a uint32_t
	int n = message.size();
	if(n%this->block_size != 0){
		return;
	}
	int i,j;
	std::string tmp_block, tmp_word;
	uint32_t* msg_block;
	while(i<n){
		msg_block = new uint32_t[16];
		tmp_block = message.substr(i,this->block_size);
		j = 0;
		while(j < this->block_size){
			tmp_word = tmp_block.substr(j,this->word_size);
			msg_block[j/this->word_size] = bin_to_num(tmp_word);
			j += this->word_size;
		}
		padded_message.push_back(msg_block);
		i += this->block_size;
	}
	return;
}

void SHA256::hash_num(){
	//the message is already loaded into padded message, so we don't require any arguments
	int num_blocks = this->padded_message.size();
	int i,t;
	uint32_t *word_schedule = new uint32_t[64];
	uint32_t a,b,c,d,e,f,g,h,T1,T2;
	std::memcpy(this->hash,this->initial_hash,sizeof(uint32_t)*8);
	for(i=0;i<num_blocks;i++){
		std::memcpy(word_schedule,this->padded_message[i],16*sizeof(uint32_t));
		t = 16;
		while(t < 64){
			word_schedule[t] = alpha1(word_schedule[t-2]) + word_schedule[t-7] + alpha0(word_schedule[t-15]) + word_schedule[t-16];
			t++;
		}
		a = this->hash[0];
		b = this->hash[1];
		c = this->hash[2];
		d = this->hash[3];
		e = this->hash[4];
		f = this->hash[5];
		g = this->hash[6];
		h = this->hash[7];
		T1 = 0;
		for(t=0;t<63;t++){
			T1 = h + sigma1(e)  + ch(e,f,g) + this->constants[t] + word_schedule[t];
			T2 = sigma0(a) + maj(a,b,c);
			h = g;
			g = f;
			f = e;
			e = d + T1;
			d = c;
			c = b;
			b = a;
			a = T1 + T2;
		}
		this->hash[0] = a + this->hash[0];
		this->hash[1] = b + this->hash[1];
		this->hash[2] = c + this->hash[2];
		this->hash[3] = d + this->hash[3];
		this->hash[4] = e + this->hash[4];
		this->hash[5] = f + this->hash[5];
		this->hash[6] = g + this->hash[6];
		this->hash[7] = h + this->hash[7];
	}
}

uint32_t *SHA256::hash_message(std::string message, std::string option){
	if(option == BIN){
		//message is binary
		this->pad(message);
		this->parse(message);
		this->hash_num();
		return this->hash;

	}else if(option == HEX){
		//message is hexadecimal
		message = hex_to_bin(message);
		this->pad(message);
		this->parse(message);
		this->hash_num();
		return this->hash;

	}else if(option == STR){
		//message is a string
		message = string_to_bin(message);
		this->pad(message);
		std::cout << "Padded" <<std::endl;
		this->parse(message);
		std::cout << "Parsed" << std::endl;
		this->hash_num();
		std::cout << "Hashed" << std::endl;
		return this->hash;

	}else{
		std::cout << "This option has not been implemented, returning nullptr." << std::endl << "Usage: Only use with options hex, binary or string";
		return nullptr;
	}
}