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
  int t = 1, fac = 1;
  cin >> t;
  while (t--)
  {
      int n,m,i,j,x,y,u,v,k;
      cin>>n>>m;
      int dis[n+2][n+2];
      for(i=0;i<n;i++){
        for(j=0;j<n;j++) {
          dis[i][j]=1e9;
        }
      }
      for(i=0;i<n;i++) dis[i][i]=0;
      for(u=1;u<=m;u++)
      {
         cin>>x>>y;
         dis[x][y]=1;
         dis[y][x]=1;
      }
     for(int mid=0;mid<n;mid++) 
      {
        for(u=0;u<n;u++)
        {
            for(v=0;v<n;v++)
            {
                 dis[u][v]=min(dis[u][v],dis[u][mid]+dis[mid][v]);
            }
        }
      }
      cin>>x>>y;
         int mx=0;
       for(i=0;i<n;i++){
           if(dis[x][i]==1e9||dis[i][y]==1e9) continue;
           mx=max(mx,dis[x][i]+dis[i][y]);
       }
     printf("Case %d: %d\n",fac,mx);
     fac++;
    
  }
}
