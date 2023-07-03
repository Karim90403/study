#include <iostream>

using namespace std;

class MyVector {
private:
    int* data;
    int size;
    int capacity;
public:
    MyVector() {
        size = 0;
        capacity = 10;
        data = new int[capacity];
    }
    ~MyVector() {
        delete[] data;
    }
    void push_back(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
    int at(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
    int getSize() {
        return size;
    }
};

int main() {
    MyVector v;
    for (int i = 2; i <= 20; i += 2) {
        v.push_back(i);
    }
    cout << "Vector contents: ";
    for (int i = 0; i < v.getSize(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    v.remove(1);
    v.remove(5);
    cout << "Vector contents after removal: ";
    for (int i = 0; i < v.getSize(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    return 0;
}
