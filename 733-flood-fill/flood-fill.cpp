class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int m = image.size();
        int n = image[0].size();
        int fr = image[sr][sc];
        if(fr == color)
            return image;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if(r - 1 >= 0 && image[r - 1][c] == fr){
                image[r - 1][c] = color;
                q.push({r - 1, c});
            }
            if(r + 1 < m && image[r + 1][c] == fr){
                image[r + 1][c] = color;
                q.push({r + 1, c});
            }
            if(c - 1 >= 0 && image[r][c - 1] == fr){
                image[r][c - 1] = color;
                q.push({r, c - 1});
            }
            if(c + 1 < n && image[r][c + 1] == fr){
                image[r][c + 1] = color;
                q.push({r, c + 1});
            }
        }
        return image;
    }
};