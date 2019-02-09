#pragma once
#include <iostream>
#include <map>
#include <string>

std::map<char,char> makeCypher();
void showKeysMap(std::map<char,char> &keysMap);
std::string encryption(std::string words, std::map<char,char> mapCypher);
std::map<char,char> swapKeyWithValue(std::map<char,char> mapCypher);
std::string decryption(std::string cyphredWords, std::map<char,char> mapCypher);
std::string encryptionFile(std::string fileName, std::map<char,char> mapCypher);


