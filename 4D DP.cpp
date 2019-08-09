//Problem link - https://codeforces.com/contest/1199/problem/F
//Solution link - https://codeforces.com/contest/1199/submission/58044554

int n;
int dp[52][52][52][52];
string s[52];
 
int calc(int a, int b, int c, int d)
{
	if(a == b and c == d)
	{
		if(s[c][a] == '#') return 1;
		else return 0;
	}
	
	if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
	
	int ans = max((b-a),(d-c)) + 1;
	
  //divide the current rectange in 2 smaller rectangles in all possible ways, horizontally and vertically
  
	for(int i=a;(i+1)<=b;i++)
	{
		ans = min(ans , calc(a,i,c,d) + calc(i+1,b,c,d) );
	}
	
	for(int i=c;(i+1)<=d;i++)
	{
		ans = min(ans , calc(a,b,c,i) + calc(a,b,i+1,d) );
	}
	
	dp[a][b][c][d] = ans;
	return ans;
}
 
int main()
{
  cin>>n;

  for(int a=0;a<=n;a++)
  {
    for(int b=0;b<=n;b++)
    {
      for(int c=0;c<=n;c++)
      {
        for(int d=0;d<=n;d++)
        {
          dp[a][b][c][d] = -1;
        }
      }
    }
  }

  for(int i=0;i<n;i++) cin>>s[i];

  cout<<calc(0,n-1,0,n-1)<<endl;
}
