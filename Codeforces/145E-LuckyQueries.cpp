#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000005;
 
struct No{
	int n4, n7, n47, n74;
};
 
int lazy[4*MAXN], n, m;
No stree[4*MAXN];
string s;
 
void merge(int node){
 
	stree[node].n4 = stree[2*node].n4 + stree[2*node+1].n4;
	stree[node].n7 = stree[2*node].n7 + stree[2*node+1].n7;
	stree[node].n47 = max(stree[2*node].n47 + stree[2*node+1].n7, max(stree[2*node].n4 + stree[2*node+1].n7, stree[2*node].n4 + stree[2*node+1].n47));
	stree[node].n74 = max(stree[2*node].n74 + stree[2*node+1].n4, max(stree[2*node].n7 + stree[2*node+1].n4, stree[2*node].n7 + stree[2*node+1].n74));

}
 
void propaga(int node, int left, int right){
 
	if (lazy[node]){
 
		swap(stree[node].n4, stree[node].n7);
		swap(stree[node].n47, stree[node].n74);
 
		if (left != right){
			lazy[2*node] = abs(lazy[2*node] - 1);
			lazy[2*node+1] = abs(lazy[2*node+1] - 1);
		}
 
		lazy[node] = abs(lazy[node] - 1);
	}
 
}
 
void build(int node, int left, int right){
 
	if (left == right){	

		stree[node].n47 = 1;
		stree[node].n74 = 1;
 
		if (s[left] == '4')
			stree[node].n4 = 1;			
		else
			stree[node].n7 = 1;
		
	} else if (left < right){
		int mid = (right + left) / 2;
		build(2*node, left, mid);
		build(2*node+1, mid+1, right);
		merge(node);	
	}
}
 
void update(int node, int left, int right, int A, int B){
 
	propaga(node, left, right);
	
	if(left >= A && right <= B){
		
		swap(stree[node].n4, stree[node].n7);
		swap(stree[node].n47, stree[node].n74);
 
		if (left != right){
			lazy[2*node] = abs(lazy[2*node] - 1);
			lazy[2*node+1] = abs(lazy[2*node+1] - 1);
		}
	
 
	}else if (left <= B && right >= A){
		int mid = (right + left) / 2;
		update(2*node, left, mid, A, B);
		update(2*node+1, mid+1, right, A, B);
		merge(node);
	}
}
 
void solve(){
	string type;
	cin >> type;
 
	if (type == "count"){
		cout << stree[1].n47 << endl;
	} else{
		int A, B;
		cin >> A >> B;
		A--; B--;
		update(1, 0, n-1, A, B);
	}
}
 
int main(){
	cin >> n >> m >> s;
	build(1, 0, n-1);
	while(m--) solve();
	return 0;
}