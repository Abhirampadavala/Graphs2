class Solution {
  public:
  
  int rows[4]={0,0,1,-1};
  int cols[4]={-1,1,0,0};
  
  bool valid(int i, int j,int n,int m)
  {
      if(i<n && i>-1 && j<m && j>-1) 
      {
          return 1;
      }
       return 0;
  }
  
  int BFS(int scrx,int scry,vector<vector<int>>& vis,int destx,int desty,queue<pair<int,int>>q,vector<vector<int>> &mat)
  {   
      int count=0;
      q.push({scrx,scry});
      while(!q.empty())
      {
      for(int i=0;i<4;i++)
      {
      if(valid(scrx+rows[i],scry+cols[i],n,m) && !vis[scrx+rows[i]][scry+cols[i]])
      {
          if(mat[scrx+rows[i]][scry+cols[i]]==1)
          {
          dist[scrx+rows[i]][scry+cols[i]]=dist[scrx][scry]+1;
          
         if([scrx+rows[i]]==destx && [scry+cols[i]]==desty) return dist;
         
            vis[scrx+rows[i]][scry+cols[i]]=1;
            q.push({scrx+rows[i],scry+cols[i]})
          }
      }
      }
      }
      return -1;
      
  }
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        int ans=(m*n)+1;
      return BFS(src[0],src[1],vis,dest[0],dest[1],q,mat);
    }
};
