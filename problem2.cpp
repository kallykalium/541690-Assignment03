/* * Compilation command:
 * g++ -std=c++17 -Wall -Wextra -g -fsanitize=address problem2.cpp -o problem2
 */

#include <iostream>

using namespace std;

struct DynArray {
    int* data;     // pointer to heap-allocated buffer
    int size;      // number of elements in use
    int capacity;  // total allocated slots
};

// 1. O(1) - Initializing fixed values and a small initial buffer
void initArray(DynArray& a) {
    a.capacity = 2;
    a.size = 0;
    a.data = new int[a.capacity];
}

// 2. O(1) - Deallocating the buffer and resetting pointers
void freeArray(DynArray& a) {
    delete[] a.data;
    a.data = nullptr;
    a.size = 0;
    a.capacity = 0;
}

// 3. O(n) amortized - O(1) mostly, but O(n) when capacity doubles and copies data
void pushBack(DynArray& a, int value) {
    if (a.size == a.capacity) {
        int newCapacity = a.capacity * 2;
        int* newData = new int[newCapacity];
        
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        
        delete[] a.data;
        a.data = newData;
        a.capacity = newCapacity;
    }
    a.data[a.size] = value;
    a.size++;
}

// 4. O(n) - Linear time because elements must be shifted to the right
void insertAt(DynArray& a, int index, int value) {
    if (index < 0 || index > a.size) return;

    if (a.size == a.capacity) {
        int newCapacity = a.capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        delete[] a.data;
        a.data = newData;
        a.capacity = newCapacity;
    }

    // Shift elements to the right starting from the end
    for (int i = a.size; i > index; i--) {
        a.data[i] = a.data[i - 1];
    }

    a.data[index] = value;
    a.size++;
}

// 5. O(n) - Linear time because elements must be shifted to the left
void removeAt(DynArray& a, int index) {
    if (index < 0 || index >= a.size) return;

    // Shift elements to the left to fill the gap
    for (int i = index; i < a.size - 1; i++) {
        a.data[i] = a.data[i + 1];
    }
    a.size--;
}

// 6. O(1) - Direct access via pointer arithmetic/index
int getAt(const DynArray& a, int index) {
    return a.data[index];
}

// 7. O(1) - Direct assignment at a memory location
void setAt(DynArray& a, int index, int value) {
    a.data[index] = value;
}

// 8. O(n) - Linear time to visit and print each element
void printDynArr(const DynArray& a) {
    cout << "[";
    for (int i = 0; i < a.size; i++) {
        cout << a.data[i] << (i == a.size - 1 ? "" : ", ");
    }
    cout << "] (size=" << a.size << ", cap=" << a.capacity << ")" << endl;
}

int main() {
    DynArray arr;
    initArray(arr);

    // 1. pushBack until a resize is triggered (from cap 2 to 4, then 4 to 8)
    for (int i = 1; i <= 5; i++) pushBack(arr, i * 10);
    printDynArr(arr); // [10, 20, 30, 40, 50] (size=5, cap=8)

    // 2. insertAt index 2
    insertAt(arr, 2, 25);
    printDynArr(arr); // [10, 20, 25, 30, 40, 50] (size=6, cap=8)

    // 3. removeAt index 0
    removeAt(arr, 0);
    printDynArr(arr); // [20, 25, 30, 40, 50] (size=5, cap=8)

    // 4. getAt / setAt
    cout << "Element at index 2: " << getAt(arr, 2) << "\n"; // 30
    setAt(arr, 2, 99);
    printDynArr(arr); // [20, 25, 99, 40, 50] (size=5, cap=8)

    freeArray(arr);
    return 0;
}