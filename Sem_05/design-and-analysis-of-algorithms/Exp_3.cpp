// find frequency of elements in a given array in O(n) time complexity.

#include <bits/stdc++.h>
using namespace std;
void findcounts(int *arr, int n)
{
    int hash[n] = {0};
    int i = 0;
    while (i < n)
    {
        hash[arr[i] - 1]++;
        i++;
    }
    cout << "Below are counts of all elements" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << (i + 1) << " -> " << hash[i] << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findcounts(arr, n);
    return 0;
}
