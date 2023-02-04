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
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
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
struct node{
  node* edge[4];
  int endmark, cntpath;
  node() {
    endmark = cntpath = 0;
    for (int i = 0; i <4; i++) edge[i] = NULL;
  }
}*root;
map<char,int>mp;
int mx = 0, c = 0, n;
void add( string &s)
{
  node *cur = root;
  for (int i = 0; s[i]; i++) {
    int c = mp[s[i]];
    if (cur->edge[c] == NULL) {
      cur->edge[c] = new node();
    }
    cur = cur->edge[c];
    cur->cntpath++;
    int x=(cur->cntpath*(i+1));
    mx=max(x,mx);
  }
  cur->endmark = 1;
}
void dfs(node *cur){
     for(int i=0;i<4;i++){
        if(cur->edge[i]) dfs(cur->edge[i]);
     }
      delete(cur);
}
void fun(){
   dfs(root);
}
int main(){
  IOS;
  int t = 1, cas = 1;
   cin>>t;
  while (t--) {
    mx=0;
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;
    int i, q;
    cin >> n;
    root = new node();
    string s;
    for (i = 0; i < n; i++) {
      cin >> s;
      int x = s.size();
      mx = max(mx, x);
      add(s);
    }
    cout <<"Case "<<cas++<<": "<< mx << endl;
    fun();
  }
  return 0;
}
