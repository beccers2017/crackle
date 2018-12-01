CXX = g++
CXXFLAGS = -std=c++11

all: crackle

clean:
	rm crackle

crackle: 
	$(CXX) $(CXXFLAGS) crackle.cpp -o crackle

