#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix {
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};

    std::unique_ptr<tridiagonal_matrix> clone() {
        return std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
    }

    void print() {
        for (int i = 0; i < m_middle.size(); i++) {
            for (int j = 0; j < m_middle.size(); j++) {
                if (i == j) {
                    std::cout << m_middle[j] << "\t";
                    continue;
                }           
                if (j == i + 1) {
                    std::cout << m_upper[i] << "\t";
                    continue;
                }
                if (j == i - 1) {
                    std::cout << m_down[j] << "\t";
                    continue;
                }
                std::cout << "0" << "\t";
            }
            std::cout << std::endl;
        }
    }

    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

};

int main() {
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();
    
    std::cout << "Base matrix: " << std::endl;
    matrix->print();

    std::cout << std::endl;
    std::cout << "Clone matrix: " << std::endl;

    matrix_clone->print();

    return 0;
}