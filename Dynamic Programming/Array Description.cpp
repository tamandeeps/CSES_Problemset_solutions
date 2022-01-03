#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+1;
int main()
{
	int n, m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int dp[n+1];
	dp[0]=1;
	int count=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0 and count<=m)
		{
         dp[i+1]=dp[i]*3%mod;
         count++;
		}
		else
		{
			count=0;
            dp[i+1]=dp[i];
		}
	}
	cout<<dp[n];
	return 0;
}