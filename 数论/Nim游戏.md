### Nim游戏

先手必胜状态：先手操作完，可以走到某一个必败状态
先手必败状态：先手操作完，走不到任何一个必败状态
先手必败状态：$a_1 \bigwedge a_2 \bigwedge a_3 \bigwedge ... \bigwedge a_n = 0$
先手必胜状态：$a_1 \bigwedge a_2 \bigwedge a_3 \bigwedge ... \bigwedge a_n  ≠ 0$

```c++
#include<iostream>
using namespace std;
int res=0;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        res=res^x;
    }
    if(res) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
```

### SG函数

```c++
#include<iostream>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;
const int K=105,N=10005;
int s[K],f[N];
int k,n;
int sg(int x){
    if(f[x]!=-1) return f[x];
    set<int> S;
    for(int i=0;i<k;i++){
        if(x-s[i]>=0) S.insert(sg(x-s[i]));
    }
    for(int i=0;;i++)
        if(S.count(i)==0)
            return f[x]=i;
}
int main(){
    cin>>k;
    int h,res=0;
    memset(f,-1,sizeof f);
    for(int i=0;i<k;i++) cin>>s[i];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h;
        res=res^sg(h);
    }
    if(res) cout<<"Yes"<<endl;    
    else cout<<"No"<<endl;
    return 0;
}
```

