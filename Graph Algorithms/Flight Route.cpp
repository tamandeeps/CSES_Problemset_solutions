#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int

const int INF=9e15;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> d;
int n,m,k;

void dijiktsra()
{
priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> p;
//d[1].resize(k,0);
p.push({0,1});
d[1][0]=0;
while(!p.empty())
{
    int u=p.top().second;
    int dist=p.top().first;
 p.pop();
        if(d[u][k-1] < dist) continue;
  //  cout<<"DEBUG";
   
    for(auto e:adj[u])
    {
        int v=e.first;
        int cost=e.second;
        if(d[v][k-1]>cost+dist)
        {
            d[v][k-1]=cost+dist;
            p.push({d[v][k-1],v});

            sort(d[v].begin(),d[v].end());
        }
    }
}

}

int32_t main()
{
    cin>>n>>m>>k;
    d.resize(n+1);
    adj.resize(n+1);
    for(int i=0;i<m;i++)
    {
    	int x,y,z;
    	cin>>x>>y>>z;
    	adj[x].pb({y,z});
    }
    for(int i=1;i<=n;i++)
    {
        d[i].resize(k,INF);

    }
    dijiktsra();
    for(int i=0;i<k;i++)
    cout<<d[n][i]<<" ";
   
	return 0;
}