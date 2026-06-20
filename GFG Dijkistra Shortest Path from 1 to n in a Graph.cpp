class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        //1.Create AdjList
        vector<pair<int,int>>AdjList[n+1];
        for(int i=0;i<m;i++)
        {
        AdjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        AdjList[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        //2.Dijkstra but also store parent for each node on the path
        vector<int>ans;
        vector<bool> explore(n+1, 0);
        vector<int> dist(n+1, INT_MAX);
        dist[1] = 0;
        //parent array
        vector<int>parent(n+1,-1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        p.push({0, 1});
        
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
                parent[neighbour]=node;
                p.push({dist[neighbour], neighbour});
            }
        }
    }
    //now after dijkistra check whether our distination dist[n] is reached or still INT_MAX
      // if still INT_MAX that means we did not reach so return {-1} as told in question
    if(dist[n]==INT_MAX) return {-1};

      //now we start from the final node as destiny desti and travel till desti =-1(parent of start node)  
      //so while doing that we store the parents of each node from reverse to first and then its total weight
      //now reverse the whole thing to get our answer
    int desti=n; 
    while(desti!=-1)
    {
        ans.push_back(desti);
        desti=parent[desti];
    }
        ans.push_back(dist[n]);

    reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
