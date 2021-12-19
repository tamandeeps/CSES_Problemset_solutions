#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+1;
int p[maxN],visited[maxN],d[maxN];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	p[i]=-1,visited[i]=false,d[i]=INT_MAX;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    d[1]=1;
    visited[1]=true;
    while(!q.empty())
    {
    	int u=q.front();
    	q.pop();
    	for(auto v:adj[u])
    	{
    		if(!visited[v])
    		{
         if(d[u]+1<d[v])
         	d[v]=d[u]+1;
         p[v]=u;
         visited[v]=true;
         q.push(v);
     }
    	}
 
    }
    if(!visited[n])
    {
    	cout<<"IMPOSSIBLE\n";
    	return 0;
    }
    cout<<d[n]<<endl;
    vector<int> ans;
    int x=n;
    while(x!=1)
    {
      ans.push_back(x);
      x=p[x];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    for(auto i: ans)
    	cout<<i<<" ";
    
	return 0;
}