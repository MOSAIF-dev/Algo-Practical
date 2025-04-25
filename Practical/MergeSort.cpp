#include<iostream>
using namespace std ;


 

class MS_Sorting{
    private:
    int *arr;
    int size;
    int *storing_Array;
    public:
    MS_Sorting(int Size)
    {
        size = Size;
        arr = new int[size];
        storing_Array = new int[size];
    }
    
        
       
        void MergeSort(int low,int high)
        {
            if(low<high){
                int mid = (low+high)/2;
                // Dividing the array into two sub parts .
                MergeSort(low,mid);
                MergeSort(mid+1,high);
//              Conquer the cost .
                Merge(low,mid,high);
            }

        }
        //  This Function is conquer the cost .
         void Merge(int low,int mid,int high)
        {
                int i = low;
                int j=mid+1;
                int k = 0;
                
                // Merging the array using while loop .

                while(i<=mid && j<=high)
                {
                    if(arr[i]<arr[j]){
                        storing_Array[k] = arr[i];
                        i++;
                        k++;
                    }
                    else{
                        storing_Array[k] = arr[j];
                        j++;
                        k++;
                    }
                }

                
                if(i>mid){
                    while(j<=high)
                    {
                        storing_Array[k] = arr[j];
                        j++;
                        k++;
                    }

                }
                else 
                {
                    while(i<=mid)
                    {
                        storing_Array[k] = arr[i];
                        i++;
                        k++;
                    }
                }
             
               for (int l = low; l <= high; l++) {
            arr[l] = storing_Array[l - low];  
        }
                
        
        }
        void Input(){
            for(int index=0;index<size;index++)
            {
                cout<<"Enter your Array value " << (index+1) << " : ";
                cin>>arr[index];
            }
        }
        void display(){
            for(int index=0;index<size;index++)
            {
                cout<<arr[index]<<" ";
                }
        }
};



int main(){
    int n  ;
    cout<<"Enter the size of the array: ";
    cin>>n;
    MS_Sorting MG(n);
    
    // Calling the input function to get the array values from the user.
    MG.Input();
    // Calling the function to merge sort the array.
    MG.MergeSort(0,n-1);
    MG.display();
    return 0;
}




// Logic kya h baba ?

// We have a array length n , we need to divide it between separate part to two disticnt subarray 
//  Then Making the function where we only divivde the array in two part and then call the function recursively till each array has exactly one Element
//  Then we merge the two array in sorted order
// Uisng Conquer Method to merge the array 

//                      Time complexity ={ 2T(n/2) + n, n>1
//                                          1           ,n<=1    }
//  T(n) = 2T(n/2) + n  using the master theorem where a = 2 and b = 2 so apply condition two where f(n) vs n^loga (b) = n^log2(2) = n^1
//  then T(n) = n^log a (b) .log a(b)  
//  T(n) = n^1 . log2(2)
//  T(n) =  θ(n.logn) // Time complexity of merge sort is θ(n.logn)

//  ****Space complexity = θ(n) // Because we only used one more additonal array of length (m1 + m2 = n ){Subarray Length } to store the result of the merge operation


//  Merge Sort Property 
//  Stable :- Yes
//  Inplace :- No

//                  THE END OF CODE 
//                  MO SAIF , 231227