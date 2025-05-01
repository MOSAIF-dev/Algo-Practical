    #include<iostream>
    #include<vector>
    #include<string>
    using namespace std;
    //  Require Mention: 0-1 Knapsack Problem 
    //  Vector for  [I] Prfoit vector [W] Weight vector [N] Number of items
    //  Maximum capacity of the Knapsack variable max_weight

    class knapsack_0_1{
        public:
            vector<int>profit;
            vector<int>weight;
            vector<string>Objects;
            
        void Initialization(int size)
        {
            profit = vector<int>(size);
            weight = vector<int>(size);
            Objects = vector<string>(size);
        }

        void Input_Object_profit_Weight(int size)
        {
            cout<<"Enter your Objects Along with its Profit and Weight "<<endl;
        for(int i=0;i<size;i++)
       {
            cout<<"Enter the name of the object: ";
            cin>>Objects[i];
            cout<<"Enter the profit of "<<Objects[i]<<" : ";
            cin>>profit[i];
            cout<<"Enter the weight of "<<Objects[i]<<" : ";
            cin>>weight[i];
            cout<<endl;
        }
        cout<<endl;
        cout<<"The Objects are: "<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<Objects[i]<<"  Profit: "<<profit[i]<<"  Weight: "<<weight[i]<<endl;
            cout<<endl;
       }
        }

        int Knapsack_problem(int size,int Knapsack_Capacity)
        {
            //  Reccurssive algo for  0-1 knapsack problem

            if(size==0 || Knapsack_Capacity==0)
            {
                // cout<<"Either Knapsack_Capacity is Empty  or 0 element"<<endl;
                return 0;
            }
            
            if(weight[size-1]>Knapsack_Capacity)
            {
                return Knapsack_problem(size-1,Knapsack_Capacity);
            }
            else
            {
                return max(profit[size-1]+Knapsack_problem(size-1,Knapsack_Capacity-weight[size-1]),Knapsack_problem(size-1,Knapsack_Capacity));
            }
        }

        //  Dynamic Programming algo for 0-1 knapsack problem
        int Knapsack_problem_Dynamic_Programming(int size, int Knapsack_Capacity)
        {
            vector<vector<int>>Stored_Profit(size+1,vector<int>(Knapsack_Capacity+1,0));

            for(int i=1;i<=size;i++)
            {
                for(int j=0;j<=Knapsack_Capacity;j++)
                {
                    if(i==0 || j==0){
                        Stored_Profit[i][j]=0;
                    }
                    else if(weight[i-1]>j){
                        Stored_Profit[i][j] = Stored_Profit[i-1][j];
                    }
                    else{
                        Stored_Profit[i][j] = max(profit[i-1]+Stored_Profit[i-1][j-weight[i-1]],Stored_Profit[i-1][j]);
                    }
                }
            }
            cout<<"The Objects are: "<<endl;
            for(int i=0;i<size;i++)
            {
                cout<<Objects[i]<<"  Profit: "<<profit[i]<<"  Weight: "<<weight[i]<<endl;
                cout<<"\n";
           }
        
            return Stored_Profit[size][Knapsack_Capacity];
        }
    };


    int main()
    {
        knapsack_0_1 knapsack;
        int size;
        cout<<"Enter the number of items: ";
        cin>>size;
        int Knapsack_Capacity;
        cout<<"Enter the maximum capacity of the Knapsack: ";
        cin>>Knapsack_Capacity;
        knapsack.Initialization(size);
        knapsack.Input_Object_profit_Weight(size);
        cout<<"Enter Your Choice: "<<endl;
        cout<<"\n";
        cout<<"1. Recursive Knapsack Problem"<<endl;
        cout<<"\n";
        cout<<"2. Dynamic Programming Knapsack Problem"<<endl;
        cout<<"\n";
        int choice; 
        cout<<"Enter 0 for Recursive and 1 for Dynamic Programming: "<<endl;
        cin>>choice;
       if(choice==0){
        
        cout<<"The maximum profit that can be obtained is: "<<knapsack.Knapsack_problem(size,Knapsack_Capacity)<<endl;
       }
       else if(choice==1){
        cout<<"The maximum profit that can be obtained is: "<<knapsack.Knapsack_problem_Dynamic_Programming(size,Knapsack_Capacity)<<endl;
       }
       else{
        cout<<"Invalid choice"<<endl;

       }
        
        cout<<endl;
        return 0;
    }


    //  Time Complexity: O(n*W) where n is the number of items and W is the maximum capacity of the knapsack.