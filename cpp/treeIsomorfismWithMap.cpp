#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10; 
 
int n, ID, degree[MAX];
map<map<int, int>, int> formato;
bool vis[MAX];
 
void init()
{
    formato.clear();
    ID = 1;
}
 
int dfs(int v, int p, vector<vector<int>> &G)
{
    if((int)G[v].size() == 1)
        return 1;
    map<int, int> ids;
    for(int &u : G[v])
    {
        if(u == p) continue;
        int x = dfs(u, v, G);
        ids[x]++;
    }
    if(formato.count(ids) <= 0)
        formato[ids] = ++ID;
    return formato[ids];
}
 
inline void findCenterAndComputeID(vector<vector<int>> &G, vector<int> &val)
{
    memset(vis, 0, sizeof(vis));
    queue<int> fila[2];
    for(int i = 0; i < n; i++)
        if(degree[i] == 1)
            fila[0].push(i);
    int cnt = 0, turn = 0;
    while(cnt + 2 < n)
    {
        while(!fila[turn].empty())
        {
            int u = fila[turn].front(); fila[turn].pop();
            vis[u] = true;
            cnt++;
            for(int i = 0; i < G[u].size(); i++)
                if(!vis[G[u][i]])
                {
                    degree[G[u][i]]--;
                    if(degree[G[u][i]] == 1) fila[1-turn].push(G[u][i]);
                }
        }
        turn ^= 1;
    }
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        val.push_back(dfs(i, -1, G));
    }
}
 
int32_t main()
{
    while(cin >> n)
    {
        init();
        vector<int> val[2];
        for(int j = 0; j < 2; j++)
        {
            memset(degree, 0, sizeof(degree));
            vector<vector<int>> G(n + 1);
            for(int i = 1; i < n; i++)
            {
                int u, v;
                scanf(" %d %d", &u, &v); u--; v--;
                G[u].push_back(v);
                G[v].push_back(u);
                degree[v]++;
                degree[u]++;
            }
            findCenterAndComputeID(G, val[j]);
        }
        bool fl = false;
        for(int &v0 : val[0])
            for(int &v1 : val[1])
                if(v0 == v1)
                    fl = true;
        puts(fl ? "S" : "N");
    }
 
    return 0;
}