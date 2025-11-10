// Write a program to find the ith smallest element of an array using Randomized Select.

#include <iostream>
#include <cstdlib>
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

int randomizedPartition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]); // Move pivot to end
    return partition(arr, low, high);
}

int randomizedSelect(int arr[], int low, int high, int i)
{
    if (low == high) // If the list contains only one element
        return arr[low];

    int partitionIndex = randomizedPartition(arr, low, high);
    int k = partitionIndex - low + 1; // Number of elements in the left partition including pivot

    if (i == k) // The pivot value is the answer
        return arr[partitionIndex];
    else if (i < k) // Go to the left partition
        return randomizedSelect(arr, low, partitionIndex - 1, i);
    else // Go to the right partition
        return randomizedSelect(arr, partitionIndex + 1, high, i - k);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 3; // Find the 3rd smallest element
    cout << "The " << i << "th smallest element is " << randomizedSelect(arr, 0, n - 1, i) << endl;
    return 0;
}
