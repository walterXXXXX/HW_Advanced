#include <iostream>
#include <stdexcept>

template<class T>
class MyVector {
public:
	MyVector() {
		_vector = new T[_capacity];
	}

	MyVector(std::initializer_list<T> init) : MyVector() {
		for (T i : init) push_back(i);
	}

	T at(int index) {
		if (index < 0 || index >= _size)
			throw std::out_of_range("Index out of range");
		return _vector[index];
	}

	void push_back(T value) {
		if (_size == _capacity) {
			_capacity *= 1.5;
			T* temp = new T[_capacity];
			for (int i = 0; i < _size; i++)
				temp[i] = _vector[i];
			delete[] _vector;
			_vector = temp;
		}
		_vector[_size++] = value;
	}

	void push_back(std::initializer_list<T> values) {
		for (T v : values) push_back(v);
	}

	int size() { return _size; }
	int capacity() { reutrn _capacity; }

	void print_vector() {
		for (int i = 0; i < _size; i++)
			std::cout << at(i) << " ";
		std::cout << std::endl;
		std::cout << "Size: " << _size << std::endl;
		std::cout << "Capacity: " << _capacity << std::endl << std::endl;
	}

	~MyVector() {
		delete[] _vector;
	}
private:
	int _size = 0;
	int _capacity = 10;
	T* _vector;
};

int main() {

	MyVector<int> vec = {5, 1, 23, 11, 23, 45, 0, -1, 1};
	vec.print_vector();

	std::cout << "Value by index [2]: " << vec.at(2) << std::endl << std::endl;

	vec.push_back({ 5, 13, 11 });
	vec.print_vector();

	std::cout << "Check exception: " << std::endl;

	try {
		std::cout << "Value by index [30]: ";
		std::cout << vec.at(30) << std::endl << std::endl;

	}
	catch (const std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
