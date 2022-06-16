//range  minimum value query
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
ll g[200005][20];
int a[200004];
ll g1[200005][20];
int query1(int l, int r)
{
  int  p=log2(r-l+1);
  return max(g[l][p],g[r-(1<<p)+1][p]);
}
void fun(int n)
{
  int i,j;
  for(j=1;j<=20;j++)
  {
    for(i=1;(i+(1<<j)-1)<=n;i++)
    {
       g[i][j]=max(g[i][j-1],g[i+(1<<(j-1))][j-1]);
    }
  }
}
int query2(int l, int r)
{
  int  p=log2(r-l+1);
  return min(g1[l][p],g1[r-(1<<p)+1][p]);
}
void fun1(int n)
{
  int i,j;
  for(j=1;j<=20;j++)
  {
    for(i=1;(i+(1<<j)-1)<=n;i++)
    {
       g1[i][j]=min(g1[i][j-1],g1[i+(1<<(j-1))][j-1]);
    }
  }
}
int main()
{
   int t = 1, fac = 1;
     scanf("%d", &t);
   while (t--)
   {
     int n,i,j,x,y,k;
     cin>>n>>k;
     for(i=1;i<=n;i++) 
      {
        cin>>a[i]; 
        g[i][0]=a[i];
        g1[i][0]=a[i];
      }
      fun(n);
      fun1(n);
      int mx=0;
      for(i=k;i<=n;i++){
      	 x=query1(i-k+1,i);
      	  y=query2(i-k+1,i);
      	  mx=max(mx,x-y);
      }
      cout<<"Case "<<fac++<<": ";
      cout<<mx<<endl;

   }

}
