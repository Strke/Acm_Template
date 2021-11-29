### KMP

```c++
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=6e6+5;
char p[maxn],s[maxn];
int n,m,ne[maxn];
int main(){
    cin>>n>>p+1>>m>>s+1;
    for(int j=0,i=2;i<=n;i++){  //求next数组
        while(p[j+1]!=p[i]&&j) j=ne[j];
        if(p[j+1]==p[i]) j++;
        ne[i]=j;
    }
    for(int i=1,j=0;i<=m;i++){  //模式串匹配
        while(j&&p[j+1]!=s[i]) j=ne[j];
        if(p[j+1]==s[i]) j++;
        if(j==n){
            cout<<i-n<<" ";//输出每个匹配到的初始下标
            j=ne[j];   
        }
    }
    cout<<endl;
    return 0;
}
```

