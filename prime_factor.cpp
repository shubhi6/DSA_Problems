#include<iostream>
#include<math.h>
using namespace std;

void primefactor(int n)
{
	 if(n<=1)
	 return ;
     while (n % 2 == 0 )
     {
     	cout<< 2 <<" ";
     	n=n/2;
	 }
	 while (n % 3 == 0 )
     {
     	cout<< 3 <<" ";
     	n=n/3;
	 }
	 for(int i=5;i*i<=n;i=i+6)
	   {
	   	while (n%i==0)
	   	   {
	   		cout<< i <<" " ;
	   		n=n/i;
		   }
		   
		   	while (n%(i+2)==0)
	   	   {
	   		cout<< (i+2) <<" ";
	   		n=n/(i+2);
		   }
	   }
	   if(n>3)
	   cout<< n <<" " ;  
 
}

int main()
{
    		int t;
    		cout<<"ENTER NUMBER OF TEST CASES = ";
    		cin>>t;
    		while(t--)
    		{
    			 int n;
	             cout<<"\n Enter a Number = ";
           	     cin>>n;
          	      primefactor(n);
			}
	return 0;
}
