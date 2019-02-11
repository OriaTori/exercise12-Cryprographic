#include "cryptographic.hpp"
#include <iostream>

int main()
{
    std::map<char,char> mapCypher = makeCypher();
    showKeysMap(mapCypher);
    std::string words = encrypt("Hello World!", mapCypher);
    std::cout << words << std::endl;
    std::cout << decrypt(words, mapCypher) << std::endl;
    std::cout << "Try to save encrypt to file" << std::endl;
    std::string data = "Hello World! What is your name?\n";
    
    saveToFile("file1.txt", data, mapCypher, encrypt);
    std::string dataFrom;
    dataFrom = loadFromFile("file1.txt", mapCypher);
    std::cout << "Encrypted: " << dataFrom << std::endl;
    dataFrom = loadFromFile("file1.txt", mapCypher, decrypt);
    std::cout << "Decrypted: " << dataFrom << std::endl;

    saveToFile("file2.txt", dataFrom, mapCypher);
    std::cout << "Decrypted: " << loadFromFile("file2.txt", mapCypher) << std::endl;
    
    saveToFile("file3.txt", dataFrom, mapCypher, encrypt);
    dataFrom = loadFromFile("file3.txt", mapCypher);
    std::cout << "Encrypted: " << dataFrom << std::endl;
    std::cout << "Decrypted: " << loadFromFile("file3.txt", mapCypher, decrypt) << std::endl;
    return 0;
}
