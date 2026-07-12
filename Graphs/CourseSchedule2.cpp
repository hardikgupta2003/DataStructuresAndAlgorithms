class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        vector<int> indegree(numCourses);
        queue<int> q;
        for (auto &edges : prerequisites)
        {
            int a = edges[0];
            int b = edges[1];
            adj[b].push_back(a);
        }
        for (int u = 0; u < numCourses; u++)
        {
            for (auto &v : adj[u])
            {
                indegree[v]++;
            }
        }
        int count = 0;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            count++;
            ans.push_back(u);
            for (auto &v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return (count == numCourses) ? ans : vector<int>{};
    }
};