### Floyd

```c++
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=2e2+5;
const int inf=0x3f3f3f3f;
int d[maxn][maxn],n,m;
void floyd(){
    for(int k=1;k<=n;k++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++)
                d[x][y]=min(d[x][y],d[x][k]+d[k][y]);
}
int main(){
    int k,x,y,z;
    cin>>n>>m>>k;
    memset(d,inf,sizeof d);
    for(int i=1;i<=n;i++) d[i][i]=0;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        if(z<d[x][y]) d[x][y]=z;
    }
    floyd();
    while(k--){
        cin>>x>>y;
        if(d[x][y]>=3e6) cout<<"impossible"<<endl;
        else cout<<d[x][y]<<endl;;
    }
    return 0;
}
```

