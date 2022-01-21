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
int a[1000004];
int main() {
    int test = 1, fac = 1;
    scanf("%d", &test);
    int n = 100000, i, j;
    for (i = 4; i <= n; i += 2) a[i] = 1;
    for (i = 3; i * i <= n; i += 2) {
        if (!a[i]) {
            for (j = i * i; j <= n; j += (2 * i)) {
                a[j] = 1;
            }
        }
    }
    vi v;
    v.pb(2);
    for (i = 3; i <= n; i += 2) {
        if (!a[i]) {
            v.pb(i);
        }
    }
    while (test--) {
        ll x,y,l;
        cin>>x>>y;
        if(x==1) x++;
        int sz=v.size();
        int dp[100005];
        mem(dp);
        for(i=0;i<sz&&v[i]*v[i]<=y;i++){
            int p=v[i];
             j=p*p;
             if(j<x)  {
                j=(x+p-1)/p;
                 j*=p;
            }
             for(;j<=y;j+=p){
                 dp[j-x]=1;
             }
        }
        int ans=0;
        cout<<"Case "<<fac++<<": ";
        for(i=x;i<=y;i++){
           if(dp[i-x]==0) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

