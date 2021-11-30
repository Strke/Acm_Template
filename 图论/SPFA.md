### SPFA（求负环）

```c++
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int maxn=2e5+5,inf=0x3f3f3f3f;
int n,m;
int h[maxn],e[maxn],ne[maxn],to[maxn],idx;
int dist[maxn],st[maxn],cnt[maxn];
void add(int x,int y,int z){
    e[idx]=z;to[idx]=y;ne[idx]=h[x];h[x]=idx++;
}
bool spfa(){
    memset(dist,inf,sizeof dist);
    queue<PII> q;
    for(int i=1;i<=n;i++){
        q.push({0,i});//将所有点放入队列，防止图不连通
        st[i]=1;
    }
    dist[1]=0;
    st[1]=1;
    cnt[1]=0;
    while(q.size()){
        PII p=q.front();q.pop();
        int ver=p.second;
        st[ver]=0;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=to[i];
            if(dist[j]>dist[ver]+e[i]){
                dist[j]=dist[ver]+e[i];
                cnt[j]=cnt[ver]+1;
                if(cnt[j]>n) return false;
                if(!st[j]){
                    q.push({dist[j],j});
                    st[j]=1;
                }
            }
        }
    }
    return true;
}
int main(){
    cin>>n>>m;
    int a,b,c;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int t = spfa();
    if(!t) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
```

