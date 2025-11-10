#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void randomizedQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Generate a random pivot index
        int pivotIndex = low + rand() % (high - low + 1);
        swap(arr[pivotIndex], arr[high]); // Move pivot to end

        int partitionIndex = partition(arr, low, high);
        randomizedQuickSort(arr, low, partitionIndex - 1);
        randomizedQuickSort(arr, partitionIndex + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 5, 8, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    randomizedQuickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}