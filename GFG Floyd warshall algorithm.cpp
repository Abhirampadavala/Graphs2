class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        //first converting all 1e8 values to INT_MA for ease(infinity)
        int n=dist.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]==100000000)
                {
                    dist[i][j]=INT_MAX;
                }
            }
        }
        
        //floyd warshall algorithm
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;
                    
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        //again setting the values back to 1e8 for which that is itself the shortest distance
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]==INT_MAX)
                {
                    dist[i][j]=100000000;
                }
            }
        }
    }
};
