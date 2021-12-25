#include<bits/stdc++.h>
using namespace std;
//#define int long long int
const int maxN=2e5+1;
const int l=31;
int up[maxN][l];


int main()
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,q;
	cin>>n>>q;
    //up.resize(n+1,vector<int> (l,0));
    for(int i=1;i<=n;i++)
    	cin>>up[i][0];
    for(int j=1;j<l;j++)
    	for(int i=1;i<=n;i++)
    		up[i][j]=up[up[i][j-1]][j-1];

    for(int j=0;j<q;j++)
    {
    	int x,k;
    	cin>>x>>k;
    	for(int i=0;i<l;i++)
    	    if(k &(1<<i))
    	    	x=up[x][i];
    	cout<<x<<endl;
    }
	return 0;
}