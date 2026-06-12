class Solution {
public:
   static const int n = 100054;
   static const int LOG = 20;
   static const int mod = 1e9 + 7;
   int depth[n];
   int parent[n];
   vector<int>adj[n];
   int up[n][LOG];
   long long power( long long a,  long long b)
   {
    long long ans = 1;
    while(b > 0)
    {
        if(b % 2)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
   }
   void dfs(int node, int parent)
   {
     up[node][0] = parent;
     for(int j = 1; j < LOG; j++)
     {
        up[node][j] = up[up[node][j-1]][j-1];
     }
     for(auto it : adj[node])
     {
        if(it == parent)continue;
        depth[it] = depth[node] + 1;
        dfs(it, node);
     }
   }
   int lca(int u, int v)
   {
     if(depth[u] < depth[v])
     {
        swap(u, v);
     }
     int diff = depth[u] - depth[v];
     for(int j = LOG - 1; j >= 0; j--)
     {
        if(diff & (1 << j))
        {
            u = up[u][j];
        }
     }
     if(u == v)return u;
     for(int j = LOG - 1; j >= 0; j--)
     {
        if(up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
     }
     return up[u][0];
   }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth[1] = 0;
        dfs(1, 0);
        for(int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            int l = lca(u, v);
            long long val = depth[u] + depth[v] - 2LL * depth[l];
            if(val == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(power(2, val - 1));
            }
        }
        return ans;
    }
};