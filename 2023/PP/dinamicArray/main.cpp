#include <cstring>
#include <iostream>

using namespace std;

class DinamicSortedIntArray {
  private:
    int *ptr, size, numberElements;

    void swap(int &a, int &b) {
        int aux;
        aux = a;
        a = b;
        b = aux;
    }

  public:
    DinamicSortedIntArray() : size(16), numberElements(0) {
        ptr = new int[size];
    }

    explicit DinamicSortedIntArray(int size) : size(size), numberElements(0) {
        ptr = new int[size];
    }

    DinamicSortedIntArray(const DinamicSortedIntArray &other) {
        size = other.size;
        numberElements = other.numberElements;
        ptr = new int[size];
        memcpy(ptr, other.ptr, sizeof(int) * numberElements);
    }

    void resize(int newSize) {
        int *aux = new int[newSize];
        memcpy(aux, ptr, sizeof(int) * numberElements);
        delete[] ptr;
        ptr = aux;
        size = newSize;
    }

    void doubleCapacity() {
        int *newPtr = new int[size * 2];
        memcpy(newPtr, ptr, sizeof(int) * numberElements);
        delete[] ptr;
        ptr = newPtr;
        size = size * 2;
    }

    void shrinkToFit() {
        int newSize = size / 2;
        if (numberElements < newSize && newSize >= 16) {
            int *newPtr = new int[newSize];
            memcpy(newPtr, ptr, sizeof(int) * numberElements);
            delete[] ptr;
            ptr = newPtr;
            size = newSize;
        }
    }

    ~DinamicSortedIntArray() {
        delete[] ptr;
    }

    int getI(int index) const {
        return ptr[index];
    }

    int getSize() const {
        return size;
    }

    int getnumberElements() {
        return numberElements;
    }

    bool insert(int value) {
        int i;
        bool flag;

        if (numberElements == size)
            return false;

        ptr[numberElements] = value;

        i = numberElements++;
        flag = true;
        while (flag) {
            if (!(i > 0))
                flag = false;
            else if (ptr[i] < ptr[i - 1])
                swap(ptr[i], ptr[i - 1]);
            --i;
        }
        return true;
    }

    bool search(int value, int &index) const {
        index = 0;

        while (index < numberElements) {
            if (ptr[index] == value)
                return true;
            ++index;
        }
        return false;
    }

    bool remove(int value) {
        int index;

        if (!search(value, index))
            return false;

        for (; index < numberElements - 1; ++index)
            ptr[index] = ptr[index + 1];

        --numberElements;

        return true;
    }
};

int main() {

    DinamicSortedIntArray v1(5);

    v1.insert(9);
    v1.insert(6);
    v1.insert(11);
    v1.insert(7);
    v1.insert(1);
    v1.insert(90);

    for (int i = 0; i < v1.getnumberElements(); ++i)
        cout << v1.getI(i) << ' ';
    cout << endl;

    v1.remove(6);
    v1.remove(0);
    v1.remove(1);
    v1.remove(5);
    v1.remove(91);
    v1.remove(11);

    for (int i = 0; i < v1.getnumberElements(); ++i)
        cout << v1.getI(i) << ' ';
    cout << endl;

    return 0;
}
