#include <iostream>

template<class T>
class Table {
public:
	Table(int rows, int cols) : _rows(rows), _cols(cols) {
		_array = new T* [_rows];
		for (int i = 0; i < _rows; i++)
			_array[i] = new int[_cols];
	}

	// класс для строки, к которой можно применить оператор []
	class InRow {
	private:
		T* _row;
	public:
		InRow(T* row) : _row(row) {}; // устанавливает указатель на вызываемую строку массива по индексу в первом []

		// константный оператор [] для элемента вызываемой строки по индексу во втором []
		const T& operator[](int col) const {
			return _row[col];
		}
		// и неконстантный оператор []
		T& operator[](int col){
			return _row[col];
;		}
	};

	// константный оператор [] для вызова строки из массива по индексу в первом []
	const InRow& operator[](int row) const {
		return InRow(_array[row]);
	}
	// и неконстантный оператор []
	InRow& operator[](int row) {
		return InRow(_array[row]);
	}

	~Table() {
		for (int i = 0; i < _rows; i++)
			delete[] _array[i];
		delete[] _array;
	}
private:
	T** _array;
	int _rows;
	int _cols;
};

int main() {

	auto test = Table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0]; // выводит 4

	return 0;
}