class Solution
{
public:
    // color 1 = 1
    // color 2 = 0

    // if curr color is 1 -> 1-currColor -> 1-1=0 and if currColor is 0 ->
    // 1-currColor -> 1-0 = 1 switching the color
    bool checkBipartite(vector<vector<int>> &graph, int curr,
                        vector<int> &color, int currColor)
    {
        color[curr] = currColor;

        for (auto &v : graph[curr])
        {
            if (color[v] == currColor)
            {
                return false;
            }

            if (color[v] == -1)
            {
                if (!checkBipartite(graph, v, color, 1 - currColor))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!checkBipartite(graph, i, color, 1))
                {
                    return false;
                }
            }
        }

        return true;
    }
};