#include<bits/stdc++.h>
using namespace std;
const  int maxN=1e5+1;
#define pb push_back
int n,m;
vector<int> adj[maxN],indegree;

void topological_sort()
{
	queue<int> q;
 for(int i=1;i<=n;i++)
 {
 	if(indegree[i]==0)
 		q.push(i);
 }
 vector<int> ans;
 while(!q.empty())
 {
 	int u=q.front();
 	q.pop();
    ans.push_back(u);
 	for(auto v:adj[u])
 	{
 		indegree[v]--;
 		if(indegree[v]==0)
 			q.push(v);
 	}
 }
 if(ans.size()==n)
 {
 	for(auto i:ans)
 		cout<<i<<" ";

 }
 else
 {
 	cout<<"IMPOSSIBLE";
 }
}



int main()
{
	cin>>n>>m;
	indegree.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
	//	adj[v].pb(u);
		indegree[v]++;
	}
	topological_sort();
	return 0;
}