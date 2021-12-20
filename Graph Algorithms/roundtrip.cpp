#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxN=1e5+1;
vector<bool> visited(maxN,false);
vector<int> p(maxN,-1);
vector<int> adj[maxN];
bool found=false;
int n;
int m;
int ans,final;
 
void dfs(int u, int par)
{
	if(found)
		return;
  visited[u]=true;
  p[u]=par;
  for(auto v: adj[u])
  {
  	if(v!=par and visited[v])
  	{
       found =true;
       ans=v;
       final=par;
       break;
  	}
  	else
  		if(!visited[v])
  			dfs(v,u);
  }
}
 
 
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
    for(int i=1;i<=n;i++)
    {
    	if(!visited[i])
    		dfs(i,p[i]);
    }
    if(!found)
    	cout<<"IMPOSSIBLE";
    else
    {
        vector<int> res;
        int x=ans;
        while(ans!=final)
        {
            res.pb(ans);
        	ans=p[ans];
        }
        res.pb(x);
        cout<<res.size()<<endl;
        reverse(res.begin(),res.end());
        for(auto i:res)
        	cout<<i<<" ";
    }
	return 0;
}