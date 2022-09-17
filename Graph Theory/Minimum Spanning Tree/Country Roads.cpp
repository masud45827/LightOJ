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
vector<int>g[505], cost[505];
int dis[505];
int n;
void bfs(int u)
{
    queue<int>q;
    q.push(u);
    dis[u]=0;
    int mn;
    while(q.size())
    {
       int p=q.front();
       q.pop();
       for(int i=0;i<g[p].size();i++)
       {
         int x=g[p][i];
            mn=max(dis[p],cost[p][i]);
            if(mn<dis[x]) 
            {
               dis[x]=mn;
               q.push(x);
            }
       }
    }
    
}
int main()
{
   int t = 1, fac = 1;
   scanf("%d", &t);
   while (t--)
   {
      int  i, x, y, u, v, w, m, mn;
      cin >> n >> m;
      for (i = 0; i <= n; i++)
      {
         g[i].clear();
         cost[i].clear();
         dis[i]=1e9;
      }
      for (i = 0; i < m; i++) {
         scanf("%d %d %d", &u, &v, &w);
         g[u].pb(v);
         g[v].pb(u);
         cost[u].pb(w);
         cost[v].pb(w);
      }
      cin >> u;
      bfs(u);
      printf("Case %d:\n", fac);
      for (i = 0; i < n; i++)
      {
         if (dis[i] != 1e9) printf("%d\n", dis[i]);
         else printf("Impossible\n");
      }
      fac++;
   }
   return 0;
}
