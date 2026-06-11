class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int>vis(V,0);
        vector<int>dist(V,-1);
        queue<int> q;
        vis[src]=1;
        dist[src]=0;
        //Step 1: Convert edges into AdjList
        vector<vector<int>>AdjList(V);
        for(int i=0;i<edges.size();i++)
        {
            AdjList[edges[i][0]].push_back(edges[i][1]);
            AdjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        //Step 2:BFS  every breadth box is at equal distance from the source and
        
        q.push(src);
        while(!q.empty())
        {
          int node=q.front();
          q.pop();
          for(int i=0;i<AdjList[node].size();i++)
          {
              if(!vis[AdjList[node][i]])
              {
                 vis[AdjList[node][i]]=1; 
                 q.push(AdjList[node][i]);
                 // is 1+ distance of nodes of its previous breadth box
                 dist[AdjList[node][i]]=dist[node]+1;
              }
          }
          
        }
        
        return dist;
        
    }
};
