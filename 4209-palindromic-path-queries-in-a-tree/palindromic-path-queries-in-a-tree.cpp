// class Solution {
// private:
//     int n;
//     vector<vector<int>> adj;
//     vector<int> parent, depth, heavy, head, pos, val;
//     int curPos;

//     struct SegmentTree{
//         int size;
//         vector<int> tree;

//         SegmentTree(int n){
//             size = n;
//             tree.assign(4 * n, 0);
//         }

//         void update(int node, int start, int end, int idx, int val){
//             if(start == end){
//                 tree[node] = val;
//                 return;
//             }

//             int mid = start + (end - start) / 2;
//             if(idx <= mid){
//                 update(2 * node, start, mid, idx, val);
//             }else{
//                 update(2 * node + 1, mid + 1, end, idx, val);
//             }

//             tree[node] = tree[2 * node] ^ tree[2 * node + 1];
//         }

//         int query(int node, int start, int end, int l, int r){
//             if(r < start || end < l){
//                 return 0;
//             }
//             if(l <= start && end <= r){
//                 return tree[node];
//             }

//             int mid = start + (end - start) / 2;
//             return query(2 * node, start, mid, l, r) ^ query(2 * node + 1, mid + 1, end, l, r);
//         }
//     };

//     int dfs(int u, int p, int d){
//         depth[u] = d;
//         parent[u] = p;

//         int size = 1;
//         int maxChildSize = 0;

//         for(int v : adj[u]){
//             if(v != p){
//                 int childSize = dfs(v, u, d + 1);
//                 size += childSize;

//                 if(childSize > maxChildSize){
//                     maxChildSize = childSize;
//                     heavy[u] = v;
//                 }
//             }
//         }

//         return size;
//     }

//     void decompose(int u, int h){
//         head[u] = h;
//         pos[u] = curPos++;

//         if(heavy[u] != -1){
//             decompose(heavy[u], h);
//         }

//         for(int v : adj[u]){
//             if(v != parent[u] && v != heavy[u]){
//                 decompose(v, v);
//             }
//         }
//     }

//     int queryPath(int u, int v, SegmentTree& segTree){
//         int res = 0;

//         while(head[u] != head[v]){
//             if(depth[head[u]] > depth[head[v]]){
//                 swap(u, v);
//             }

//             res ^= segTree.query(1, 0, n - 1, pos[head[v]], pos[v]);
//             v = parent[head[v]];
//         }

//         if(depth[u] > depth[v]){
//             swap(u, v);
//         }

//         res ^= segTree.query(1, 0, n - 1, pos[u], pos[v]);
//         return res;
//     }

// public:
//     vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries){
//         this->n = n;
//         adj.assign(n, vector<int>());

//         for(const auto& e : edges){
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }

//         parent.assign(n, 0);
//         depth.assign(n, 0);
//         heavy.assign(n, -1);
//         head.assign(n, 0);
//         pos.assign(n, 0);

//         dfs(0, -1, 0);

//         curPos = 0;
//         decompose(0, 0);

//         SegmentTree segTree(n);
//         val.resize(n);

//         for(int i = 0; i < n; i++){
//             val[i] = 1 << (s[i] - 'a');
//             segTree.update(1, 0, n - 1, pos[i], val[i]);
//         }

//         vector<bool> ans;

//         for(const string& q : queries){
//             stringstream ss(q);
//             string type;
//             ss >> type;
//             if(type == "update"){
//                 int u;
//                 char c;
//                 ss >> u >> c;
//                 val[u] = 1 << (c - 'a');
//                 segTree.update(1, 0, n - 1, pos[u], val[u]);
//             }else{
//                 int u, v;
//                 ss >> u >> v;
//                 int mask = queryPath(u, v, segTree);
//                 ans.push_back((mask & (mask - 1)) == 0);
//             }
//         }
//         return ans;
//     }
// };

//Euler Tour + Fenwick Tree (XOR) + LCA


class Solution {
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, initial, val;

    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int x) {
            for (; i <= n + 1; i += i & -i)
                bit[i] ^= x;
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        }

        void rangeXor(int l, int r, int x) {
            update(l + 1, x);
            update(r + 2, x);
        }

        int pointQuery(int i) {
            return query(i + 1);
        }
    };

    void dfs(int u, int p) {
        tin[u] = timer++;

        up[0][u] = (p == -1 ? u : p);

        for (int k = 1; k < LOG; k++)
            up[k][u] = up[k - 1][up[k - 1][u]];

        initial[u] = (p == -1 ? 0 : initial[p])
                     ^ (1 << (val[u]));

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer - 1;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++)
            if (diff & (1 << k))
                u = up[k][u];

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        depth.assign(n, 0);
        tin.resize(n);
        tout.resize(n);
        initial.assign(n, 0);
        val.resize(n);

        for (int i = 0; i < n; i++)
            val[i] = s[i] - 'a';

        up.assign(LOG, vector<int>(n, 0));

        timer = 0;
        dfs(0, -1);

        Fenwick bit(n);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int oldMask = 1 << val[u];
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                val[u] = c - 'a';

                bit.rangeXor(tin[u], tout[u], delta);
            } else {
                int u, v;
                ss >> u >> v;

                int pu = initial[u] ^ bit.pointQuery(tin[u]);
                int pv = initial[v] ^ bit.pointQuery(tin[v]);

                int w = lca(u, v);

                int mask = pu ^ pv ^ (1 << val[w]);

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
