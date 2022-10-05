/*
This SHA256 algorithm is taken from https://csrc.nist.gov/csrc/media/publications/fips/180/4/final/documents/fips180-4-draft-aug2014.pdf
*/

#pragma once
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>

#define HEX "hex"
#define BIN "bin"
#define STR "string"


class SHA256{
public:
	SHA256();
	uint32_t *hash_message(std::string message, std::string option);

private:
	std::vector<uint32_t *> padded_message;
	uint32_t *hash;
	uint32_t *initial_hash;
	uint32_t *constants;
	int block_size;
	int word_size;
	int digest_size;
	std::string to_binary(std::string message);
	void pad(std::string& message);
	void parse(std::string message);
	void hash_num();
};