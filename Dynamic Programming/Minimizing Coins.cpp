#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main()
{
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> dp(x+1,-1);
	dp[0]=0;
	for(int i=1;i<=x;i++)
	{
		for(auto j:a)
		{
			if(i-j<0 or dp[i-j]==-1)
				continue;
			if(dp[i]==-1)
				dp[i]=1+dp[i-j];
			else
				dp[i]=min(1+dp[i-j],dp[i]);
		}
	}
	cout<<dp[x];
	
	return 0;
}