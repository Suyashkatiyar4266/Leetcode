// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();

//                         // Base cases

//         if(n==0||grid[0][0]==1||grid[n-1][n-1]==1){
//             return -1;
//         }
//         if(n==1){
//             return 1;
//         }
//         vector<pair<int,int>> dir={
//             {-1,0},     
//             {1,0},     
//             {0,-1},     
//             {0,1},     
//             {-1,1},     
//             {-1,-1},     
//             {1,-1},     
//             {1,1},     
//         };

//                         //setup BFS

//         queue<array<int,3>> q;
//         q.push({0,0,1});
//         grid[0][0]=1;
//         while(!q.empty())
//         {
//             auto[r,c,d] = q.front();
//             q.pop();
//             if(r==n-1 && c==n-1)
//             return d;
//             for(auto[x,y]:dir){
//                 int rn = r + x;
//                 int cn = c + y;
//                 if(rn>=0 && rn <n && cn >= 0 && cn < n && grid[rn][cn]==0){
//                     grid[rn][cn]=1;
//                     q.push({rn,cn,d+1});
//                 }
//             }
//         }
//         return -1;
//     }
// };




                    // Dijkstra's Approach

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n == 0 || grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        if (n == 1)
            return 1;

        vector<pair<int, int>> dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, 1}, {-1, -1}, {1, -1}, {1, 1}
        };

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;
        pq.push({1, {0, 0}});

        while (!pq.empty()) {
            auto [d, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            if (d > dist[r][c])
                continue;

            if (r == n - 1 && c == n - 1)
                return d;

            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 &&
                    d + 1 < dist[nr][nc]) {

                    dist[nr][nc] = d + 1;
                    pq.push({d + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
