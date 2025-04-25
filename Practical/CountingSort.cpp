#include<iostream>
#include<cmath>
using namespace std;
//  Counting Sort Algo

void CountingSortAlgo()
{
    int arr[] = {4, 2, 2, 6, 3,5};
   

   int max = arr[0];
   int size = sizeof(arr)/sizeof(arr[0]);
   for(int i=1;i<size;i++)
   {
    if(arr[i]>max)
    {
        max = arr[i];
    }
   }
   int c[max+1] = {0};

   for(int i=0;i<size;i++)
   {
    c[arr[i]]++;
   }

   for(int i = 1;i<=max;i++)
   {
    c[i]  = c[i] + c[i-1];
   }
   int output[size];
   for(int i = size-1; i >=0 ; i--)
   {
    output[c[arr[i]]-1] = arr[i];
    c[arr[i]]--;
   }
   for(int i=0;i<size;i++)
   {
    cout<<output[i]<<" ";
   }
  
}

int main()
{
    CountingSortAlgo();
    return 0;
}


//  Time complexity of this algo is 
//  O(n + k)  
// Space Complexity O(n) 