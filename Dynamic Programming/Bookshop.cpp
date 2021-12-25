#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main()
{
	
	int n,x;
	cin>>n>>x;
	vector<int> h(n),s(n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		cin>>h[i];
	int c=0;
	vector<vector<int>> dp(n,vector<int> (x+1,0));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			c++;
			if(j==0)
			{
				dp[i][j]=0;
				continue;
			}
			if(i>0 and j>=s[i])
			{
				dp[i][j]=max(dp[i-1][j],h[i]+dp[i-1][j-s[i]]);
			//	cout<<dp[i][j]<<endl;
			}
			else
				if(i==0  and j>=s[0])
					dp[0][j]=h[0];

		}
	}
	cout<<dp[n-1][x];
	return 0;
}