// Given two sorted arrays, the task is to merge them in a sorted manner.
// Examples: 

// Input: a[] = { 1, 3, 4, 5}, b[] = {2, 4, 6, 8} 
// Output: Array after merging = {1, 2, 3, 4, 4, 5, 6, 8}

// Input: a[] = { 5, 8, 9}, ab[] = {4, 7, 8} 
// Output: Array after merging = {4, 5, 7, 8, 8, 9} 

#include<iostream>
#include<algorithm>
using namespace std;

void merge(int a[], int n, int b[], int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < n)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < m)
    {
        cout << b[j] << " ";
        j++;
    }
}

int main()
{
    int j, n, x, m;
    cout << "Enter size of 1st array = ";
    cin >> n;
    cout << "Enter elements of 1st array = ";
    int a[n];
    for (j = 0; j < n; j++)
    cin >> a[j];
    cout << "Enter size of 2nd array = ";
    cin >> m;
    cout << "Enter elements of 2nd array = ";
    int b[m];
    for (j = 0; j < m; j++)
    cin >> b[j];

    cout << "\nArray after merging = " << "\n";
    merge(a, n, b, m);

    return 0;
}

