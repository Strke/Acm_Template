### Trie树

 ```c++
 #include<iostream>
 #include<string.h>
 #include<algorithm>
 #include<cstring>
 using namespace std;
 const int maxn=1e5+5;
 int son[maxn][28],idx,cnt[maxn];
 void insert(char *str){
     int p=0;
     for(int i=0;str[i];i++){
         int u=str[i]-'a';
         if(!son[p][u]) son[p][u]=++idx;
         p=son[p][u];
     }
     cnt[p]++;
 }
 int query(char * str){
     int p=0;
     for(int i=0;str[i];i++){
         int u=str[i]-'a';
         if(!son[p][u]) return 0;
         p=son[p][u];
     }
     return cnt[p];
 }
 int main(){
     int n;cin>>n;
     char op;
     while(n--){
         char a[maxn];
         cin>>op>>a;   
         if(op=='I') insert(a);
         else cout<<query(a)<<endl;
     }
     return 0;
 }
 ```

