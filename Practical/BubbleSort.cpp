#include<iostream>
#include<vector>
using namespace std;

// int inversionCount(vector<int>&arr)
// {
//     int inversion = 0;
//     int n = arr.size();
//     for(int i=0;i<n;i++)
//     {
//         for(int j = i+1 ; j<n;j++)
//         {
//             if(arr[i] > arr[j])
//             inversion++;
//         }
//     }
//     cout << "\nTotal Number of Inversions: " << inversion;
// }
void BubbleSort(vector<int> arr)
{
    int n  = arr.size();
    int pass = 0;
    int com = 0;
    int inversion = 0;
    int swaps = 0;
   
   
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            com++;

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;  
                inversion++;
                flag = true;
            }
           
        }
       
      
        if (flag) 
            pass++;
        else 
            break;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nTotal Number of Comparisons: " << com;
    cout << "\nTotal Number of Passes: " << pass;
    cout << "\nTotal Number of Inversions: " << inversion;

    cout << "\nTotal Number of Swaps: " << swaps << endl;
}

int main()
{
    vector<int> arr = {60, 80, 30, 40, 20,90,30, 80, 50, 40};
    BubbleSort(arr);
    // inversionCount(arr);
   
    return 0;
}
