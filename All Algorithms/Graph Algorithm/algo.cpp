//Question : return a list of numbers of n digits whose difference between the digits is k .
//In this problem we will use bfs-breadth first search algorithm
/*Breadth-first search is a graph traversal algorithm that starts traversing the graph from the root node and explores all the neighboring nodes.
Then, it selects the nearest node and explores all the unexplored nodes. 

Here are a few steps to implement the BFS algorithm for this problem.

We could implement the algorithm with nested two-levels loops, where the outer loop iterates through levels and the inner loop handles the elements within each level.

We could use a queue data structure to keep the numbers for a single level.

For each number in the queue ,rather than making a recursive call for the next number we simply append the number to the queue for the next level.

*/
#include<bits/stdc++.h>
using namespace std;
void numsSameConsecDiff(int n, int k) {
       vector<int> v;
        queue<pair<int,int>> q;//queue data structure for each level
				for(int i=1;i<=9;i++){   
            q.push({i,1});
            while(!q.empty()){
                pair<int, int> curr=q.front();
                q.pop();
                int num=curr.first;
                int length=curr.second;
                if(length==n){
                    v.push_back(num);
                    continue;
                }
                int ld=num%10;
                if(k==0)
                    q.push({num*10+ld, length+1});
                else{
                    if(ld+k<10)
                        q.push({num*10+ld+k, length+1});
                    if(ld-k>=0)
                        q.push({num*10+ld-k, length+1});
                }
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        cout<<"\n";
    }
    //main function
int main()
{
    int n,k;
    cin>>n>>k;
 
    // Function Call
    numsSameConsecDiff(n,k);
   
    return 0;
   
}