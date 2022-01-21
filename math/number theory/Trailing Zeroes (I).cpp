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
vi pr;
int N=1e6+4;
void fun(){
  vector<int>ck(N+2,0);
  int i,j;
  for(i=2;i<=N;i+=2) ck[i]=1;
    for(i=3;i*i<=N;i+=2){
        if(!ck[i]){
           for(j=i*i;j<=N;j+=(2*i)) ck[j]=1;
        }
    }
    pr.pb(2);
    for(i=3;i<=N;i++){
       if(!ck[i]) pr.pb(i);
    }
}
int main() {
  int test = 1, fac = 1;
  fun();
  scanf("%d", &test);
  while (test--) {
    ll n,i,x,y,num=1;
     cin>>n;
     int sz=pr.size();
      for(i=0;i<sz&&pr[i]*pr[i]<=n;i++){
        int res=0;
         while(n%pr[i]==0){
           res++;
            n/=pr[i];
         }
         num*=(res+1);
      }
      if(n!=1) num*=2;
      cout<<"Case "<<fac++<<": ";
      cout<<num-1<<endl;
  
  }
  return 0;
}

