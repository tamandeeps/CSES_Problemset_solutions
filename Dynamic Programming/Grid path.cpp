#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main()
{
	int n;
	cin>>n;
	vector<vector<char>> grid(n,vector<char> (n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>grid[i][j];
	vector<vector<int>> dp(n, vector<int> (n,0));
	if(grid[0][0] != '*')
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
            {
            	if(grid[i][j] == '*')
            		continue;
            	if(j-1 <0 and i-1 <0)
            		continue;
            	if(j-1 <0)
            		dp[i][j]=dp[i-1][j];
            	else
            		if(i-1<0)
            			dp[i][j]=dp[i][j-1];
            		else
            			dp[i][j]=dp[i-1][j]+dp[i][j-1];
            	 dp[i][j]%=mod;
            }

	}
	cout<<dp[n-1][n-1];
	return 0;
}