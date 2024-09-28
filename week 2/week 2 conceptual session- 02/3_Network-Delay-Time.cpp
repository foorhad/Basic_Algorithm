class Solution
{
public:
    vector<pair<int, int>> adj[105];
    int dis[105];
    void dijktre(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dis[src] = 0;

        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int parentCost = p.first;
            int parentNode = p.second;

            for (auto p : adj[parentNode])
            {
                int childNode = p.second;
                int childCost = p.first;

                if (parentCost + childCost < dis[childNode])
                {
                    dis[childNode] = parentCost + childCost;
                    pq.push({dis[childNode], childNode});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        for (auto x : times)
        {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            adj[u].push_back({w, v});
        }
        for (int i = 1; i <= n; i++)
            dis[i] = INT_MAX;
        dijktre(k);

        int mx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] == INT_MAX)
                return -1;
            mx = max(mx, dis[i]);
        }
        return mx;
    }
};