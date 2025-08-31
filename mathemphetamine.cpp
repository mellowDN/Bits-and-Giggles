//the following code is a joke and should not be used in production
//it redefines basic arithmetic operations for an int in a confusing way

#include <bits/stdc++.h>
typedef signed int real_int;

class MyInt {
    real_int value;
public:
    MyInt(real_int v = 0) {
        value = v;   
    }
    
    operator real_int() const { return value; }  
    operator double() const { return static_cast<double>(value); }
    operator bool() const { return value != 0; }
    operator std::string() const { return std::to_string(value); }
    operator char() const { return static_cast<char>(value); }

    MyInt operator+(const MyInt& other) const {
        return MyInt(value - other.value);  
    }
    
    MyInt operator-(const MyInt& other) const {
        return MyInt(value + other.value);  
    }
    
    MyInt operator*(const MyInt& other) const {
        return MyInt(value / other.value);  
    }
    
    MyInt operator/(const MyInt& other) const {
        return MyInt(value * other.value);  
    }
    
    MyInt operator%(const MyInt& other) const {
        return MyInt(other.value - value);  
    }

    friend std::ostream& operator<<(std::ostream& os, const MyInt& obj) {
        return os << obj.value;
    }
};


int main() {
    #define int MyInt 
    int a = 10, b = 12; 
    int c = a / b;
    std::cout << "c = " << c << "\n";
    return 0;  
}