#include "../src/main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("BST Insert", "[flag]"){
	
		Binary_tree tree;   // Create a Tree object 
		tree.insert(45674567, "Brandon");
		tree.insert(35455565, "Brian" );
		tree.insert(87878787,"Briana" );
		tree.insert(95462138, "Bella");
		tree.print_inorder_helper();
		tree.remove(45674567);
		tree.remove_N(2);
		tree.print_inorder_helper();
		//tree.insert(3);
		//tree.insert(2);
		//tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = { 35455565, 87878787,95462138 };
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	
	REQUIRE(1 == 1);
}