// User function Template for C++
class Solution {
  public:
  
  //here it makes sense to send vis and s using pass by address
  //but why not AdjList 
//becoz it is an array not 2D vector
   void DFS(int node,vector<int>&vis,vector<pair<int,int>>AdjList[],stack<int>&s)
       {
           vis[node]=1;
           for(int i=0;i<AdjList[node].size();i++)
           {
               if(!vis[AdjList[node][i].first])
               {
                 vis[AdjList[node][i].first]=1;
                 DFS(AdjList[node][i].first,vis,AdjList,s);
               }
           }
        s.push(node);  
       }
       
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int>dist(V,INT_MAX);
        dist[0]=0;
        //Step 1 Create AdjList
        vector<pair<int,int>>AdjList[V];
        for(int i=0;i<E;i++)
        {
            AdjList[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
       // Step 2 DFS Toposort and fill the stack
       stack<int>s;
       vector<int>vis(V,0);
       //we are not visiting unconnected vetices to src wantedly
       //so removing that for loop across vis array to visit unconnected vetices
       //since anyways their dist  will be -1
       //so this si the modification in  toposort algo here
       DFS(0,vis,AdjList,s);
       
       
      
       //Step 3 Empty the stack with the top(which has no parent) coming out first
       while(!s.empty())
       {
       int current=s.top();
       s.pop();
       for(int j=0;j<AdjList[current].size();j++)
       {
        //Step 4 Fill the dist vector of its neighbours 
           dist[AdjList[current][j].first]=min(dist[AdjList[current][j].first],dist[current]+AdjList[current][j].second);
       }
       }
       
       //Step 5 : for the nodes which are not connected to src(0) 
       //for them dist wouldnt change, so change them to -1;
       
       for(int p=0;p<V;p++)
       {
           if(dist[p]==INT_MAX)  dist[p]=-1;
       }
       return dist;
       
       
    }
};

