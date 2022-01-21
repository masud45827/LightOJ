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
vl pr;
map<ll, ll>tm1;
void fact(ll n) {
  if (n % 2 == 0) {
    pr.pb(2);
    while (n % 2 == 0) {
      tm1[2]++;
      n /= 2;
    }
  }
  for (ll p = 3; p * p <= n; p += 2) {
    if (n % p == 0) {
      pr.pb(p);
      while (n % p == 0) {
        n /= p;
        tm1[p]++;
      }
    }
  }
  if (n != 1) {
    if (!tm1[n]) {
      pr.pb(n);
      tm1[n]++;
    }
  }
}
ll bigmod ( ll a, ll p )
{
    ll res = 1;
    ll x = a;

    while ( p )
    {
        if ( p & 1 )
        {
            res = ( res * x ) % mod;
        }
        x = ( x * x ) % mod;
        p = p >> 1;
    }

    return res;
}
int main() {
  int test = 1, fac = 1;
  scanf("%d", &test);
  while (test--) {
    ll n, i, m, j, x, y;
    pr.clear(); tm1.clear();
    cin >> n >> m;
    fact(n);
    for(int x:pr){
       tm1[x]*=m;
         //error(x,tm1[x]);
    }
    ll ans=1;
    for(int p:pr){
      x=bigmod(p,tm1[p]+1);
      error(x);
       x--;
        if(x<0) x+=mod;
        ll d=bigmod(p-1,mod-2);
        x*=d;
        ans=((ans%mod)*(x%mod))%mod;
    }
    cout<<"Case "<<fac++<<": "<<ans<<endl;
  }
  return 0;
}

