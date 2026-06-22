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
        bool flag =0;
        for(int i=0;i<edges.size();i++)
        { 
          //edge relaxing
          
          //this next line is added to correct the code
          //For comparing infinity-3 and infinity math works but we cant take that in code so writing 10^8 as that value
          //so we will write this condititon
          if(dist[edges[i][0]]==1e8) continue;

          //one more thing that while loop runs for V-1 times for worst case
          //if we found out that correct value of dist is already obtained and
          //in next iteration no change is happening to dist(i.e dist value not decreasing) then break the loop and return the dist
          //if no change happens then then flag remains 0 and in next if condition returns dist
          //if change happens then dist will be updated and flag will  be changed to 1
                    if(dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]])
                    {
                      flag=1;
                     dist[edges[i][1]]=dist[edges[i][0]]+edges[i][2];
                    }

            
          if(dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]])  
          {
          dist[edges[i][1]]=dist[edges[i][0]]+edges[i][2];
          }
        }

          //flag 1 means change happend , while ka loop continues
         if(!flag) 
          {
           return dist;
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
