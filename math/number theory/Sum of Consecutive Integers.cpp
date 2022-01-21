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
vector<int>pr;
void fun() {
  int i, j, x, y, n = 10000006;
  vector<int>ck(n + 4, 0);
  for (i = 2; i <= n; i += 2) ck[i] = 1;
  for (i = 3; i * i <= n; i += 2) {
    if (!ck[i]) {
      for (j = i * i; j <= n; j += (2 * i)) {
        ck[j] = 1;
      }
    }
  }
  pr.pb(2);
  for (i = 3; i <= n; i++) {
    if (!ck[i]) pr.pb(i);
  }
}
int main() {
  int test = 1, fac = 1;
  fun();
  scanf("%d", &test);
  while (test--) {
      ll n,i,x,y,ans=1;
      cin>>n;
      while(n%2==0) n/=2;
    for(i=0;i<pr.size()&&pr[i]*pr[i]<=n;i++){
         ll c=0;
         while(n%pr[i]==0){
           c++;
            n/=pr[i];
         }
          c++;
         ans*=c;
    }

     if(n>1) ans*=2;
    cout<<"Case "<<fac++<<": ";
    cout<<ans-1<<endl;
  }
  return 0;
}

