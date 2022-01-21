#include<bits/stdc++.h>
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
int dp[5000006];
ull ar[5000006];
void fun(){
     int i,j,x,y;
      for(i=2;i<=5000000;i++) dp[i]=i;
        for(i=2;i<=5000000;i++){
            if(dp[i]==i){
                for(j=i;j<=5000000;j+=i) dp[j]-=(dp[j]/i);
            }
        }
        for(i=2;i<=5000000;i++) ar[i]=ull(dp[i])*ull(dp[i])+ar[i-1];
}
int main() {
    int test = 1, fac = 1,i,j; 
    scanf("%d", &test);
    fun();
    while (test--) {
          int a,b,x,y;
         cin>>a>>b;  
         ull ans=ar[b]-ar[a-1];
         cout<<"Case "<<fac++<<": ";
         cout<<ans<<endl;
    }
    return 0;
}
