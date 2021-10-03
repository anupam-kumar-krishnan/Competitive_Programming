#include<bits/stdc++.h>
using namespace std;


int median(vector<vector<int>> &m, int r, int c){
        // code here 
        int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
  
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
  
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
  
        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i].begin(), m[i].begin()+c, mid)-m[i].begin();
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
    }

    int main() {
        int t;
        cin>>t;

        while(t--) {
            int r,c;
            cin>>r>>c;

            vector<vector<int> > m(r,vector<int>(c));

            for(int i=0;i<r;i++) {
                for(int j=0;j<c;j++) {
                    cin>>m[i][j];
                }
            }

            cout<<median(m,r,c)<<"\n";
        }

        return 0;
    }