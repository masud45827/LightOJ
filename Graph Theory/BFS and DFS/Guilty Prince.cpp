#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#define setpr(x) cout<<setprecision(x)<<fixed
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
template <typename T> inline void Int(T &a) {
  bool minus = false; a = 0; char ch = getchar();
  while (true) { if (ch == '-' or (ch >= '0' && ch <= '9')) break; ch = getchar(); }
  if (ch == '-') minus = true; else a = ch - '0';
  while (true) { ch = getchar(); if (ch < '0' || ch > '9') break; a = a * 10 + (ch - '0'); }
  if (minus)a *= -1 ;
}
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

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;
const double PI      = (double)acos(-1.0) ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}
int vis[100][100];
char ch[100][100];
int ans=0,m,n;
void dfs(int x,int y){
  //error(x,y);
    if(x+1<=n&&vis[x+1][y]==0){
        ans++;
         vis[x+1][y]=1;
        dfs(x+1,y);
    }
    if(x-1>=1&&vis[x-1][y]==0){
        ans++;
        vis[x-1][y]=1;
        dfs(x-1,y);
    }
    if(y+1<=m&&vis[x][y+1]==0){
        ans++;
        vis[x][y+1]=1;
        dfs(x,y+1);
    }
     if(y-1>=1&&vis[x][y-1]==0){
        ans++;
        vis[x][y-1]=1;
        dfs(x,y-1);
    }
}
int main() {
  IOS;
  int test = 1, fac = 1;
  cin >> test;
  while (test--) {
    mem(vis);
    int i, j, x, y;
    cin >> m >> n;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        cin >> ch[i][j];
        if (ch[i][j] == '@') {
          x = i; y = j;
          vis[x][y] = 1;
        }
        if (ch[i][j] == '#') vis[i][j] = 1;
      }
    }
    ans=1;
    dfs(x,y);
    cout<<"Case "<<fac++<<": "<<ans<<endl;
  }
  return 0;
}

