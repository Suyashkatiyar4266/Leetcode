class Solution {
void bfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while(!q.empty()){
        int u =q.front();
        q.pop();
        for(int v = 0; v < isConnected.size(); v++)
        {
            if(isConnected[u][v] == 1 && !visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count = 0;
        for(int i=0 ; i < n ; i++)
        {
            if(visited[i]==false)
            {
                bfs(isConnected , i , visited);
                count++;
            }
        }
        return count;
    }
};
