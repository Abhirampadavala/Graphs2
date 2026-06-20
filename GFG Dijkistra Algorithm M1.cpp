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
        vector<int> dist(V, INT_MAX);
        vector<int> explr(V, 0);
        dist[src] = 0;
        
        // outer loop to repeat the process V times
      //Now because of this The TC reaches O(V^2) and gives TLE for some test cases
      //So in M2 we will use priority queue
        for(int p = 0; p < V; p++) {
            
            int node = -1;
            int value = INT_MAX;
            
            for(int j = 0; j < V; j++) {
                if(!explr[j] && dist[j] < value) {
                    node = j;
                    value = dist[j];
                }
            }
            
            // FIX: If no more reachable nodes are found, terminate early
           if(node == -1) {
              break;
          }
            
            // Mark the selected minimum node as explored
            explr[node] = 1;
            
            // Traverse and relax neighbors
            for(int i = 0; i < AdjList[node].size(); i++) {
                int nbd = AdjList[node][i].first;
                int wt = AdjList[node][i].second;
                
                // FIX: Added check to prevent adding to INT_MAX (overflow prevention)
                if(!explr[nbd] && dist[node] != INT_MAX) {
                    dist[nbd] = min(dist[nbd], dist[node] + wt);
                }
            }
        }
        
        return dist;
    }
};
