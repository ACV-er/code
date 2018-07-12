#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const LL INF = 1E9+9;

const int maxn = 100006;
const int LOG = 20;

struct node
{
    int l,r;
    int sum;
}Node[maxn*LOG];
int root[maxn],node_cnt;
int numbers[maxn],num_cnt;
int a[maxn];

void build(int l,int r,int &rt)
{
    rt=++node_cnt;
    Node[rt].l=Node[rt].r=Node[rt].sum=0;
    if(l==r)
        return ;
    int m=(l+r)>>1;
    build(l,m,Node[rt].l);
    build(m+1,r,Node[rt].r);
}
void update(int v,int l,int r,int &rt,int pre)
{
    rt=++node_cnt;
    Node[rt]=Node[pre];
    ++Node[rt].sum;
    if(l==r)
        return ;
    int m=(l+r)>>1;
    if(v<=m)
        update(v,l,m,Node[rt].l,Node[pre].l);
    else
        update(v,m+1,r,Node[rt].r,Node[pre].r);
}
int query(int k,int l,int r,int r1,int r2)
{
    if(l==r)
        return r;
    int lnum=Node[Node[r2].l].sum-Node[Node[r1].l].sum;
    int m=(l+r)>>1;
    if(k<=lnum)
        return query(k,l,m,Node[r1].l,Node[r2].l);
    else
        return query(k-lnum,m+1,r,Node[r1].r,Node[r2].r);
}

int main()
{
//  ios::sync_with_stdio(false);
    int n,m;
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
    //      cin>>a[i];
            numbers[i]=a[i];
        }
        sort(numbers+1,numbers+n+1);
        num_cnt=unique(numbers+1,numbers+n+1)-numbers-1;
        node_cnt=0;
        root[0]=0;
        build(1,num_cnt,root[0]);
        for(int i=1;i<=n;i++)
        {
            int pos = lower_bound(numbers+1,numbers+num_cnt+1,a[i])-numbers;
            update(pos,1,num_cnt,root[i],root[i-1]);
        }
        while(m--)
        {
            int L,R,K;
            cin>>L>>R>>K;
            int q=query(K,1,num_cnt,root[L-1],root[R]);
            printf("%d\n",numbers[q]);
        //  cout<<numbers[q]<<'\n';
        }
    }
    return 0;
}
