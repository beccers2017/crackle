#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE DictionaryTest
#include <boost/test/unit_test.hpp>
#include <exception>
#include <unistd.h>

BOOST_AUTO_TEST_SUITE(test_suite1);




BOOST_AUTO_TEST_CASE(DictionaryTestCase 1) {
	
}

BOOST_AUTO_TEST_CASE(DictionaryTestCase 2) {
	
}


BOOST_AUTO_TEST_SUITE_END();


class DictionaryAttack: public CppUnit::TestFixture {
	std::string calculateHash_MD5_Test() {
		if(calculateHash_MD5(std::string input = "password")) {
			
		}
	}
}