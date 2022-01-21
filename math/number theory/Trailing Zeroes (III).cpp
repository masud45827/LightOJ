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
ll fun(ll n) {
    ll ans = 0;
    for (ll i = 5; i <= n; i *= 5) {
        ans += (n / i);
    }
    return ans;
}
int main() {
    int test = 1, fac = 1;
    scanf("%d", &test);
    while (test--) {
        ll l = 1, r = 1e18, i, j, x, y, mid, f = 0, n, ans;
        cin >> n;
        while (l <= r) {
            mid = (l + r) / 2;
            x = fun(mid);
            if (x >= n) {
                r = mid - 1;
                ans = mid;
                if (x == n) f = 1;
            } else l = mid + 1;
        }
            cout << "Case " << fac++ << ": ";
            if (!f) cout << "impossible" << endl;
            else cout << ans << endl;
    }
        return 0;
    }

