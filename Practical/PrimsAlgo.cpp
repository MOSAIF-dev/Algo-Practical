#include<iostream>
#include<vector>
using namespace std;
//  Requirements Baba ki :  4 vector name 
// 
// [I] destination[] , Every nodes must be infinite except Source  
// [II] Previous[] , Tracking the final MST .
// [III] Color[] ,  for tracking the nodes which is already visited 
// [IV] EdgeCost[] , each nodes and vertex edge cost .

//  void function  :  For taking the input and initilizing the input 
#define MAX 100
class MST{
    public:

    
    int getIndex(vector<int>& NodeLabel, int source) {
        int n = NodeLabel.size();
        for (int i = 0; i < n; i++) {
            if (NodeLabel[i] == source)
                return i;
        }
        return -1;
    }

    const int INF = 1e9;

    void initializeGraph(int adjMatrix[MAX][MAX], vector<int>& NodeLabel, int source) {
        int size = NodeLabel.size();
    
        vector<int> Dest(size, INF);      // Distance vector initialized to "infinity"
        vector<int> Prev(size, -1);       // Previous node initialized to -1
        vector<string> Color(size, "W");  // Node color: "W" for unvisited
    
        Dest[source] = 0; // Distance to source is 0
    }


    //  Min Heap is used for tracking the minimum edge cost during the execution of Prim's algorithm

    void heapifyDown(vector<int>& NodeLable,int i, int n) {
        int smallest = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
    
        if (leftChild < n && NodeLable[leftChild] < NodeLable[smallest]) {
            smallest = leftChild;
        }
    
        if (rightChild < n && NodeLable[rightChild] < NodeLable[smallest]) {
            smallest = rightChild;
        }
    
        if (smallest != i) {
            swap(NodeLable[i], NodeLable[smallest]);
            heapifyDown(smallest, n);
        }
    }
    
    void buildMinHeap() {
        int currentSize = NodeLabel.size();

        for (int i = (currentSize / 2) - 1; i >= 0; i--) {
            heapifyDown(i, currentSize);
        }
    }
    //  KeyDecrease  Operation bcz of , when we update the node level then it is definitely reduce the vertex cost , so we need it .
    // void decreaseKey(vector<int>& NodeLabel, int index, int newValue) {
    //     NodeLabel[index] = newValue;
    //     heapifyDown(index, NodeLabel.size());
    //     if (newValue < NodeLabel[index]) {
    //         heapifyDown(index, NodeLabel.size());
    //     }


    //  Key dlt operation . 

    void KeyDlt(int First_Element_As_Min_Element,vector<int>&Color)
    {
        NodeLabel.erase(NodeLabel.begin() + First_Element_As_Min_Element);
        buildMinHeap();

    }

    //  Find the Adjacency Matrix 

    void findAdjacencyMatrix(vector<int>& NodeLabel, int adjMatrix[MAX][MAX], int vertex , int edges)
    {
        int FinalValidationSourceIndex = getIndex(NodeLabel, vertex);
    if (FinalValidationSourceIndex == -1 )
        return;
    }

    for(int i=0;i<vertex ; i++){
        for (int j = 0; j < edges; j++) {
        if(adjMatrix[i][j]==1)
        {
            
        }
        }
    }
    
    void Edge_Relaxation(){
     while(!buildMinHeap())
     {
        int u = KeyDlt(buildMinHeap());
        Color[u] = "b";

        //  Find Adjacency .

     }
    
};



int main()
{

    // Graph as a input 

   

    vector<int>NodeLabel ;
    vector<int>EdgeCost;
    MST M1;
    int vertex, edge;
    cout << "Enter your graph vertex: ";
    cin >> vertex;
    cout << "Enter your graph edge: ";
    cin >> edge;
    cout << "Enter edges (format: u v for undirected graph   and Edge Cost ):" << endl;

    int adjMatrix[MAX][MAX] = {0};

    for(int i=0;i<edge;i++){
        
        int u ,v,edge_cost;
        cin>>u>>v>>edge_cost;

        int U_index= M1. getIndex(NodeLabel, u);
        if (U_index == -1) {
            NodeLabel.push_back(u);
            U_index = NodeLabel.size() - 1;
        }
        int V_index =M1. getIndex(NodeLabel, v);
        if (V_index == -1) {
            NodeLabel.push_back(v);
            V_index = NodeLabel.size() - 1;
        }
        adjMatrix[U_index][V_index] = 1;
        adjMatrix[V_index][U_index] = 1;
    }
    cout << "Adjacency Matrix:" << endl;
    int n = NodeLabel.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    int source ;
    cout<<"Enter your Source Node lable :";
    cin>>source ;

M1.initializeGraph(adjMatrix,NodeLabel,source);

    return 0;
}