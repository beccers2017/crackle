CXX = g++
CXXFLAGS = -std=c++11 -lcrypto

TARGET = crackle

all: $(TARGET)

clean:
	rm crackle

crackle: crackle.cpp UserInterface.cpp DictionaryAttack.cpp
	$(CXX) $(CXXFLAGS) crackle.cpp -o crackle 

