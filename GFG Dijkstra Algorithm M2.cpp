class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // 1. Corrected Adjacency List to store pairs: {neighbor, weight}
        vector<pair<int, int>> AdjList[V];
        for(int i = 0; i < edges.size(); i++) {
            // edges[i][0] -> u, edges[i][1] -> v, edges[i][2] -> weight
            AdjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            AdjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});

        }
        
        // 2. Initialize Dijkstra states
        // Code here
    vector<bool> explore(V, 0);
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, src});

    // Select a node which is not explored yet and its distance value is min.

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();

//if already this node is explored then just go to next loop
        if (explore[node] == 1)
            continue;
            
//if not explored then
        explore[node] = 1;

        // Relax the edges.
        for (int i = 0; i < AdjList[node].size(); i++)
        {
            int neighbour = AdjList[node][i].first;
            int weight = AdjList[node][i].second;

            if (!explore[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
            }
        }
    }
    return dist;
    }
};
