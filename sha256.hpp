#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>


class SHA256{
public:
	SHA256();
	uint32_t *hash_message(std::string message);

private:
	std::vector<uint32_t> padded_message;
	uint32_t *hash;
	uint32_t *initial_hash;
	int block_size;
	int word_size;
	int digest_size;
	std::string to_binary(std::string message);
	void pad(std::string& message);
	void parse(std::string message);
};