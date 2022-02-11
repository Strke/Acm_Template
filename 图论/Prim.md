### prim求最小生成树

```c++
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 505;
const int inf = 0x3f3f3f3f;
int g[N][N], dist[N], st[N];
int n, m;
int prime(){
    int res = 0;
    memset(dist, inf, sizeof dist);
    for(int i = 0;i < n;i ++){
        int t = -1;
        for(int j = 1; j <= n; j ++)
            if(!st[j] && (t==-1 || dist[t] > dist[j]))
                t=j;
        if(i && dist[t] == inf) return inf;
        if(i) res += dist[t];
        st[t] = 1;
        for(int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}
int main(){
    cin >> n >> m;
    int a, b, c;
    memset(g, inf, sizeof g);
    for(int i = 1; i <= m; i ++){
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prime();
    if(t == inf) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}
```

