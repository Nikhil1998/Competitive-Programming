//Problem link - https://codeforces.com/contest/1185/problem/G1
//Solution link - https://codeforces.com/contest/1185/submission/56284230

#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

ll dp[1<<15][4];
int n,T;
vector<pair<int,int> > v;

int calc(int mask,int lst,int t)
{
	if(dp[mask][lst] != -1) return dp[mask][lst];
	
	if(t > T) return 0;
	if(t == T) return 1;
	if(mask == ((1<<n) - 1)) return 0;
	
	ll ans = 0;
	
	for(int i=0;i<n;i++)
	{
    //select unselected song if genre is different than last selected song
		if(((mask>>i)&1) == 0 and v[i].ss != lst)
		{
			ans += calc(mask|(1<<i),v[i].ss,t+v[i].ff);
			ans = ans%mod;
		} 
	}
	dp[mask][lst] = ans;
	return ans;
}

int main()
{
  cin>>n>>T;

  memset(dp,-1,sizeof(dp));

  for(int i=0;i<n;i++)
  {
    int ti,gi;
    cin>>ti>>gi;

    v.pb(mp(ti,gi));
  }

  cout<<calc(0,0,0)<<endl;
}
