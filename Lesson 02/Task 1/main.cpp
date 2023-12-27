#include <iostream>
#include <exception>

class SmartArray {
public:
	SmartArray(int size) {
		arr = new int[size];
		this->size = size;
		localSize = 0;
	}

	void addElement(int element) {
		if (localSize == size) throw std::exception("Невозможно добавить новый элемент, т.к. массив заполнен");
		arr[localSize] = element;
		localSize++;
	}

	int getElement(int num) {
		if (num < 0 || num > size-1) throw std::exception("Номер элемента вне диапазона массива");
		if (num > localSize-1) throw std::exception("Элемент массива не определен");
		return arr[num];
	}

	~SmartArray() {
		delete[] arr;
	}

private:
	int* arr;
	int size;
	int localSize;
};


int main() {
	setlocale(LC_ALL, "");

	try {
		SmartArray arr(5);
		arr.addElement(1);
		arr.addElement(4);
		arr.addElement(155);
		arr.addElement(14);
		arr.addElement(15);
//		arr.addElement(100);
		std::cout << arr.getElement(1) << std::endl;
//		std::cout << arr.getElement(12) << std::endl;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}