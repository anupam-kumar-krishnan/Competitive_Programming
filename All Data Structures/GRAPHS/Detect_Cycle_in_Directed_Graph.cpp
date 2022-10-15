#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Graph{
    private:
      ll v;
      list<ll> *adj;
    public:
      Graph(ll v){
        this->v = v;
        adj = new list<ll>[v];
      }

      void addEdge(ll p,ll q){
        adj[p].push_back(q);
      }

      bool checkCycle(ll node,vector<ll> &vis,vector<ll> &rec){
        if(vis[node] == 0){
            vis[node] = 1;
            rec[node] = 1;
            for(auto x: adj[node]){
                if(vis[x] == 0 and checkCycle(x,vis,rec)){
                    return true;           
                }else if(rec[x] == 1){
                    return true;
                }
            }   
        }
        rec[node] = 0;
        return false;
      }

      bool isCyclic(){
        vector<ll> vis(v,0), rec(v,0);
        for(ll i = 0 ; i < v; i++){
            if(vis[i] == 0 and checkCycle(i,vis,rec)){
                return true;
            }
        }
        return false;
      }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);    
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(0, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;    
}