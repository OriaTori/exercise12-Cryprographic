#include "cryptographic.hpp"
#include <iostream>

int main()
{
    std::map<char,char> mapCypher = makeCypher();
    showKeysMap(mapCypher);
    std::string words = encryption("Hello World!", mapCypher);
    std::cout << words << std::endl;
    std::cout << decryption(words, mapCypher) << std::endl;
    std::cout << encryptionFile("file.txt", mapCypher) << std::endl;
    return 0;
}
