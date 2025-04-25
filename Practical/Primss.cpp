#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//  Requirements Baba ki :  4 vector name 

// [I] destination[] , Every nodes must be infinite except Source  
// [II] Previous[] , Tracking the final MST .
// [III] Color[] ,  for tracking the nodes which is already visited 
// [IV] EdgeCost[] , each nodes and vertex edge cost .

#define MAX 100

class MST {
public:
    vector<int> NodeLabel;
    vector<int> Dest;
    vector<int> Prev;
    vector<string> Color;
    const int INF = 1e9;

    // Get index of a node label
    int getIndex(vector<int>& NodeLabel, int source) {
        int n = NodeLabel.size();
        for (int i = 0; i < n; i++) {
            if (NodeLabel[i] == source)
                return i;
        }
        return -1;
    }

    // Initialize vectors  While tracking or the graph we need it for solution .
    void initializeGraph(int size, int sourceIndex) {
        Dest = vector<int>(size, INF);   // Initialy all nodes value is +INF
        Prev = vector<int>(size, -1);    // This array helps to make the MST 
        Color = vector<string>(size, "W");  // Visited value not allowd again Restricted Color 

        Dest[sourceIndex] = 0; // Distance to source is 0
    }

    // Get the unvisited node with minimum edge cost
    int getMinIndex(int size) {
        int minCost = INF;
        int minIndex = -1;
        for (int i = 0; i < size; i++) {
            if (Color[i] == "W" && Dest[i] < minCost) {
                minCost = Dest[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    // Prim's Algorithm (Edge Relaxation Phase)

    void Edge_Relaxation(int adjMatrix[MAX][MAX]) {
        int size = NodeLabel.size();

        while (true) {
            int u = getMinIndex(size);
            if (u == -1)
                break;

            Color[u] = "B"; // mark visited

            for (int v = 0; v < size; v++) {

                if (adjMatrix[u][v] != 0 && Color[v] == "W" && adjMatrix[u][v] < Dest[v]) {

                    Dest[v] = adjMatrix[u][v];

                    Prev[v] = u;
                }
            }
        }

        // Show MST result
        cout << "\nMinimum Spanning Tree (using Prim's Algorithm):\n";
        int totalCost = 0;
        for (int i = 0; i < size; i++) {
            if (Prev[i] != -1) {
                cout << "Edge: " << NodeLabel[Prev[i]] << " - " << NodeLabel[i]
                     << " | Cost: " << Dest[i] << endl;
                totalCost += Dest[i];
            }
        }
        cout << "Total Cost of MST: " << totalCost << endl;
    }
};

int main() {
    vector<int> inputNodeLabels;
    MST M1;
    int vertex, edge;
    cout << "Enter your graph vertex: ";
    cin >> vertex;
    cout << "Enter your graph edge: ";
    cin >> edge;

    int adjMatrix[MAX][MAX] = {0};

    cout << "Enter edges (format: u v edge_cost):\n";
    for (int i = 0; i < edge; i++) {
        int u, v, edge_cost;
        cin >> u >> v >> edge_cost;

        int U_index = M1.getIndex(M1.NodeLabel, u);
        if (U_index == -1) {
            M1.NodeLabel.push_back(u);
            U_index = M1.NodeLabel.size() - 1;
        }

        int V_index = M1.getIndex(M1.NodeLabel, v);
        if (V_index == -1) {
            M1.NodeLabel.push_back(v);
            V_index = M1.NodeLabel.size() - 1;
        }

        adjMatrix[U_index][V_index] = edge_cost;
        adjMatrix[V_index][U_index] = edge_cost;
    }

    // Show adjacency matrix
    int n = M1.NodeLabel.size();
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 0)
                cout << "∞ ";
            else
                cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    int sourceLabel;
    cout << "\nEnter your Source Node label: ";
    cin >> sourceLabel;

    int sourceIndex = M1.getIndex(M1.NodeLabel, sourceLabel);
    if (sourceIndex == -1) {
        cout << "Source node not found.\n";
        return 0;
    }

    M1.initializeGraph(n, sourceIndex);
    M1.Edge_Relaxation(adjMatrix);

    return 0;
}



//  Baba TC Ki baat kre ? 

// Solution  :     Main Factor for Time Complexity 

// [I]    n time dlt operation from min heap = O(n.logn)
// [II]  Find All Adjacency Matrics  = O(n^2)
// [III] Key Decrement n times = O(n*e)  


//  Overall T.C = O(n^2 log n) 