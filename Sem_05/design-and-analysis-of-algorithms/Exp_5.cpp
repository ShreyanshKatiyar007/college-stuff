/*Sort a given set of elements using the Quick sort method and determine
the time required to sort the elements. Repeat the experiment for different
values of n, the number of elements in the list to be sorted. The elements
can be read from a file or can be generated using the random number
generator.*/

#include <bits/stdc++.h>
#include <ctime>
using namespace std;

void swap(int arr[], int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
int partition(int arr[], int low, int high, int pivot)
{
    int i = low, j = low;
    while (i <= high)
    {
        if (arr[i] > pivot)
            i++;
        else
            swap(arr, i++, j++);
    }
    return j - 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(arr, low, high, arr[high]);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    srand(time(0));
    cout << "Generated array: ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
        cout << arr[i] << "\t";
    }
    cout << endl;
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << "\nTime: " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
