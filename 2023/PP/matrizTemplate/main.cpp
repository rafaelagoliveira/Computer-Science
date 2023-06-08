#include <iostream>

template <class Type>
class Matrix {
  private:
    Type **bigArray;
    unsigned n;

  public:
    Matrix() : n(3), bigArray(new T*[n]) {
        for (unsigned i = 0; i < n; ++i) {
            bigArray[i] = new T[n];
        }
    }

    explicit Matrix(unsigned n) : n(n), bigArray(new T*[n]) {
        for (unsigned i = 0; i < n; ++i) {
            bigArray[i] = new T[n];
        }
    }

    ~Matrix() {
        for (unsigned i = 0; i < n; ++i) {
            delete[] bigArray[i];
        }
        delete[] bigArray;
    }

    Type getElement(unsigned i, unsigned j) const {
        return bigArray[i][j];
    }

    void setElement(unsigned i, unsigned j, Type value) {
        bigArray[i][j] = value;
    }

};

int main() {
    unsigned i, j, n = 3;

    Matrix<int> m(n);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            m.setElement(i, j, i * n + j);
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            std::cout << m.getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}