### Kruskal求最小生成树

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5, M=4e5+5, inf=0x3f3f3f3f;
struct node{
    int a,b,c;
}e[M];
int n,m,p[N];
bool cmp(node x,node y){
    return x.c<y.c;
}
int find(int x){
    if(x!=p[x]) return p[x]=find(p[x]);
    return p[x];
}
int kruskal(){
    int res=0,cnt=1;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=0;i<m;i++){
        int a=find(e[i].a),b=find(e[i].b),c=e[i].c;
        if(a!=b){
            p[a]=b;
            res+=c;
            cnt++;
        }
    }
    if(cnt<n) return inf;
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>e[i].a>>e[i].b>>e[i].c;
    }
    sort(e,e+m,cmp);
    int t=kruskal();
    if(t==inf) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
```

