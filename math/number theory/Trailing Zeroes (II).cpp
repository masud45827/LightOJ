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
map<ll,ll>mp;
ll fun(ll n,ll x) {
    ll ans = 0;
    for (ll i = x; i <= n; i *= x) {
        ans += (n / i);
    }
    return ans;
}
ll fun1(ll n,ll x){
    ll ans=0;
    while(n%x==0){
        ans++; n/=x;
    }
    return ans;
}
int main() {
    int test = 1, fac = 1;
    scanf("%d", &test);
    while (test--) {
        ll n,i,x,y,r,p,q,ans=0,c=0,tw=0,fv=0;
        cin>>n>>r>>p>>q;
         tw+=fun(n,2LL);
          fv+=fun(n,5LL);
          tw-=fun(n-r,2LL); tw-=fun(r,2LL);
           fv-=fun(n-r,5LL); fv-=fun(r,5LL);
            tw+=(fun1(p,2LL)*q);
            fv+=(fun1(p,5LL)*q);
            ans=min(fv,tw);
        cout<<"Case "<<fac++<<": ";
         cout<<ans<<endl;
        
    }
    return 0;
}

