class Solution {
    unordered_map<int,vector<int>> adj; //Adj list
    void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<vector<int>>& bridges)
    {
        static int time = 0;    //timestamp
        disc[u] = low[u] = time;
        time +=1;
        
        for(int v: adj[u])
        {
            if(disc[v]==-1) //If v is not visited
            {
                parent[v] = u;
                DFS(v,disc,low,parent,bridges);
                low[u] = min(low[u],low[v]);
                
                if(low[v] > disc[u])
                    bridges.push_back(vector<int>({u,v}));
            }
            else if(v!=parent[u])   //Check for back edge
                low[u] = min(low[u],disc[v]);
        }
    }
    void findBridges_Tarjan(int V,vector<vector<int>>& bridges)
    {
        vector<int> disc(V,-1),low(V,-1),parent(V,-1);
        //Apply DFS for each component
        for(int i=0;i<V;++i)
            if(disc[i]==-1)
                DFS(i,disc,low,parent,bridges);
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();++i)   //Make Adj list (step 1)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<vector<int>> bridges; //Store all the bridges as pairs
        findBridges_Tarjan(n,bridges); //step 2(applying TARJANS AlGO)
        return bridges;
    }
};