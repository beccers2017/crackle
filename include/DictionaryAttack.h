/**
 * @file DictionaryAttack.h
 * @author Rebecca Donohoe
 * @version 0.1.0
 */
#ifndef DICTIONARYATTACK_H
#define DICTIONARYATTACK_H

#include <iostream>
#include <string>

class DictionaryAttack {
	public:
		//DictionaryAttack();
		DictionaryAttack(std::string givenHash);
		bool loadDictionary(std::string filename);
		void launchDictionaryAttack(std::string filename, std::string hashType);
		void calculateHash_MD5(std::string input);
		void calculateHash_SHA1(std::string input);
		void calculateHash_SHA256(std::string input);
		void calculateHash_SHA512(std::string input);
		void compareHashes(std::DictionaryHash);
	private:
		std::string hash;
		
};
#endif