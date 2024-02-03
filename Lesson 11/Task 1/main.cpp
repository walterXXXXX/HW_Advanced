#include <iostream>
#include <vector>


template<class T>
void moveVectors(std::vector<T>& one, std::vector<T>& two) {
    two = std::move(one);
}

template<class T>
void print(const std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << "\t";
    std::cout << std::endl;
}

int main() {

    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    
    std::cout << "Before moving\n";
    std::cout << "Vector one:\t";
    print(one);
    std::cout << "Vector two:\t";
    print(two);
    
    moveVectors(one, two);

    std::cout << "\nAfter moving\n";
    std::cout << "Vector one:\t";
    print(one);
    std::cout << "Vector two:\t";
    print(two);

    return 0;
}