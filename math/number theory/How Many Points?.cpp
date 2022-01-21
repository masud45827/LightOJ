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
   ll n,k,i,j,x,y,a1,a2,b1,b2;
   cin>>a1>>b1>>a2>>b2;
    x=abs(a1-a2); y=abs(b1-b2);
    cout<<"Case "<<fac++<<": ";
    if(x==0&&y==0) cout<<"1"<<endl;
    else if(x==0) cout<<(y+1)<<endl;
    else if(y==0) cout<<(x+1)<<endl;
    else cout<<__gcd(x,y)+1<<endl;
  }
  return 0;
}

