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
vector<pi>vt;
int cp(int n) {
    int i, ans = 0;
    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans++;
            if (n / i != i) ans++;
        }
    }
    return ans;
}
void fun() {
    for (int i = 1; i <= 1000; i++) {
        int x = cp(i);
        //error(i,x);
        vt.pb({i, x});
    }
}
bool cmp(pi p1, pi p2) {
    if (p1.S == p2.S) return p1.F > p2.F;
    return p1.S<p2.S;
}
int main() {
    int test = 1, fac = 1;
    fun();
    sort(all(vt), cmp);
    scanf("%d", &test);
    while (test--) {
        int n, i, x, y, sz;
        cin >> n;
         cout<<"Case "<<fac++<<": "<<vt[n-1].F<<endl;
    }
    return 0;
}

