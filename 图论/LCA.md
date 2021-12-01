### LCA（最近公共祖先）

```c++
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=4e4+5,M=2*N;
int h[N],ne[M],to[M],e[M],idx,n;
void add(int x,int y){
    to[idx]=y;ne[idx]=h[x];h[x]=idx++;
}
int fa[N][16],depth[N];
void bfs(int root){
    memset(depth,inf,sizeof depth);
    depth[0]=0;depth[root]=1;
    queue<int> q;
    q.push(root);
    while(q.size()){
        int ver=q.front();q.pop();
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=to[i];
            if(depth[j]>depth[ver]+1){
                depth[j]=depth[ver]+1;
                q.push(j);
                fa[j][0]=ver;
                for(int i=1;i<=15;i++){
                    fa[j][i]=fa[fa[j][i-1]][i-1];
                }
            }
        }
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    for(int i=15;i>=0;i--){
        if(depth[fa[a][i]]>=depth[b])
            a=fa[a][i];
    }
    if(a==b) return b;
    for(int i=15;i>=0;i--){
        if(fa[a][i]!=fa[b][i]){
            a=fa[a][i];b=fa[b][i];
        }
    }
    return fa[a][0];
}
int main(){
    cin>>n;int root,a,b;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(b==-1) root=a;
        add(a,b);add(b,a);
    }
    bfs(root);
    int m;cin>>m;
    while(m--){
        cin>>a>>b;
        int p=lca(a,b);
        if(p==a) cout<<"1"<<endl;
        else if(p==b) cout<<"2"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}
```

