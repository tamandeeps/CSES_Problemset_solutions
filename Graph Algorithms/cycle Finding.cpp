#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxN=1e5+1;
const int INF=1e9;
int n;
int m;
bool iscycle=false;
vector<int> p;

 struct triplet 
 {
    int u;
     int v;
     int dist;
 };

 vector<triplet> edges;
 vector<int> d;

void bellmanFord()
{
 d[1]=0;
 p.resize(n+1,-1);
 for(int i=0;i<n-1;i++)
 {
    for(auto e:edges)
    {
        int u=e.u;
        int v=e.v;
        int dist=e.dist;
        if(d[u]==INF)
            continue;
       if(d[v]>d[u]+dist)
        {
            d[v]=d[u]+dist;
        }
    }
 }
 int vertex;
  for(auto e:edges)
    {
        int u=e.u;
        int v=e.v;
        int dist=e.dist;
        if(d[u]==INF)
            continue;
        
        if(d[v]>d[u]+dist)
        {
            iscycle=true;
            vertex=v;
        }

    }
    if(iscycle)
    {
        cout<<"YES"<<endl;
        vector<int> path;
        path.pb(vertex);
        int i=p[vertex];
        while(i!=vertex)
        {
            path.pb(i);
            i=p[i];
        }
        path.pb(vertex);
        reverse(path.begin(),path.end());
        for(auto i:path)
            cout<<i<<" ";
    }
    else
        cout<<"NO";

}

 
 
int main()
{
    cin>>n>>m;
    edges.resize(m);
    d.resize(n+1,INF);
    for(int i=0;i<m;i++)
    {
    	int x,y,z;
    	cin>>x>>y>>z;
        edges[i].u=x;
        edges[i].v=y;
        edges[i].dist=z;
    	
    }
    bellmanFord();
   
	return 0;
}