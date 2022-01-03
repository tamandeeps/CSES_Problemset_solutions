#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
int dp[1001][1001];

void solve()
{
	int n;
	cin>>n;
	dp[1][1]=3;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
           dp[i][i]+=(dp[i][j]+3)%mod;
		}
	}
	cout<<dp[n][n];
}

int main()
{
	//solve();
	int t;
	cin>>t;
	while(t>0)
	{
		solve();
		cout<<endl;
		t--;
	}
return 0;
}