### AC自动机

```c++
#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
const int N=1e4+5, S=55, M=1e6+5;
int t,n;
int trie[N*S][26],idx,cnt[N*S];
int q[N*S],fail[N*S];
void insert(string s){
    int p=0,h=s.size();
    for(int i=0;i<h;i++){
        int t=s[i]-'a';
        if(!trie[p][t]) trie[p][t]=++idx;
        p=trie[p][t];
    }
    cnt[p]++;
}
void build(){
    int hh=0,tt=-1;
    for(int i=0;i<26;i++) {
        if(trie[0][i]) q[++tt]=trie[0][i];
    }
    while(hh<=tt){
        int ans=q[hh++];
        for(int i=0;i<26;i++){
            if(trie[ans][i]){
                fail[trie[ans][i]]=trie[fail[ans]][i];
                q[++tt]=trie[ans][i];
            }
            else{
                trie[ans][i]=trie[fail[ans]][i];
            }
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        memset(trie,0,sizeof trie);
        memset(cnt,0,sizeof cnt);
        memset(fail,0,sizeof fail);
        idx=0;
        cin>>n;
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            insert(s);
        }
        build();
        cin>>s;
        int res=0,h=s.size();
        for(int i=0,j=0;i<h;i++){
            int u=s[i]-'a';
            j=trie[j][u];
            int p=j;
            while(p){
                res+=cnt[p];
                cnt[p]=0;
                p=fail[p];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
```

