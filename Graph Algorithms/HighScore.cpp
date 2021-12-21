#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
const int INF = 1e17;
const int NINF = INF*(-1);

struct triplet
 {
    int u;
    int v;
    int wt;
 };
 
 int n,m;
 vector<triplet> edges;
 vector<int> d;

 

 void bellmanFord()
 {
  d[1]=0;
  for(int i=0;i<n-1;i++)
  {
   for(auto e:edges)
   {
       int u=e.u;
       int v=e.v;
       int wt=e.wt;
       if(d[u]==INF)
        continue;
    d[v]=min(d[v],d[u]+wt);
    d[v]=max(d[v],NINF);
   }  
}
for(int i=0;i<n-1;i++)
{
    for(auto e: edges)
    {
        int u=e.u;
        int v=e.v;
        int wt=e.wt;
        if(d[u]==INF)
            continue;
        d[v]=max(d[v],NINF);
        if(d[v]>d[u]+wt)
            d[v]=NINF;
    }
}

 }

int32_t main()
{
 cin>>n>>m;
  edges.resize(m);
  d.resize(n+1,INF);
  for(int i=0;i<m;i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    z=-1*z;
    edges[i].u=x;
    edges[i].v=y;
    edges[i].wt=z;
  }
  bellmanFord(); 
  int maximum=0;
  if(d[n]==NINF)
    {
        cout<<"-1";
        return 0;
    }
   
  
  cout<<-1*d[n];

}