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
int main()
{
  int test = 1, fac = 1;
  scanf("%d", &test);
  while (test--)
  {
    ll n;
     string s;
     cin>>n>>s;
     cout<<"Case "<<fac<<": ";
     fac++;
     if(s=="Alice")
     {
       if(n%3!=1) cout<<"Alice"<<endl;
       else cout<<"Bob"<<endl;
     }else
     {
      if(n%3!=0) cout<<"Bob"<<endl;
      else cout<<"Alice"<<endl;
     }

  }

}
