#include <bits/stdc++.h>

std::vector<std::vector<int>> g1;
std::vector<std::pair<int,int>> zeroVector;
	int m, n, q;


void takevectorinput(int n, int m) {
	int tmp=0;
	for (int i=1; i<=n; i++) {
		std::vector<int> store;
		for (int j=1; j<=m; j++)
		{
			std::cin >> tmp;
			store.push_back(tmp);
            if (tmp == 0)
            {
                zeroVector.push_back(std::make_pair(i,j));
            }
		}
		g1.push_back(store);
	}
}

int cheapestpath(std::pair<int, int> startingpoint, std::pair<int, int> endingpoint) {
	
	// Same point
	if (startingpoint.first == endingpoint.first && startingpoint.second == endingpoint.second) {
		return g1[startingpoint.first-1][startingpoint.second-1];
	}

    if (zeroVector.size() > 0 )
    {
        for (int i=0;i<zeroVector.size();i++)
        {
            if (n==1){
                if((zeroVector[i].second >= startingpoint.second && zeroVector[i].second <= endingpoint.second))
                {
                    return 0;
                }
            }
            else{
            if((zeroVector[i].first >= startingpoint.first && zeroVector[i].first <= endingpoint.first) && (zeroVector[i].second >= startingpoint.second && zeroVector[i].second <= endingpoint.second) ){
                return 0;
            }
            }

        }
    }
	return 1;
}

int main() {
	std::cin >> n >> m;
	takevectorinput(n, m);
	std::cin >> q;
	while (q--) {
		int a, b, c ,d, totalcost;
		std::cin >> a >> b >> c >> d;
		if (g1[c-1][d-1] == 0) {
		    totalcost = 0;
		}
		else {


            
                totalcost = cheapestpath(std::make_pair(a,b), std::make_pair(c,d));
		}
		std::cout << totalcost << "\n";
	}
	return 0;
}