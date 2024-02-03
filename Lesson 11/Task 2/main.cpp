#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class BigInteger {
public:
    // инициализация строкой std::string
    BigInteger(const std::string& value = "") {
        if (value != "") {
            auto it = value.crbegin();
            while (it != value.crend()) {
                if (*it < '0' || *it > '9')
                    throw std::invalid_argument("Попытка преобразовать некорректное значение: " + value);
                value_.push_back(*it - '0');
                ++it;
            }
        }
    }

    // инициализация копированием вектора std::vector<short>
    BigInteger(const std::vector<short>& value) {
        value_ = value;
    }

    // инициализация перемещением вектора std::vector<short>
    BigInteger(std::vector<short>&& value) {
        value_ = value;
    }

    ~BigInteger() = default;

    // конструктор копирования 
    BigInteger(const BigInteger& other) :
        BigInteger(other.value_) {};

    // конструктор перемещения 
    BigInteger(BigInteger&& other) noexcept :
        BigInteger(std::move(other.value_)) {};

    // оператор копирующего присваивания
    BigInteger& operator = (const BigInteger& other) {
        return *this = BigInteger(other);
    }

    // оператор перемещающего присваивания
    BigInteger& operator = (BigInteger&& other) noexcept {
        if (this != &other) 
            value_ = std::move(other.value_);
        return *this;
    }

    // оператор вывода значения BigInteger в поток (консоль)
    friend std::ostream& operator << (std::ostream& ostr, const BigInteger& v) {
        for (auto it = v.value_.crbegin(); it != v.value_.crend(); it++)
            ostr << static_cast<char>('0' + *it);
        return ostr;
    }

    // СЛОЖЕНИЕ //

    // оператор сложения BigInteger и числа
    BigInteger operator + (long long lg) const {
        if (this->value_.size() == 0) 
            throw std::logic_error("Переменная типа BigInteger не инициализирована!");
        BigInteger result;
        // складываем по-разрядно и сохраняем в вектор result от младшего разряда к старшему
        auto it = this->value_.cbegin();
        short toHighDigit = 0;
        while (it != this->value_.cend() || lg != 0 || toHighDigit != 0) {
            short digit = lg % 10 + toHighDigit;
            lg /= 10;
            if (it != this->value_.cend()) {
                digit += *it;
                it++;
            }
            result.value_.push_back(digit % 10);
            toHighDigit = digit / 10;
        }
        return result;
    }

    BigInteger operator += (long long lg) {
        if (this->value_.size() == 0)
            throw std::logic_error("Переменная типа BigInteger не инициализирована!");
        *this = *this + lg;
        return *this;
    }

    // оператор сложения числа и BigInteger
    friend BigInteger operator + (long long lg, const BigInteger& bi) {
        BigInteger result;
        result = bi + lg;
        return result;

    }
    
    // оператор сложения двух BigInteger
    BigInteger operator + (const BigInteger& other) const {
        if (this->value_.size() == 0 || other.value_.size() == 0)
            throw std::logic_error("Переменная типа BigInteger не инициализирована!");
        BigInteger result;
        // складываем по-разрядно и сохраняем в вектор result от младшего разряда к старшему
        auto it1 = this->value_.cbegin();
        auto it2 = other.value_.cbegin();
        short toHighDigit = 0;
        while (it1 != this->value_.cend() || it2 != other.value_.cend() || toHighDigit != 0) {
            short digit = toHighDigit;
            if (it1 != this->value_.cend()) {
                digit += *it1;
                it1++;
            }
            if (it2 != other.value_.cend()) {
                digit += *it2;
                it2++;
            }
            result.value_.push_back(digit % 10);
            toHighDigit = digit / 10;
        }
        return result;
    }

    BigInteger operator += (const BigInteger& other) {
        if (this->value_.size() == 0 || other.value_.size() == 0)
            throw std::logic_error("Переменная типа BigInteger не инициализирована!");
        *this = *this + other;
        return *this;
    }

    // УМНОЖЕНИЕ //

    // оператор умножения BigInteger на число
    BigInteger operator * (long long lg) const {
        if (this->value_.size() == 0)
            throw std::logic_error("Переменная типа BigInteger не инициализирована!");
        BigInteger result("0");
        for (long long i = 0; i < lg; i++) {
            result += *this;
        }
        return result;
    }

    // оператор умножения числа на BigInteger
    friend BigInteger operator * (long long lg, const BigInteger& other) {
        if (other.value_.size() == 0)
            throw std::logic_error("Переменная типа BigInteger не инициализирована!");
        BigInteger result = other * lg;
        return result;
    }

    // оператор умножения BigInteger на BigInteger
    BigInteger operator * (const BigInteger& other) const {
        if (this->value_.size() == 0 || other.value_.size() == 0)
            throw std::logic_error("Переменная типа BigInteger не инициализирована!");
        // меньшее число будем использовать как счетчик, большее число как слагаемое
        const BigInteger* count;
        const BigInteger* add;
        if (*this < other) {
            count = this;
            add = &other;
        }
        else {
            add = this;
            count = &other;
        }
        BigInteger result = "0";
        for (int i = 0; i < count->value_.size(); i++) {
            short inCount = count->value_.at(i);
            BigInteger inResult = "0";
            for (int j = 0; j < inCount; j++) {
                inResult += *add;
            }
            for (int j = 0; j < i; j++) {
                inResult = inResult * 10;
            }
            result += inResult;
        }
        return result;
    }

    // СРАВНЕНИЕ //
    
    // оператор "равно"
    friend bool operator == (const BigInteger& lh, const BigInteger& rh) {
        if (lh.value_.size() != rh.value_.size()) return false;
        bool result = true;
        for (int i = 0; i < lh.value_.size(); i++)
            if (lh.value_.at(i) != rh.value_.at(i)) {
                result = false;
                break;
            }
        return result;
    }

    // оператор "не равно"
    friend bool operator != (const BigInteger& lh, const BigInteger& rh) {
        if (!(lh == rh)) return true;
        else return false;
    }

    // оператор "меньше"
    friend bool operator < (const BigInteger& lh, const BigInteger& rh) {
        if (lh.value_.size() < rh.value_.size()) return true;
        if (lh.value_.size() > rh.value_.size()) return false;
        if (lh == rh) return false;
        bool result = true;
        for (int i = lh.value_.size() - 1; i > -1; i--) {
            if (lh.value_.at(i) > rh.value_.at(i)) {
                result = false;
                break;
            }
        }
        return result;
    }

    // оператор "больше"
    friend bool operator > (const BigInteger& lh, const BigInteger& rh) {
        if (lh < rh || lh == rh) return false;
        else return true;
    }

private:
    std::vector<short> value_; // по индексу [0] младший разряд числа, в конце вектора - старший
};


int main()
{   
    setlocale(LC_ALL, "");
    int a;
    int b;
    try {
        auto number1 = BigInteger("114575");
        auto number2 = BigInteger("78524");
        auto result = number1 + number2;
        std::cout << result << std::endl; // 193099

        number1 = BigInteger("111111111111111111111111");
        number2 = BigInteger("111111111111111111111");
        result = number1 * number2;
        std::cout << result << std::endl; // 12345679012345679012333320987654320987654321

    }
    catch (std::invalid_argument& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
    
    return 0;
}