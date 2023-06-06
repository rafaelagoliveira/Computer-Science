#include <iostream>

using namespace std;

class IntOverload {
  private:
    int integer;

  public:
    IntOverload() : integer(0) {}
    IntOverload(int integer) : integer(integer) {}
    
    int getInt() const {
        return integer;
    }

    IntOverload operator +(const IntOverload &value) const {
        return IntOverload(integer + value.integer);
    }

    IntOverload operator -(const IntOverload &value) const {
        return IntOverload(integer - value.integer);
    }

    IntOverload operator *(const IntOverload &value) const {
        return IntOverload(integer * value.integer);
    }

    IntOverload operator /(const IntOverload &value) const {
        return IntOverload(integer / value.integer);
    }

    IntOverload operator %(const IntOverload &value) const {
        return IntOverload(integer % value.integer);
    }

    IntOverload operator ++() {
        return IntOverload(++integer);
    }

    IntOverload operator ++(int) {
        return IntOverload(integer++);
    }

    IntOverload operator --() {
        return IntOverload(--integer);
    }

    IntOverload operator --(int) {
        return IntOverload(integer--);
    }

    bool operator ==(const IntOverload &value) {
        return integer == value.integer;
    }

    bool operator !=(const IntOverload &value) {
        return integer != value.integer;
    }

    bool operator <(const IntOverload &value) {
        return integer < value.integer;
    }

    bool operator >(const IntOverload &value) {
        return integer > value.integer;
    }

    bool operator <=(const IntOverload &value) {
        return integer <= value.integer;
    }

    bool operator >=(const IntOverload &value) {
        return integer >= value.integer;
    }

    bool operator &&(const IntOverload &value) {
        return integer && value.integer;
    }

    bool operator ||(const IntOverload &value) {
        return integer || value.integer;
    }

    bool operator !() {
        return !integer;
    }
};

int main() {
    IntOverload a(5), b(2), result, i = 0;

    result = a + b;
    cout << "Sum: " << result.getInt() << endl;
    
    result = a - b;
    cout << "Subtraction: " << result.getInt() << endl;
    
    result = a * b;
    cout << "Multiplication: " << result.getInt() << endl;
    
    result = a / b;
    cout << "Division: " << result.getInt() << endl;
    
    result = a % b;
    cout << "Module: " << result.getInt() << endl;
    
    ++i;
    cout << "Pre increment: " << i.getInt() << endl; 
    
    i++;
    cout << "Pos increment: " << i.getInt() << endl; 
    
    --i;
    cout << "Pre decrement: " << i.getInt() << endl; 
    
    i--;
    cout << "Pos increment: " << i.getInt() << endl; 

    if (a == b) {
        cout << "a == b" << endl;
    }

    if (a != b) {
        cout << "a != b" << endl;
    }
    
    if (a < b) {
        cout << "a < b" << endl;
    }
    
    if (a > b) {
        cout << "a > b" << endl;
    }
    
    if (a <= b) {
        cout << "a <= b" << endl;
    }
    
    if (a >= b) {
        cout << "a => b" << endl;
    }
    
    if (a == result && b == result) {
        cout << "a e b == result" << endl;
    }
    
    if (a == result || b == result) {
        cout << "a ou b == result" << endl;
    }
    
    if (!result) {
        cout << "!result" << endl;
    }


    return 0;
}