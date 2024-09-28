class Solution
{
public:
    vector<int> adj_list[200005];
    bool vis[200005];
    bool dis[200005];

    void bfs(int i)
    {
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            for (auto child : adj_list[parent])
            {
                if (!vis[child])
                {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        for (auto vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        bfs(source);
        return vis[destination];
    }
};