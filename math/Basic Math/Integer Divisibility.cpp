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
    int n,i,j,x,y,d,s=0,c=1;
    cin>>n>>d;
    s=d;
    s%=n;
    while(1)
    {
        if(s==0) break;
        s=(s*10+d)%n;
        c++;
    }
    cout<<"Case "<<fac<<": ";
    fac++;
     cout<<c<<endl;

  }

}
