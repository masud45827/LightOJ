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
ll fun1(ll n, ll x) {
    n = n * 10 + x;
    return n;
}
int main() {
    int test = 1, fac = 1;
    scanf("%d", &test);
    while (test--) {
        string s;
        ll sz, i, j, x, y, n, d;
        cin >> s >> d;
        n = s.size();
        d=abs(d);
        i = 0;
        if (s[i] == '-') i++;
        x = 0;
        if (s[i] == '0' && i == n - 1) {
            cout << "Case " << fac++ << ": ";
             cout << "divisible" << endl;
            continue;
        }
        while (i < n) {
            while (i < n && x < d) {
                x = fun1(x, s[i] - '0');
                //error(x);
                i++;
            }
          //  error(x);
            x=x%d;
           // error(x);
        }
        //error(x);
        cout << "Case " << fac++ << ": ";
        if (x != 0) cout << "not divisible" << endl;
        else cout << "divisible" << endl;

    }
    return 0;
}

