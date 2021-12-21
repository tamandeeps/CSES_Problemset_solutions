include<bits/stdc++.h>
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
   
	return 0;
}