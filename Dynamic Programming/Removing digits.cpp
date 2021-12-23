#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
 
int main()
{
	int x;
	cin>>x;
	vector<int> dp(x+1,0);
	dp[0]=0;
	for(int i=1;i<=9;i++)
		dp[i]=1;
	for(int i=10;i<=x;i++)
	{
       int num=i;
       while(num>0)
       {
       	int rem=num%10;
       	num/=10;
       	if(rem == 0)
       		continue;
       	if(dp[i]==0)
       	dp[i]=1+dp[i-rem];
       else
       	dp[i]=min(dp[i],1+dp[i-rem]);
       }
	}
	cout<<dp[x];
	return