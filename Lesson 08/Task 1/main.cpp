#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {

	std::cout << "[IN]: ";
	std::string inputStr;
	std::getline(std::cin, inputStr);
	std::istringstream iss(inputStr);

	std::vector<int> vec;
	int value;
	while (iss >> value)
		vec.push_back(value);
	
	std::sort(vec.begin(), vec.end());
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());

	for (int c : vec)
		std::cout << c << " ";

	return 0;
}
