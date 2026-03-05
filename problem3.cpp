#include <iostream>

using namespace std;

// 1. Linear Search: O(n)
int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// 2. Binary Search: O(log n)
int binarySearch(int* arr, int n, int target) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        // Menggunakan rumus midpoint yang diminta
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// 3. Generate Sorted Array: O(n)
int* generateSortedArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2; // Menghasilkan angka genap berurutan {0, 2, 4, ...}
    }
    return arr;
}

void testSearch(int n) {
    int* arr = generateSortedArray(n);
    int midIdx = n / 2;
    int targetExist = arr[midIdx]; // Nilai yang pasti ada
    int targetNotExist = -1;       // Nilai yang pasti tidak ada (karena array isinya >= 0)

    cout << "--- Testing Array Size n = " << n << " ---" << endl;
    
    // Test 1: Value Exists
    int resLin = linearSearch(arr, n, targetExist);
    int resBin = binarySearch(arr, n, targetExist);
    cout << "Target " << targetExist << " (Exist)  -> Linear: " << resLin << ", Binary: " << resBin;
    cout << (resLin == resBin ? " [AGREE]" : " [DISAGREE]") << endl;

    // Test 2: Value Does Not Exist
    resLin = linearSearch(arr, n, targetNotExist);
    resBin = binarySearch(arr, n, targetNotExist);
    cout << "Target " << targetNotExist << " (Not Exist) -> Linear: " << resLin << ", Binary: " << resBin;
    cout << (resLin == resBin ? " [AGREE]" : " [DISAGREE]") << endl << endl;

    delete[] arr; // Caller responsible for freeing
}

int main() {
    int sizes[] = {10, 100, 1000};
    for (int n : sizes) {
        testSearch(n);
    }
    return 0;
}