#include <iostream>
#include <set>
#include <list>
#include <vector>

template <class T>
void printContainer(T cont) {
	for (std::string el : cont)
		std::cout << el << " ";
	std::cout << std::endl;
}

int main() {

	std::set<std::string> test_set = { "one", "two", "three", "four" };
	printContainer(test_set); // four one three two

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	printContainer(test_list); // one, two, three, four

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	printContainer(test_vector); // one, two, three, four
	
	return 0;
}
