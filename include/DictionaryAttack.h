/**
 * @file DictionaryAttack.h
 * @author Rebecca Donohoe
 * @version 0.1.0
 */
#ifndef DICTIONARYATTACK_H
#define DICTIONARYATTACK_H

#include <iostream>
#include <fstream>
#include <string>

class DictionaryAttack {
	public:
		DictionaryAttack(std::string givenHash, std::string hash_type);
		bool loadDictionary(std::string &filename);
		void launchDictionaryAttack(std::ifstream &file);
		std::string calculateHash_MD5(std::string input);
		std::string calculateHash_SHA1(std::string input);
		std::string calculateHash_SHA256(std::string input);
		std::string calculateHash_SHA512(std::string input);
		bool compareHashes(std::string dictionaryHash, std::string line);
		
	private:
		std::string hash;
		std::string hashType;
};
#endif