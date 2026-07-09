class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        queue<int> q;

        int count = 0;

        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++)
        {
            for (auto &v : adj[u])
            {
                indegree[v]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            count++;

            for (auto &v : adj[front])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        if (count == V)
            return false;
        else
            true;
    }
};
