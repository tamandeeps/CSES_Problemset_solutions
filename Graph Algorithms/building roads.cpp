#include<bits/stdc++.h>
using namespace std;
int parent[100001],s[100001];
int find(int x)
{
	if(parent[x]<0)
		return x;
	return parent[x]=find(parent[x]);
}
bool merge(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
		return true;
	if(s[a]<s[b])
			swap(a,b);
		parent[b]=a;
		s[a]+=s[b];
		s[b]=s[a];
	
	return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	parent[i]=-1,s[i]=1;
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	bool l=merge(a,b);
    }
    int k=0;
    vector<pair<int,int>> ans;
    for(int i=1;i<n;i++)
    	if(!merge(i,i+1))
    		k++,ans.push_back({i,i+1});
    cout<<k<<endl;
    for(auto p:ans)
    	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}