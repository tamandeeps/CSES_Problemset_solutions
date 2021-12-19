#include<bits/stdc++.h>
using namespace std;
bool visited[1001][1001];
int n,m;
vector<string> matrix;
set<pair<int,int>> x={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int i, int j)
{
	visited[i][j]=true;
	//cout<<i<<j<<endl;
    for(auto [a,b]:x)
    {
    	int h,k;
    	h=a+i;
    	k=b+j;
    	//cout<<h<<k<<endl;
        //cout<<(matrix[h][k]!='#');
        if(h>=0&&h<n&&k<m&&k>=0&&!visited[h][k]&&matrix[h][k]!='#')
        	dfs(h,k);
    }
}
int main()
{
	cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	string s;
    	cin>>s;
        matrix.push_back(s);
    }
   // for(auto i: matrix)
    //	cout<<i<<endl;
    int count=0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		//cout<<matrix[i][j];
    		if(matrix[i][j]=='#')
    			{
    				//cout<<"yes";
    			continue;
    			}
    		if(!visited[i][j])
    		{
    			count++;
    			dfs(i,j);
    		}
    	}
    }
    cout<<count;
	return 0;
}