#include <iostream>
#include <string>
#include <map>

int main() {

	std::cout << "[IN]: ";
	std::string inputStr;
	std::getline(std::cin, inputStr);
	
	// для подсчета кол-ва букв будем использовать map, где ключ - буква, а значение - кол-во, 
	// т.к. поиск буквы по ключу за O(logN);
	// для сортировки создадим второй multimap, в который скопируем все элементы получившегося map,
	// меняя местами ключ и значение для сортировки за O(Nlog2N)

	std::map<char, int> calcMap;
	std::multimap<int, char, std::greater<int>> resultMap;

	for (char c : inputStr) {
		auto it = calcMap.find(c);
		if (calcMap.find(c) == calcMap.end())
			calcMap.insert(std::make_pair(c, 1));
		else
			it->second++;
	}

	for (const auto& el : calcMap)
		resultMap.insert(std::make_pair(el.second, el.first));

	std::cout << "[OUT]: " << std::endl;
	for (const auto& el : resultMap)
		std::cout << el.second << " : " << el.first << std::endl;

	return 0;
}
