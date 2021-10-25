#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll SIZE = 26;
 
struct node{
	ll count;
	node* ar[SIZE];
};
 
node* getNode()
{
	node* n = new node;
	n->count=0;
 
	for(ll i=0;i<SIZE;i++)
	n->ar[i] = NULL;
 
	return n;
}
 
void insert(node *root , string st)
{
	node *tempRoot = root;
 
	for(ll i=0;i<st.size();i++)
	{
		ll index = st[i] - 'a';
 
		if(tempRoot->ar[index] == NULL)
		tempRoot->ar[index] = getNode();
 
		tempRoot = tempRoot->ar[index];
		tempRoot->count++;
	}
 
// 	tempRoot->endOfWord = true;
}
 
ll search(node *root , string st)
{
	node *tempRoot = root;
 
	for(ll i=0;i<st.size();i++)
	{
		ll index = st[i] - 'a';
 
		if(tempRoot->ar[index] == NULL)
		return 0;
 
		tempRoot = tempRoot->ar[index];
	}
 
	return tempRoot->count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node* root=getNode();

    ll n,q;
    cin>>n>>q;
    while(n--)
    {
        string s;
        cin>>s;
        insert(root,s);
    }
    while(q--)
    {
        string s;
        cin>>s;
        cout<<search(root,s)<<'\n';
    }
    return 0;
}