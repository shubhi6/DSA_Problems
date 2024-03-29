//...................First Circular Tour................

// Examples:

// Input: arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}}. 
// Output: 1
// Explanation: If started from 1st index then a circular tour can be covered.

// Input: arr[] {{6, 4}, {3, 6}, {7, 3}}
// Output: 2

//..........NAIVE APPROACH..........

#include <bits/stdc++.h>
using namespace std;

class petrolPump {
public:
    int petrol;
    int distance;
};

int printTour(petrolPump arr[], int n) {
    int start = 0;
    int end = 1;
    int curr_petrol = arr[start].petrol - arr[start].distance;
    while (end != start || curr_petrol < 0) {
        while (curr_petrol < 0 && start != end) {
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;
            if (start == 0)
                return -1;
        }
        curr_petrol += arr[end].petrol - arr[end].distance;
        end = (end + 1) % n;
    }
    return start;
}

int main() {
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);
    (start == -1) ? cout << "No solution" : cout << "Start = " << start;
    return 0;
}

// Output
// Start = 2

//............EFFICIENT WAY..........

#include <bits/stdc++.h>
using namespace std;

class petrolPump {
public:
    int petrol;
    int distance;
};

int printTour(petrolPump p[], int n) {
    int start = 0, deficit = 0;
    int capacity = 0;
    for (int i = 0; i < n; i++) {
        capacity += p[i].petrol - p[i].distance;
        if (capacity < 0) {
            start = i + 1;
            deficit += capacity;
            capacity = 0;
        }
    }
    return (capacity + deficit >= 0) ? start : -1;
}

int main() {
    petrolPump arr[] = { { 6, 4 }, { 3, 6 }, { 7, 3 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);
    (start == -1) ? cout << "No solution" : cout << "Start = " << start;
    return 0;
}


// Output
// Start = 2
