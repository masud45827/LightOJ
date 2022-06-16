#include <bits/stdc++.h>
using namespace std;
int tree[4*100005];
void invert_range(int node, int b, int e, int l, int r){
    if(b==l && e==r){
        if(tree[node]==0) tree[node]=1;
        else tree[node]=0;
        return;
    }
    int mid = (b+e)/2;
    if(r<=mid)
        invert_range(2*node, b, mid, l, r);
    else if(mid<l)
        invert_range(2*node+1, mid+1, e, l, r);
    else{
        invert_range(2*node, b, mid, l, mid);
        invert_range(2*node+1, mid+1, e, mid+1, r);
    }
}

int query(int node, int l, int r, int pos){

    if(r==pos and l==pos){
        return tree[node];
    }

    if(tree[node]){
        tree[node*2]= !tree[node*2];
        tree[node*2+1]= !tree[node*2+1];
        tree[node]=0;
    }

    int mid = (l+r)/2;
    if(pos<=mid){
        return  query(node*2, l, mid, pos);
    }
    else{
        return  query(node*2+1, mid+1, r, pos);
    }
}

int main(){
    int t, test = 1;
    cin>>t;
     while(t--) {
        printf("Case %d:\n", test++);
        memset(tree, 0, sizeof(tree));
        string str;
        cin >> str;
        int len = str.size();
        for (int i = 0; i < len; i++){
            if(str[i]=='1'){
                invert_range(1,1,len,i+1,i+1);
            }
        }

        int q,l,r,in;
        cin >> q;
        while(q--){
            char ch;
            cin >> ch;
                  if(ch=='I'){
                    cin >> l;
                    cin >> r;
                    invert_range(1, 1, len, l, r);
                }else{
                    cin >> in;
                    printf("%d\n", (query(1,1,len,in)));
                }
            }
        }
    return 0;
}
