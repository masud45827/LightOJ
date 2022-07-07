#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long   ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
     int t = 1, fac = 1;
     scanf("%d", &t);
     while (t--) {
          ll n, i, j, x, y, m, s = 0, m1, m2;
          cin >> n >> m;
          s=(n/(2*m));
          s=s*(m*m);
          cout<<"Case "<<fac++<<": "<<s<<endl;
     }
     return 0;
}
