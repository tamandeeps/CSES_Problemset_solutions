#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxN=1e5+1;
const int mod=1e9+7;
vector<int> adj[maxN],indegree;
vector<int> cnt;

void ModifiedTopoSort()
{
	queue<int> q;
for(int i=2;i<=n;i++)
{
	if(indegree[i]==0)
		q.push(i);
}
while(!q.empty())
{
	int u=q.front();
	q.pop();
    for(auto v:adj[u])
    {
    	indegree[v]--;
    	if(indegree[v]==0 and v!=1)
    		q.push(v);
    }

}
q.push(1);
cnt[1]=1;
while(!q.empty())
{
	int u=q.front();
	q.pop();
	for(auto v:adj[u])
	{
		cnt[v]=cnt[u]+cnt[v];
		cnt[v]%=mod;
		indegree[v]--;
		if(indegree[v]==0)
			q.push(v);
	}
}
cout<<cnt[n];
}

int main()
{
	cin>>n>>m;
	indegree.resize(n+1);
	cnt.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	ModifiedTopoSort();
	return 0;
}