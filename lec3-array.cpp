#include <iostream>

using namespace std;


template <typename T> 

void insertionSort(T *const array, int const n) 
{
    for (int k = 1; k < n; ++k) 
    {
        for (int j = k; j > 0; --j) 
        {
            if (array[j - 1] > array[j]) 
            {
                swap(array[j-1], array[j]);
            } 
            else 
            {
                break;
            }
        }
    }
};

template <typename T> 

void displayArray(T *const array, int size) 
{
    for (T *p = array; p < array + size; ++p) 
    {
        cout << "Element: " << *p << endl;
    }
}

int main() {
    int arr1[] = {1,5,2,8};
    int size = sizeof(arr1) / sizeof(int);

    displayArray(arr1, size);
    insertionSort(arr1, size);
    displayArray(arr1, size);

    return 0;
}