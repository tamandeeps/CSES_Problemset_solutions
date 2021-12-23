#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main()
{
	int n;
	cin>>n;
	vector<int> dp(n+1,0);
	dp[1]=1;
	dp[0]=1;
	for(int i=2;i<=n;i++)
	{
       for(int j=1;j<=6;j++)
       {
          if(i-j<0)
          	continue;
          dp[i]+=dp[i-j];
          dp[i]%=mod;
       }
	}
	cout<<dp[n];
	return 0;
}