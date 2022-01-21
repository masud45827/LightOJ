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
ll m=1000003;
ll bigmod ( ll a, ll p )
{
    ll res = 1;
    ll x = a;

    while ( p )
    {
        if ( p & 1 )
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res;
}
ll fact[1000004],infact[1000004];
int main() {
  int test = 1, fac = 1;
   fact[1]=1;
    fact[0]=1; infact[0]=1;
    infact[1]=1;
  for(int i=2;i<=1000000;i++){
    fact[i]=(fact[i-1]*i)%m;
    infact[i]=bigmod(fact[i],m-2);
  }
  scanf("%d", &test);
  while (test--) {
      ll n,i,k,j,x,y;
      cin>>n>>k;
       error(fact[n],infact[n-k],infact[k]);
      x=(fact[n]*infact[n-k])%m;
      x=(x*infact[k])%m;
      cout<<"Case "<<fac++<<": ";
      cout<<x<<endl;

  }
  return 0;
}

