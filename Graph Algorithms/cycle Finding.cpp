#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int

struct triplet
{
    int u;
    int v;
    int dist;
};

vector<triplet> edges;
vector<int> d,p;
int n,m;

void ModifiedBellmanFord()
{
    int x;
    for(int i=0;i<n;i++)
    {
         x=-1;
        for(auto e:edges)
        {
            int u=e.u;
            int v=e.v;
            int dist=e.dist;
            if(d[u]+dist<d[v])
            {
                d[v]=d[u]+dist;
                p[v]=u;
                x=v;
            }

        }
    }
    if(x==-1)
    {
     cout<<"NO";
     return;
    }
    for(int i=0;i<n-2;i++)
    {
       x=p[x];
    }
    vector<int> cycle;
    for(int v=x; ;v=p[v])
    {
        cycle.pb(v);
        if(v==x and cycle.size()>1)
            break;
    }
    cout<<"YES"<<endl;
    reverse(cycle.begin(),cycle.end());
    for(auto i:cycle)
        cout<<i<<" ";

}

int32_t main()
{
    cin>>n>>m;
    edges.resize(m);
    d.resize(n+1,0);
    p.resize(n+1,-1);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edges[i]={x,y,z};
    }
    ModifiedBellmanFord();
    return 0;
}