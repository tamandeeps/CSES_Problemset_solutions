#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
const int mod=1e9+7;
const int maxN=1e5+1;
const int INF=1e17;
vector<pair<int,int>> adj[maxN];
vector<long long > d(maxN,INF),routes(maxN,0),min_f(maxN,0),max_f(maxN,0);
int n,m;

void ModifiedDijiktsra()
{
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
d[1]=0;
pq.push({d[1],1});
routes[1]=1;
while(!pq.empty())
{
	int u=pq.top().second;
	int dist=pq.top().first;
	pq.pop();
	for(auto j:adj[u])
	{
      int v=j.first;
      int c=j.second;
      if(d[v]<c+dist)
      	continue;
      if(d[v]==c+dist)
      {
      	routes[v]+=routes[u];
      	routes[v]%=mod;
        min_f[v]=min(min_f[u]+1,min_f[v]);
        max_f[v]=max(max_f[u]+1,max_f[v]);
      }
      if(d[v]>c+dist)
       {
       	d[v]=c+dist;
       	routes[v]=routes[u];
       	min_f[v]=min_f[u]+1;
       	max_f[v]=max_f[u]+1;
       	pq.push({d[v],v});
       }

	}
}
}


int32_t main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		adj[x].pb({y,z});
	}
	ModifiedDijiktsra();
	cout<<d[n]<<" "<<routes[n]<<" "<<min_f[n]<<" "<<max_f[n];

	return 0;
}