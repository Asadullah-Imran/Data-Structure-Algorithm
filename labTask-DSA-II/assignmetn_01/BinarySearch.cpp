#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (key == arr[mid])
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        return binarySearch(arr, key, mid + 1, high);
    }
    else
    {
        return binarySearch(arr, key, low, mid - 1);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array (sorted): ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter a number for the key value: ";
    cin >> key;

    int index = binarySearch(arr, key, 0, size - 1);

    if (index != -1)
    {
        cout << "Found the value at index: " << index << endl;
    }
    else
    {
        cout << "Not found!" << endl;
    }

    return 0;
}