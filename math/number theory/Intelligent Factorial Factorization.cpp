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
int N=103;
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
map<pi,int>mp;
void fun1(){
   for (int i = 2; i <= 100; i++) {
       int x=i;
       int sz=pr.size();
        for(int j=0;j<sz&&pr[j]*pr[j]<=x;j++){
           int res=0;
           while(x%pr[j]==0){
             res++;
              x/=pr[j];
           }
            mp[{i,pr[j]}]+=res;
        }
        if(x!=1) mp[{i,x}]++;
  }
}
int main() {
  int test = 1, fac = 1;
  fun();
   fun1();
  scanf("%d", &test);
  while (test--) {
      int n,i,j,x,y;
       cin>>n;

        map<int,int>mp1;
        for(i=2;i<=n;i++){
            for(j=0;j<=100;j++){
               if(mp[{i,j}]){
                 mp1[j]+=mp[{i,j}];
               }
            }
        }
       cout<<"Case "<<fac++<<": ";
        cout<<n<<" = ";
        vector<pi>vt;
       for(i=2;i<=100;i++){
         if(mp1[i]) vt.pb({i,mp1[i]});
       }
        for(int i=0;i<vt.size();i++){
           cout<<vt[i].F<<" ("<<vt[i].S<<")";
           if(i!=vt.size()-1) cout<<" * ";
        }
        cout<<endl;

  }
  return 0;
}

