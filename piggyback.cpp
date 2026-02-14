#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<climits>
using namespace std;

// Function to find the level of the given node
int findLevel(int N, vector<vector<int> >& edges, int X)
{

    // Variable to store maximum vertex of graph
    int maxVertex = 0;
    for (auto it : edges) {
        maxVertex = max({ maxVertex, it[0], it[1] });
    }

    // Creating adjacency list
    vector<int> adj[maxVertex + 1];
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // If X is not present then return -1
    if (X > maxVertex || adj[X].size() == 0)
        return -1;

    // Initialize a Queue for BFS traversal
    queue<int> q;
    q.push(N);
    int level = 0;

    // Visited array to mark the already visited nodes
    vector<int> visited(maxVertex + 1, 0);
    visited[N] = 1;

    // BFS traversal
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto currentNode = q.front();
            q.pop();
            if (currentNode == X) {
                return level;
            }

            for (auto it : adj[currentNode]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        level++;
    }

    return -1;
}

//b starts at 0, e starts at 1.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("10.in", "r", stdin);
    int b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;
    vector<vector<int>> connections;
    vector<int> temp(2);
    for (int i=0; i<m; i++) {
        int f, s;
        cin >> f >> s;
        connections.push_back({f, s});
    }
    int apart_stepse = b*findLevel(1, connections, n) + e*findLevel(2, connections,n);
    int together_stepse= INT_MAX;
    for (int i=1; i<n; i++) {
        int together = findLevel(i, connections, n);
        int bsteps = findLevel(1, connections, i);
        int esteps = findLevel(2, connections, i);
        if (together != -1 && bsteps != -1 && esteps != -1 && p*together + b*bsteps + e*esteps < together_stepse) {
            together_stepse = p*together + b*bsteps + e*esteps;
        }
    }
    if (together_stepse <= apart_stepse) {
        cout << together_stepse;
    } 
    else {
        cout << apart_stepse;
    }
}