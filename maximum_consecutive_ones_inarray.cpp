//Through this code we can find the count of the maximum number of consecutive 1's present in the array.

//Examples : 

//Input: arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1}
//Output: 4

//Input: arr[] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}
//Output: 1

#include<iostream>
#include<cmath>
using namespace std;

int maxconsecutiveone(bool arr[],int n)
{
	int res=0,curr=0,i;
    for(int i=0;i<n;i++)
    {
    	if(arr[i]==0)
    	curr=0;
    	else
    	{
    		curr++;
    		res=max(res,curr);
		}
	}
    
	return res;
	
}

int main()
{
	int j,n;
	cout<<"Enter size of array = ";
	cin>>n;
	bool arr[n];
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Maximum consecutive ones in an array are = ";
	cout<<maxconsecutiveone(arr,n);
}
