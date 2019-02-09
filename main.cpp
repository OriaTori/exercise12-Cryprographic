#include "cryptographic.hpp"
#include <iostream>

int main()
{
    std::map<char,char> mapCypher = makeCypher();
    showKeysMap(mapCypher);
    std::string words = encryption("Hello World!", mapCypher); 
    decryption(words, mapCypher); 
    return 0;
}
