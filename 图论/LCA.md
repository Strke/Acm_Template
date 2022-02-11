### LCA（最近公共祖先）

```c++
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
const int N = 1e4 + 5, M = 2 * N, inf = 0x3f3f3f3f;
int h[N], ne[M], to[M], e[M], idx;
int fa[N][15], depth[N], dist[N];
//fa数组为倍增数组， depth数组为每个节点的深度
void add(int x, int y, int z){
    e[idx] = z;to[idx] = y; ne[idx] = h[x]; h[x] = idx ++;
}
void bfs(int root){
    memset(depth, inf, sizeof depth);
    queue<int> q;
    q.push(root);
    depth[root] = 1;depth[0] = 0;
    dist[0] = 0;dist[root] = 0;
    while(q.size()){
        int p = q.front();
        q.pop();
        for(int i = h[p]; ~i; i = ne[i]){
            int j = to[i];
            if(depth[j] > depth[p] + 1){
                depth[j] = depth[p] + 1;
                dist[j] = dist[p] + e[i];
                q.push(j);
                fa[j][0] = p;
                for(int k = 1; k < 15; k ++) 
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int sa = a, sb = b;
    for(int i = 14; i >= 0; i --) 
        if(depth[fa[a][i]] >= depth[b])
            a = fa[a][i];
    if(a == b) return dist[sa] - dist[sb];
    for(int i = 14; i >= 0; i --)
        if(fa[a][i] != fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    int p = fa[a][0];
    return dist[sa] + dist[sb] - 2 * dist[p];
}

int main(){
    int n, m, x, y, k;cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; i ++){
        cin >> x >> y >> k;
        add(x, y, k); add(y, x, k);
    }
    bfs(1);
    for(int i = 0; i < m; i ++){
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}
```

