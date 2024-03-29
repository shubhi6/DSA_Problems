// Calculating LCM of a number

// LCM stands for "Least Common Multiple." 
// It refers to the smallest positive integer that is divisible by two or more given integers without leaving a remainder.
// In simpler terms, the LCM is the smallest number that all the given numbers can divide into evenly.

// For example, the LCM of 4 and 6 is 12 because it is the smallest number that both 4 and 6 can divide into evenly.
// Similarly, the LCM of 3, 4, and 6 is also 12 because it is the smallest number that all three numbers can divide into evenly.
#include<iostream>
#include<math.h>
using namespace std;

int LCM(int n,int m)
{
	int res= max(m,n);
	while(true)
	{
		if(res%n==0 && res%m==0)
		return res;
        res++;
	}
	return res;
	
}


int main()
{
    int t;
    cout<<"Number of Test Cases = ";
    cin>>t;
    while(t--)
    {
    		int n,m;
	        cout<<"Enter Two Number = ";
           	cin>>n>>m;
          	cout<<"LCM of Numbers = " <<LCM(n,m)<<endl;
	}
	return 0;
}
