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
		//DictionaryAttack();
		DictionaryAttack(std::string givenHash, std::string hash_Type);
		bool loadDictionary(std::string filename);
		void launchDictionaryAttack(std::ifstream *filename, std::string &hash);
		std::string calculateHash_MD5(std::string input);
		std::string calculateHash_SHA1(std::string input);
		std::string calculateHash_SHA256(std::string input);
		std::string calculateHash_SHA512(std::string input);
		bool compareHashes(std::string DictionaryHash, std::string line);
		
	//	std::string getLine() const;
	//	int getLineCount() const;
		
	//	void setLine(std::string line);
	//	void setLineCount(int lineCount);
	private:
		std::string hash;
		std::string hashType;
};
#endif