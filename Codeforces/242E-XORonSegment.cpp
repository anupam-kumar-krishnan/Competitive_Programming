#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100005;
 
ll stree[4*MAXN][32], lazy[4*MAXN], a[MAXN], n, q;
 
void mergeFilhos(ll node){
	for(int i=0; i<32; i++)
		stree[node][i] = stree[2*node][i] + stree[2*node+1][i];
}
 
void propaga(ll node, ll left, ll right){
 
	if(lazy[node]){
 
		if(left != right){
			lazy[2*node] ^= lazy[node];
			lazy[2*node+1] ^= lazy[node];
		}
 
		for(int i=0; i<32; i++){	
			if((lazy[node] >> i) & 1)
				stree[node][i] = (right - left + 1) - stree[node][i];
		}

		lazy[node] = 0;
	}
}
 
void build(ll node, ll left, ll right){
 
	if (left == right){
		
		ll num = a[left];
		for(int i=0; i<32; i++){
			if((num >> i) & 1)
				stree[node][i]++;		
		}

	} else if (left < right){
 
		ll mid = (right + left) / 2;
 
		build(2*node, left, mid);
		build(2*node+1, mid+1, right);
 
		mergeFilhos(node);	
	}
}
 
void update(ll node, ll left, ll right, ll A, ll B, ll value){
 
	propaga(node, left, right);
	
	if(left >= A && right <= B){
		
		if (left != right){
			lazy[2*node] ^= value;
			lazy[2*node+1] ^= value;
		}
 
		for(int i=0; i<32; i++){
			if((value >> i)& 1)
				stree[node][i] = (right - left + 1) - stree[node][i];
		}
 
	}else if (left <= B && right >= A){
		ll mid = (right + left) / 2;
 
		update(2*node, left, mid, A, B, value);
		update(2*node+1, mid+1, right, A, B, value);
 
		mergeFilhos(node);
	}
}
 
ll getSum(ll node, ll left, ll right, ll A, ll B){
	
	propaga(node, left, right);
 
	if (right < A || left > B)
		return 0;
	if (left >= A && right <= B){
		
		ll sumNode = 0;
		ll aux = 1;
		for(int i=0; i<32;i++){
			sumNode += stree[node][i] * (aux << i);
		}
 
		return sumNode;
	}
 
	ll mid = (right + left) / 2;
 
	ll p1 = getSum(2*node, left, mid, A, B);
	ll p2 = getSum(2*node+1, mid+1, right, A, B);
 
	return p1 + p2;	
}
 
void solve(){
	ll type, A, B, value;
	cin >> type >> A >> B;
 
	if (type == 1){
		cout << getSum(1, 1, n, A, B) << endl;
	} else{
		cin >> value;
		update(1, 1, n, A, B, value);
	}
}
 
int main(){
	memset(lazy, 0, sizeof(lazy));
	cin >> n;
	for(ll i=1; i<=n; i++)
		cin >> a[i];
	build(1, 1, n);
	cin >> q;
	while(q--) solve();
	return 0;
}