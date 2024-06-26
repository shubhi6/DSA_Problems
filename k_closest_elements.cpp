// .....................K Closest Elements.........................

// Given a sorted array arr[] and a value X, find the k closest elements to X in arr[]. 

// Examples: 

// Input: K = 4, X = 35
//        arr[] = {12, 16, 22, 30, 35, 39, 42, 
//                45, 48, 50, 53, 55, 56}
// Output: 30 39 42 45


#include<stdio.h> 

int findCrossOver(int arr[], int low, int high, int x) 
{ 
    if (arr[high] <= x) 
        return high; 
    if (arr[low] > x) 
        return low; 

    int mid = (low + high)/2; 

    if (arr[mid] <= x && arr[mid+1] > x) 
        return mid; 

    if(arr[mid] < x) 
        return findCrossOver(arr, mid+1, high, x); 

    return findCrossOver(arr, low, mid - 1, x); 
} 

void printKclosest(int arr[], int x, int k, int n) 
{ 
    int l = findCrossOver(arr, 0, n-1, x); 
    int r = l+1; 
    int count = 0; 

    if (arr[l] == x) l--; 

    while (l >= 0 && r < n && count < k) 
    { 
        if (x - arr[l] < arr[r] - x) 
            printf("%d ", arr[l--]); 
        else
            printf("%d ", arr[r++]); 
        count++; 
    } 

    while (count < k && l >= 0) 
        printf("%d ", arr[l--]), count++; 

    while (count < k && r < n) 
        printf("%d ", arr[r++]), count++; 
} 

int main() 
{ 
    int arr[] ={12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 35, k = 4; 
    printKclosest(arr, x, 4, n); 
    return 0 ;
}

// Output: 
// 39 30 42 45

