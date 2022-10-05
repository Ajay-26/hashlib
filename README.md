# hashlib

A lot of my friends expressed difficult finding a good SHA256 library in C++. Of course, there are great SHA256 libraries such as Crypto++, and I don't claim to be better than them by any means, but I thought, I'd have a crack at building a SHA256 hashing library on my own. The time taken to hash a string of average length (around 50 characters) was approximately 40 microseconds. I did not use multithreading or any sort of parallelisation, but plan to do so in the future. I tried to make it as fast as possible, but given my limited experience, I am sure that there are several optimisations that can be made. The objective of this library is to get some experience coding under my belt, as well as making a library which my friends can easily use for their assignments (one of them is very cute I hope she uses it in particular).

Usage instructions:
The test.cpp file is merely for testing. The Makefile will simply run the test.cpp file. To actually use the hash functions, one must include sha256.hpp in their own files. It has one public function, and that is to return a pointer to the hash, which is an array of size 8 and datatype uint32_t
Memory need not be allocated to the array. A separate function to print the value of this hash is given in utils.cpp and it also has a function to convert this hash 'array' to a string of bits.

Hope you find this helpful!
