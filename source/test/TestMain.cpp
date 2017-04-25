#include <Drawer.hpp>
#include <iostream>
#include "ExpressionGrammar.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <gtest/gtest.h>

using namespace std;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
