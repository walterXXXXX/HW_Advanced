#include <iostream>

template <class T>
class my_unique_ptr {
public:
	my_unique_ptr(T* ptr) :
		_ptr(ptr) {};

	my_unique_ptr(const my_unique_ptr&) = delete;

	T& operator = (const my_unique_ptr&) = delete;

	T& operator * () const {
		return *_ptr;
	}

	T* operator -> () {
		return _ptr;
	}

	T* release() {
		T* temp = _ptr;
		_ptr = nullptr;
		return temp;
	}

	~my_unique_ptr() {
		delete _ptr;
	}

private:
	T* _ptr;
};

class MyClass {
public:
	int _a;
	std::string _str;
	
	MyClass(int a, std::string str) :
		_a(a), _str(str) {};

	~MyClass(){
		std::cout << "Called destructor";
	}
};


int main() {

	my_unique_ptr<MyClass> ptr1(new MyClass(1, "Test1"));
	std::cout << (*ptr1)._a << "\t" << (*ptr1)._str << std::endl;

	ptr1->_a = 2; ptr1->_str = "Test2";
	std::cout << (*ptr1)._a << "\t" << (*ptr1)._str << std::endl;

	MyClass* releasePtr = ptr1.release();
	std::cout << (*releasePtr)._a << "\t" << (*releasePtr)._str << std::endl;

	delete releasePtr;

	return 0;
}
