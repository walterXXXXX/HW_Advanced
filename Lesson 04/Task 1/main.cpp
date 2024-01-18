#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <sstream>

template <typename T1>
T1 mySqr(T1 value) {
	// шаблон функции работает с простыми числами
	T1 res = value * value;

	return res;
}


template <>
std::vector<double> mySqr(std::vector<double> values) {
	// специализация шаблона работает с векторами
	for (auto& el : values) el = mySqr(el);

	return values;
}



int main() {

	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "eng");

    while (true) {
        std::cout << "[IN]: ";
        std::string inputStr;
        std::getline(std::cin, inputStr);
		if (inputStr == "exit") break;
		std::cout << "[OUT]: ";

		try {
			std::vector<double> values;
			std::vector<double> result;
			std::istringstream iss(inputStr);

			// преобразуем введенную строку в вектор значений double и вызываем mySqr для вектора;
			std::string str;
			while (std::getline(iss, str, ',')) {
				double value = std::stod(str); // выбрасывает исключение std::invalid_argument или std::out_of_range
				values.push_back(value); 
			}

			result = mySqr(values);

			for (const auto& el : result) std::cout << el << " ";
			std::cout << std::endl;
		}
		catch (const std::invalid_argument& ex) {
			std::cout << "Некорректный ввод" << std::endl;
		}
		catch (const std::out_of_range& ex) {
			std::cout << "Введенное число вне диапазаона" << std::endl;
		}
	}
		
	return 0;
}
