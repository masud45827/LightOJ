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
int main() {
  int test = 1, fac = 1;
  scanf("%d", &test);
  while (test--) {
      ll n,i,x,y;
      cin>>n>>x;
       n-=x;
       cout<<"Case "<<fac++<<": ";
        if(n<=x) cout<<"impossible"<<endl;
        else{
             vi v;
             for(i=1;i*i<=n;i++){
               if(n%i==0){
                    if(i>x) v.pb(i);
                    if(n/i!=i&&(n/i)>x) v.pb(n/i);
               }
             }
        sort(all(v));
         for(ll x:v) cout<<x<<" ";
          cout<<endl;
      }
  }
  return 0;
}
