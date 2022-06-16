#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
//typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#ifdef LOCAL
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ' ;
	err(++it, args...);
}
#else
#define error(args...)
#endif
int cn = 1, sz;
map<ll, ll> mp;
map<ll, ll>::iterator it;
ll dp[100006],bit[100005];
ll query(ll i) {
     ll ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}
void update(ll i, ll x, ll n) {
    while (i <= n) {
        bit[i] += x;
        i+=(i&(-i));
    }
}
int main() {
	int test = 1, fac = 1;
	scanf("%d", &test);
	while (test--) {
		ll n, i, x, y;
		cin >> n;
		ll a[n + 2];
		mem(bit);
		 mem(dp);
		mp.clear();
		for (i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		ll cn = 1;
		for (it = mp.begin(); it != mp.end(); it++) {
			it->second = cn++;
		}
		sz = cn - 1;
		for (i = 0; i < n; i++) {
			a[i] = mp[a[i]];
		}
		ll ans=0,res=0;
		for(i=0;i<n;i++){
			ans=query(a[i]-1)+1;
			//error(ans);
			 ans%=mod;
			 res+=ans;
			  res%=mod;
			update(a[i],ans,n);
		}
		cout<<"Case "<<fac++<<": "<<res<<endl;
	}
	return 0;
}

