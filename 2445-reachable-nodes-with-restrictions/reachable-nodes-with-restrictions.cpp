// // DFS

// class Solution {
// public:
//     int reachableNodes(int n, vector<vector<int>>& edges,
//                        vector<int>& restricted) {
//         vector<vector<int>> adj(n);
//         vector<bool> visited(n, false);

//         for (auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         for (int node : restricted) {
//             visited[node] = true;
//         }

//         int count = 0;
//         dfs(0, adj, visited, count);

//         return count;
//     }

// private:
//     void dfs(int node, vector<vector<int>>& adj,
//              vector<bool>& visited, int& count) {
//         visited[node] = true;
//         count++;

//         for (int neighbor : adj[node]) {
//             if (!visited[neighbor]) {
//                 dfs(neighbor, adj, visited, count);
//             }
//         }
//     }
// };


//BFS


class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        queue<int> q;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int x : restricted)
            visited[x] = true;

        q.push(0);
        visited[0] = true;

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return count;
    }
};
