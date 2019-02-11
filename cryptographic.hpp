#pragma once
#include <functional>
#include <iostream>
#include <map>
#include <string>

std::map<char,char> makeCypher();
void showKeysMap(std::map<char,char> &keysMap);
std::string encrypt(std::string words, std::map<char,char> mapCypher);
std::map<char,char> swapKeyWithValue(std::map<char,char> mapCypher);
std::string decrypt(std::string cyphredWords, std::map<char,char> mapCypher);

void saveToFile(const std::string fileName, std::string data, std::map<char,char> mapCypher, std::function<std::string (std::string, std::map<char,char>)> decryptEncrypt = nullptr);
std::string loadFromFile(const std::string fileName, std::map<char,char> mapCypher, std::function<std::string (std::string, std::map<char,char>)> decryptEncrypt = nullptr);
