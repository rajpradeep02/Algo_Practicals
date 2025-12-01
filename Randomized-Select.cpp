

#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);     

    for (int j = low; j <= high - 1; j++)
    {
       
        if (arr[j] <= pivot)
        {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int randomizedPartition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]); 
    return partition(arr, low, high);
}

int randomizedSelect(int arr[], int low, int high, int i)
{
    if (low == high)
        return arr[low];

    int partitionIndex = randomizedPartition(arr, low, high);
    int k = partitionIndex - low + 1; 

    if (i == k)
        return arr[partitionIndex];
    else if (i < k) 
        return randomizedSelect(arr, low, partitionIndex - 1, i);
    else 
        return randomizedSelect(arr, partitionIndex + 1, high, i - k);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 3; 
    cout << "The " << i << "th smallest element is " << randomizedSelect(arr, 0, n - 1, i) << endl;
    return 0;
}
