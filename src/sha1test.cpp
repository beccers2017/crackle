#include <iostream>
#include <cstring>

#include <openssl/sha.h>

using namespace std;

char data[] = "Hello, World!";
size_t length = strlen(data);

unsigned char h[SHA_DIGEST_LENGTH];

std::string hs = SHA1(data, length, h);
printf("%s", hs);