### tarjan

```c++
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int inf=0x3f3f3f3f,N=1e4+5,M=1e5+5;
int h[N],ne[M],to[M],idx;
int dfn[N],low[N],timestamp;
int stk[N],in_stk[N],top;
int id[N],scc_cnt,Size[N];
int dout[N];
void add(int x,int y){
    to[idx]=y;ne[idx]=h[x];h[x]=idx++;
}
void tarjan(int x){
    dfn[x]=low[x]=++timestamp;
    stk[++top]=x;in_stk[x]=1;
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=to[i];
        if(!dfn[j]){
            tarjan(j);
            low[x]=min(low[x],low[j]);
        }
        else if(in_stk[j]) low[x]=min(low[x],dfn[j]);
    }
    if(dfn[x]==low[x]){
        scc_cnt++;
        int p;
        do{
            p=stk[top--];
            in_stk[p]=0;
            id[p]=scc_cnt;
            Size[scc_cnt]++;
        }while(p!=x);
    }
}
int main(){
    int n,m,a,b;cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        add(a,b);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=n;i++){
        for(int j=h[i];j!=-1;j=ne[j]){
            int k=to[j];
            int a=id[i],b=id[k];
            if(a!=b) dout[a]++;
        }
    }
    int res=0,s=0;
    for(int i=1;i<=scc_cnt;i++){
        if(!dout[i]){
            res=Size[i];s++;
            if(s>1){
                res=0;break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
```

