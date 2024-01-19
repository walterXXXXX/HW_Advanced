#include <iostream>
#include <string>
#include <set>


int main() {

	std::set<int, std::greater<int>> mySet;

	std::cout << "[IN]: " << std::endl;
	int count;
	std::cin >> count;

	for (int i = 0; i < count; i++) {
		int value;
		std::cin >> value;
		mySet.insert(value);
	}
	
	std::cout << "[OUT]: " << std::endl;
	for (int i : mySet)
		std::cout << i << std::endl;

		
	return 0;
}
