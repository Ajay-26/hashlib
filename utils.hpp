#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <assert.h>
#include <chrono>

std::chrono::steady_clock::time_point get_time();

void print_time_diff(std::chrono::steady_clock::time_point begin, std::chrono::steady_clock::time_point end);

std::string to_bits(int n);

std::string hex_to_bin(std::string hex);

std::string string_to_bin(std::string str);

uint32_t bin_to_num(std::string bits);

uint32_t hex_to_num(std::string hex);

uint32_t rotate_left(uint32_t x, int n);

uint32_t rotate_left(uint32_t x, int n);

uint32_t alpha0(uint32_t x);

uint32_t alpha1(uint32_t x);

uint32_t sigma0(uint32_t x);

uint32_t sigma1(uint32_t x);

uint32_t ch(uint32_t x,uint32_t y, uint32_t z);

uint32_t maj(uint32_t x, uint32_t y, uint32_t z);

void print_hash(uint32_t *h);