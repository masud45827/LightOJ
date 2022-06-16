#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
ll tree[3 * 100005];
ll a[3 * 100005];
void  built_tree(ll b, ll e, ll node)
{
  if (b == e)
  {
    tree[node] = a[b];
    return;
  }
  ll left, right, mid;
  mid = (b + e) / 2;
  left = node * 2;
  right = node * 2 + 1;
  built_tree(b, mid, left);
  built_tree(mid + 1, e, right);
  tree[node] = tree[left] + tree[right];
}
void update(ll b, ll e, ll pos, ll value, ll node)
{
  if (pos < b || pos > e) return;
  if (pos <= b && pos >= e)
  {
    tree[node] += value;
    return;
  }
  ll mid, left, right;
  mid = (b + e) / 2;
  left = node * 2;
  right = node * 2 + 1;
  update(b, mid, pos, value, left);
  update(mid + 1, e, pos, value, right);
  tree[node] = tree[left] + tree[right];
}
ll query(ll node, ll b, ll e, ll l, ll r)
{
  if (l > e || r < b) return 0;
  if (l <= b && e<= r) return tree[node];
  ll mid, left, right;
  mid = (b + e) / 2;
  left = node * 2;
  right = node * 2 + 1;
  ll ans1 = query(left, b, mid, l, r);
  ll ans2 = query(right, mid + 1, e, l, r);
  return ans1 + ans2;

}

int main()
{
  int t, l = 1;
  scanf("%d", &t);
  while (t--)
  {
  	memset(a , 0 ,sizeof a);
  	memset(tree , 0 ,sizeof tree);
    ll x, n, i, j, q;
    scanf("%lld %lld", &n, &q);
    for (i = 1; i <= n; i++)  scanf("%d", &a[i]);
    built_tree(1, n, 1);
    printf("Case %d:\n", l);
    l++;
    for (i = 1; i <= q; i++)
    {
      ll pos, value, l, r;

      scanf("%lld", &x);
      if (x == 2)
      {
        scanf("%lld %lld", &pos, &value);
        pos++;
        update(1, n, pos, value, 1);
      }
      if (x == 1)
      {
        scanf("%lld", &pos);
        pos++;
        ll res = query(1, 1, n, pos, pos);
        printf("%lld\n", res);
        update(1, n, pos, -res, 1);
      }

      if (x == 3)
      {
        scanf("%lld %lld", &l, &r);
        l++, r++;
        ll ans = query(1, 1, n, l, r);
        printf("%lld\n", ans);
      }
    }

  }
}
