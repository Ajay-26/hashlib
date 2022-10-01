#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <assert.h>

std::string to_bits(int n);

std::string hex_to_bin(std::string hex);

uint32_t bin_to_num(std::string bits);

uint32_t hex_to_num(std::string hex);