class Solution
{
public:
    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited)
    {
        visited[u] = true;

        // Visit neighbours
        for (int &v : adj[u])
        {
            if (!visited[v])
            {
                dfs(adj, v, visited);
            }
        }
    }

    void dfsOptimized(vector<vector<int>> &isConnected, vector<bool> &visited, int u)
    {
        visited[u] = true;

        for (int v = 0; v < isConnected.size(); v++)
        {
            if (isConnected[u][v] == 1 && u != v && !visited[v])
            {
                dfs(isConnected, visited, v);
            }
        }
    }

    void bfs(vector<vector<int>> &adj, vector<bool> &visited, int u)
    {

        queue<int> q;

        q.push(u);
        visited[u] = true;
        while (!q.empty())
        {
            int front = q.front();

            q.pop();
            for (auto &v : adj[front])
            {
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(adj, i, visited);
            }
        }

        return count;
    }
};