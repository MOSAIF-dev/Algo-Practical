#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

// Get the index of a node in the NodeLabel vector
int getIndex(vector<int>& NodeLabel, int source) {
    int n = NodeLabel.size();
    for (int i = 0; i < n; i++) {
        if (NodeLabel[i] == source)
            return i;
    }
    return -1;
}

// DFS Traversal Function
void TraverseDFS(int adjMatrix[MAX][MAX], vector<int>& NodeLabel, int vertex, int source, vector<int>& visit) {
    int FinalValidationSourceIndex = getIndex(NodeLabel, source);
    if (FinalValidationSourceIndex == -1 )
        return;

    cout << source << " ";  
    visit[FinalValidationSourceIndex] = 1;  

    for (int i = 0; i < vertex; i++) {
        if (adjMatrix[FinalValidationSourceIndex][i] == 1 && visit[i] == 0) {
            TraverseDFS(adjMatrix, NodeLabel, vertex, NodeLabel[i], visit);
        }
    }
}

int main() {
    int vertex, edge;
    cout << "Enter your graph vertex: ";
    cin >> vertex;
    cout << "Enter your graph edge: ";
    cin >> edge;

    int adjMatrix[MAX][MAX] = {0};
    vector<int> NodeLabel;
    
    cout << "Enter edges (format: u v for undirected graph):" << endl;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        int U_index = getIndex(NodeLabel, u);
        if (U_index == -1) {
            NodeLabel.push_back(u);
            U_index = NodeLabel.size() - 1;
        }
        int V_index = getIndex(NodeLabel, v);
        if (V_index == -1) {
            NodeLabel.push_back(v);
            V_index = NodeLabel.size() - 1;
        }

        adjMatrix[U_index][V_index] = 1;
        adjMatrix[V_index][U_index] = 1;  // Since it's an undirected graph
    }

    cout << "Adjacency Matrix:" << endl;
    int n = NodeLabel.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    int sourceNode;
    cout << "Enter your source node: ";
    cin >> sourceNode;

    vector<int> visit(n, 0);  // Keep track of visited nodes

    cout << "DFS Traversal: ";
    TraverseDFS(adjMatrix, NodeLabel, n, sourceNode, visit);
    cout << endl;

    return 0;
}


 //  Final TC = O(n^2) OR  O(n + e)
//  Final SC = O(n) 