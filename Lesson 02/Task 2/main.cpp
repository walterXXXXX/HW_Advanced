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

	int getSize() { return size; }

	int getLocalSize() { return localSize; }

	SmartArray& operator = (SmartArray& copyArr) {
		delete[] arr;
		size = copyArr.getSize();
		localSize = size;
		arr = new int[size];
		for (int i = 0; i < size; i++) arr[i] = copyArr.getElement(i);
		return *this;
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

	SmartArray arr(5);
	arr.addElement(1);
	arr.addElement(4);
	arr.addElement(155);

	SmartArray new_array(2);
	new_array.addElement(44);
	new_array.addElement(34);

	arr = new_array;

	std::cout << "arr: " << std::endl;
	for (int i = 0; i < arr.getLocalSize(); i++) std::cout << arr.getElement(i) << std::endl;
	std::cout << std::endl << "new_array: " << std::endl;
	for (int i = 0; i < new_array.getLocalSize(); i++) std::cout << new_array.getElement(i) << std::endl;
	

	return 0;
}