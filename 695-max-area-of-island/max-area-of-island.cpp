class Solution {
public:
    int DFS(vector<vector<int>> &grid ,int r, int c){
        int m = grid.size();
        int n = grid[0].size();
        if(r<0 || r>=m || c < 0 || c >= n || grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        int area = 1;
        area += DFS(grid, r+1 , c);
        area += DFS(grid, r-1 , c);
        area += DFS(grid, r , c+1);
        area += DFS(grid, r , c-1);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;
        if(grid.empty())
            return 0;
        for(int r = 0 ; r < m; r++){
            for(int c = 0 ; c < n; c++){
                if(grid[r][c] ==1){
                    max_area = max(max_area, DFS(grid , r,c));
                }
            }
        }
        return max_area;
    }

};