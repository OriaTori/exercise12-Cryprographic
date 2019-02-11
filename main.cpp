#include "cryptographic.hpp"
#include <iostream>

int main()
{
    std::map<char,char> mapCypher = makeCypher();
    showKeysMap(mapCypher);
    std::string words = encrypt("Hello World!", mapCypher);
    std::cout << words << std::endl;
    std::cout << decrypt(words, mapCypher) << std::endl;
    std::cout << encryptFile("file.txt", mapCypher) << std::endl;
    std::cout << "Try to save encrypt to file\n";
    std::string data = "Hello World! What is your name?";
    saveToFile("fileToSave.txt", data, mapCypher, encrypt);

    saveToFile("fileToSave2.txt", data, mapCypher, decrypt);
    return 0;
}
