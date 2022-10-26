  public:
    // Function to detect cycle in an undirected graph.
    int parent[100005];
    int find(int v)
    {
        if(parent[v]==-1)return v;
        else return find(parent[v]);
    }
    void unin(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        parent[x]=y;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // set<pair<int,int>>s;
        memset(parent,-1,sizeof(parent));
        for(int i=0;i<V;i++)
        {
            for(auto it2:adj[i])
            {
                if(i<it2)
                {
                    int a=find(i);
                    int b=find(it2);
                    if(a==b)return true;
                    unin(a,b);
                }
            }
        }
        return false;
    }
};