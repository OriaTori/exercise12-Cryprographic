#include "cryptographic.hpp"
#include <algorithm>
#include <iterator>
#include <random>
#include <utility>

void ciphering(std::string words)
{
    
}
std::map<char,char> makeCypher()
{
    std::map<char,char> mapCypher;
    std::string word, cypher; 
    
    std::generate_n(std::back_insert_iterator<std::string>(word),94,
                    [n=32]() mutable {return ++n;});
    cypher = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cypher.begin(), cypher.end(), g);
    auto it = cypher.begin();
    for(auto key : word)
    {
        auto p = std::make_pair(key,*it);
        ++it;
        mapCypher.insert(p);
    }
    return mapCypher;
}
void showKeysMap(std::map<char,char> &keysMap)
{
    for(auto key : keysMap)
        std::cout << "{ " << key.first << " , " << key.second << " } ";
    std::cout << std::endl;
}
std::string encryption(std::string words, std::map<char,char> mapCypher)
{
    std::string encryptedWords;
    for(auto it : words)
    {
        auto letterCode = mapCypher.find(it);
        if(letterCode != mapCypher.end())
        {
            encryptedWords += letterCode->second;
        }
    }
    words.swap(encryptedWords);
    return words;
}
std::map<char,char> swapKeyWithValue(std::map<char,char> mapCypher)
{
    std::map<char,char> decryptedMap;
    for(auto it : mapCypher)
    {
        auto p = std::make_pair(it.second,it.first);
        decryptedMap.insert(p);
    }
    return decryptedMap;
}
std::string decryption(std::string cyphredWords, std::map<char,char> mapCypher)
{
    std::string decryptedWords;
    std::map<char,char> keyMap = swapKeyWithValue(mapCypher);
    for(auto it : cyphredWords)
    {
        auto letter = keyMap.find(it);
        if(letter != keyMap.end())
        {
            std::cout << letter->first << "\t" << letter->second << std::endl;
            //decryptedWords += letter->second;
        }
    }
    return cyphredWords;
}
