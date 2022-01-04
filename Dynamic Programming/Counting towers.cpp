#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
int dp[1001][1001];

void solve()
{
	int n;
	cin>>n;
	int dp[2][n+1];
	dp[0][1]=1;
	dp[1][1]=3;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[0][i]=dp[0][j]%mod;
			dp[1][i]
		}
	}

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