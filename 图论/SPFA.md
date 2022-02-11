### SPFA（求负环）

求差分约束时需注意

* 有一个超级源点
* spfa内的不等关系求最小值时用最长路，求最大值时用最短路

差分约束时构建的不等关系为必须如下所示

​															                	$$S_i \geq S_{i - 1} + c_i$$

```c++
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
const int N = 510, M = 5210;
int n, h[N], ne[M], to[M], e[M],cntx;
void add(int x,int y,int z){
    to[cntx] = y;e[cntx] = z;ne[cntx] = h[x];h[x] = cntx ++;
}
int dist[N], st[N], cnt[N];//cnt数组记录了负环的信息
bool spfa(){
    queue<int> q;
    memset(dist, 0, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= n; i ++){
        q.push(i);st[i] = true;
    }
    while(q.size()){
        int p = q.front();
        q.pop();
        st[p] = false;
        for(int i = h[p]; ~i; i = ne[i]){
            int j = to[i];
            if(dist[j] > dist[p] + e[i]){
                dist[j] = dist[p] + e[i];
                cnt[j] = cnt[p] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}
```

