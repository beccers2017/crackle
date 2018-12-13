CXX = g++
CXXFLAGS = -Wall -g -lcrypto

all: crackle

run: crackle
	./crackle

clean:
	rm UserInterface.o DictionaryAttack.o BruteForce.o crackle

crackle: UserInterface.o DictionaryAttack.o BruteForce.o crackle.cpp
	$(CXX) $(CXXFLAGS) crackle.cpp UserInterface.o BruteForce.o DictionaryAttack.o -o crackle

UserInterface.o: UserInterface.cpp
	$(CXX) $(CXXFLAGS) -c src/UserInterface.cpp

DictionaryAttack.o: DictionaryAttack.cpp
	$(CXX) $(CXXFLAGS) -c src/DictionaryAttack.cpp

BruteForce.o: BruteForce.cpp
	$(CXX) $(CXXFLAGS) -c /srcBruteForce.cpp





