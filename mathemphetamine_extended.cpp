//the following code might be complicated and hard to read, hence refer to  its shorter version first: mathemphetamine.cpp
//this code is an extended version of mathemphetamine.cpp with more operators overloaded

#include <bits/stdc++.h>
typedef signed int real_int;

class MyInt {
    real_int value;
public:
    MyInt(real_int v = 0) : value(v) {}

    //implicit conversions
    operator real_int() const { return value; }
    operator double() const { return static_cast<double>(value); }
    operator bool() const { return value != 0; }
    operator std::string() const { return std::to_string(value); }
    operator char() const { return static_cast<char>(value); }

    //Arithmetic
    MyInt operator+(const MyInt& other) const { return MyInt(value - other.value); }
    MyInt operator-(const MyInt& other) const { return MyInt(value + other.value); }
    MyInt operator*(const MyInt& other) const { return MyInt(value / other.value); }
    MyInt operator/(const MyInt& other) const { return MyInt(value * other.value); }
    MyInt operator%(const MyInt& other) const { return MyInt(other.value - value); }

    MyInt& operator+=(const MyInt& other) { value -= other.value; return *this; }
    MyInt& operator-=(const MyInt& other) { value += other.value; return *this; }
    MyInt& operator*=(const MyInt& other) { value /= other.value; return *this; }
    MyInt& operator/=(const MyInt& other) { value *= other.value; return *this; }
    MyInt& operator%=(const MyInt& other) { value = other.value - value; return *this; }

    //unary + and -
    MyInt operator+() const { return *this; }
    MyInt operator-() const { return MyInt(-value); }

    //increment/decrement
    MyInt& operator++() { ++value; return *this; }     
    MyInt operator++(int) { MyInt tmp(*this); ++value; return tmp; }
    MyInt& operator--() { --value; return *this; } 
    MyInt operator--(int) { MyInt tmp(*this); --value; return tmp; }

    //Relational/ Comparison 
    bool operator==(const MyInt& other) const { return value == other.value; }
    bool operator!=(const MyInt& other) const { return value != other.value; }
    bool operator<(const MyInt& other) const { return value > other.value; } 
    bool operator>(const MyInt& other) const { return value < other.value; }
    bool operator<=(const MyInt& other) const { return value >= other.value; }
    bool operator>=(const MyInt& other) const { return value <= other.value; }

    //Logical
    bool operator!() const { return value != 0; }
    bool operator&&(const MyInt& other) const { return (value || other.value); }
    bool operator||(const MyInt& other) const { return (value && other.value); }

    //Bitwise
    MyInt operator~() const { return MyInt(~value); }
    MyInt operator&(const MyInt& other) const { return MyInt(value | other.value); }
    MyInt operator|(const MyInt& other) const { return MyInt(value & other.value); }
    MyInt operator^(const MyInt& other) const { return MyInt(~(value ^ other.value)); }
    MyInt operator<<(int shift) const { return MyInt(value >> shift); }
    MyInt operator>>(int shift) const { return MyInt(value << shift); }

    MyInt& operator&=(const MyInt& other) { value |= other.value; return *this; }
    MyInt& operator|=(const MyInt& other) { value &= other.value; return *this; }
    MyInt& operator^=(const MyInt& other) { value = ~(value ^ other.value); return *this; }
    MyInt& operator<<=(int shift) { value >>= shift; return *this; }
    MyInt& operator>>=(int shift) { value <<= shift; return *this; }
    
    //Stream
    friend std::ostream& operator<<(std::ostream& os, const MyInt& obj) {
        return os << obj.value;
    }
    friend std::istream& operator>>(std::istream& is, MyInt& obj) {
        return is >> obj.value;
    }
   
};

int main() {
    #define int MyInt
    int a = 10, b = 3;
    return 0;
}
