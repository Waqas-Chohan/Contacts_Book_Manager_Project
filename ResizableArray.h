#pragma once
#include<string>
#include <stdexcept>

using namespace std;

template<typename T>
class ResizableArray {
private:
    T* array;
    int capacity;
    int size;

public:
    ResizableArray();
    ResizableArray(int initialCapacity);
    ~ResizableArray();
    T& GetItem(int index) const;
    void SetItem(int index, const T& value);
    void AddItem(const T& item);
    void RemoveItem(int index);
    int GetSize() const;
    T* GetArray() const;

private:
    void Resize(int newCapacity);
};

template<typename T>
ResizableArray<T>::ResizableArray() : capacity(10), size(0) {
    array = new T[capacity];
}

template<typename T>
ResizableArray<T>::ResizableArray(int initialCapacity) : capacity(initialCapacity), size(0) {
    array = new T[capacity];
}

template<typename T>
ResizableArray<T>::~ResizableArray() {
    delete[] array;
}

template<typename T>
T& ResizableArray<T>::GetItem(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return array[index];
}
template<typename T>
void ResizableArray<T>::SetItem(int index, const T& value) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    array[index] = value;
}

template<typename T>
void ResizableArray<T>::AddItem(const T& item) {
    if (size == capacity) {
        Resize(capacity * 2); // Double capacity if array is full
    }
    array[size++] = item;
}

template<typename T>
void ResizableArray<T>::RemoveItem(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }

    // Shift elements to  left
    for (int i = index; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }
    size--;

    // Shrink array if necessary
    if (size < capacity / 4) {
        Resize(capacity / 2); // Half capacity if size is quarter of capacity
    }
}

template<typename T>
int ResizableArray<T>::GetSize() const {
    return size;
}

template<typename T>
T* ResizableArray<T>::GetArray() const {
    return array;
}

template<typename T>
void ResizableArray<T>::Resize(int newCapacity) {
    T* newArray = new T[newCapacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;

    // Adjust size if new capacity is less than the current size
    if (newCapacity < size) {
        size = newCapacity;
    }
}