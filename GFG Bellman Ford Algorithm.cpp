class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        //1e8 or simply write 100000000
        vector<int>dist(V,1e8);
        dist[src]=0;
        int count=V-1;
        //doing the loop for V-1 times
        while(count--){
        
        for(int i=0;i<edges.size();i++)
        {
            
          //this next line is added to correct the code
          if(dist[edges[i][0]]==1e8) continue;
            
          if(dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]])  
          {
          dist[edges[i][1]]=dist[edges[i][0]]+edges[i][2];
          }
        }
        }
        
        //cycle detection
        for(int i=0;i<edges.size();i++)
        {
          if(dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]])  
          {
              //this next line is added to correct the code
          if(dist[edges[i][0]]==1e8) continue;
              return {-1};
          }
        }
        
        return dist;
    }
};
