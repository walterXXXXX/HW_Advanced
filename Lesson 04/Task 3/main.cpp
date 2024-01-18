#include <iostream>
#include <string>
#include <sstream>

class NumCounter {
public:

	void operator()(int number) {
		if (!(number % 3)) {
			sum += number;
			count++;
		}
	}

	int getSum() { return sum; }
	int getCount() { return count; }

private:
	int sum = 0; // сумма чисел, делящихся на 3
	int count = 0; // кол-во чисел, делящихся на 3
};

int main() {
	setlocale(LC_ALL, "");

	std::cout << "[IN]: ";
	std::string inputStr;
	std::getline(std::cin, inputStr);
	std::istringstream iss(inputStr);

	NumCounter numCounter;

	try {
		std::string str;
		while (iss >> str) {
			numCounter(std::stoi(str));
		}
		std::cout << "[OUT]: get_sum() = " << numCounter.getSum() << std::endl;
		std::cout << "[OUT]: get_count() = " << numCounter.getCount() << std::endl;
	}
	catch (const std::invalid_argument& ex) {
		std::cout << "Некорректный ввод" << std::endl;
	}
	catch (const std::out_of_range& ex) {
		std::cout << "Введено число за допустимыми границами диапазона" << std::endl;
	}

	return 0;
}