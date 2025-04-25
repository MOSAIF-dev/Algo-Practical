#include <iostream>
#include <vector>
#include <queue>

//  Baba logic kya h ?
// Note:-  Baba ka number 1 se 9 tak hota hai.

// Sol:- Easy h bhai , [i] -sbse phle total number of edges and nodes(Vertex) ko input m le lo .
// [ii] - graph ko unweighted graph m convert karo .  Uska koi formula h ? Ha ji formula hi to h.
// [iii] -  Formula for undirected graph    -----     adjMatrix[U_index][V_index] = 1;  adjMatrix[V_index][U_index] = 1;  Aur koi Option ?
// [iv] -  Formula for directed graph       -----    adjMatrix[U_index][V_index] =1;
//  Duplicate value ko remove karna h . Jo ki line 70 se lekr 85 tk h 
// Ab actual logic aayega bhai .
//  BFS Traversal Kya h ? 
// Answer:-  B  BFS traversal ek graph ko level wise traverse karta h .Source value kkoi si b vertex ho skti h . to source validation b jaruri h
//  BFS traversal ke 2 main steps h .
// [I] Create a vector where initilize all the value as 0 
//  [II] Create a queue and push the source value in it . 
//  [III]  while loop chalao jab tak queue empty nahi ho jaye .
//  [IV]  Dequeue the value and print it for showing the answer and make the visited vertex as 1 . 
//  [V]  Now add all the adjacent vertex of the dequeued vertex in the queue
//  [VI]  Repeat the step [III] to [V] till the queue empty.



using namespace std;

#define MAX 100  

int  getIndex(vector<int>&NodeLable,int source){
    int i = 0;
    int n = NodeLable.size();
    for(i = 0; i <n; i++){
        if(NodeLable[i] == source) {
            return i;
        }
    }
    return -1;
}

void TraverseBFS(int adjMatrix[MAX][MAX], vector<int>& NodeLable, int nodes, int source) {
    vector<int> visit(nodes, 0);  
    queue<int> Queue;
    int n = NodeLable.size();
    
    int FinalSourceValidation = getIndex(NodeLable, source);
    if (FinalSourceValidation == -1) {
        cout << "Source Node is not present in the graph" << endl;
        return;
    }

    cout << "BFS Traversal: ";
    visit[FinalSourceValidation] = 1;
    Queue.push(FinalSourceValidation);

    while (!Queue.empty()) {
        int v = Queue.front();
        Queue.pop();
        
        cout << NodeLable[v] << " "; 

        for (int i = 0; i < n; i++) {  
            if (adjMatrix[v][i] == 1 && visit[i] == 0) {
                visit[i] = 1;
                Queue.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<int> NodeLable;

    int adjMatrix[MAX][MAX] = {0};  

    cout << "Enter edges (format: u v for undirected graph):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        int U_index = getIndex(NodeLable, u);
        if (U_index == -1) {
            NodeLable.push_back(u);
            U_index = NodeLable.size() - 1;
        }
        int V_index = getIndex(NodeLable, v);
        if (V_index == -1) {
            NodeLable.push_back(v);
            V_index = NodeLable.size() - 1;
        }
        adjMatrix[U_index][V_index] = 1;
        adjMatrix[V_index][U_index] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    int n = NodeLable.size();
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    int source;
    cout << "Enter your source node: ";
    cin >> source;

    TraverseBFS(adjMatrix, NodeLable, nodes, source);

    return 0;
}

//  Time complexity of this code ?
//  logic for T.C. is as follows:
// If we make the adjacency Matrix then total number of operations will be O(n^2) where n is the number of nodes in the graph.
//  Then we are doing BFS traversal which will take O(n + e) time where n is the vertex and this is under Adjacency list Matrix 

//  So the overall time complexity will be O(n^2) OR  O(n + e)

// Space complexity of this code ?
//  To track the visited nodes we are using a vector of size n which will take O(n) space
//  To keep the source value in the queue we are using a queue which will take atmost  O(n) space.
//  So the overall space complexity will be O(n) .


//  Final TC = O(n^2) OR  O(n + e)
//  Final SC = O(n) 
