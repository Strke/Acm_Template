### dijkstra（堆优化版）

```c++
#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<vector>
using namespace std;
const int maxn=2e5;
typedef pair<int,int> PII;
int h[maxn],to[maxn],ne[maxn],e[maxn],cnt,n,m;
int dist[maxn],st[maxn];
void add(int x,int y,int z){
    to[cnt]=y;e[cnt]=z;ne[cnt]=h[x];h[x]=cnt++;
}
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push({0,1});
    dist[1]=0;
    while(!q.empty()){
        PII p=q.top();q.pop();
        int ver=p.second;
        if(st[ver]) continue;
        st[ver]=1;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=to[i];
            if(dist[j]>dist[ver]+e[i]){
                dist[j]=dist[ver]+e[i];
                q.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    cout<<dijkstra()<<endl;
    return 0;
}
```

