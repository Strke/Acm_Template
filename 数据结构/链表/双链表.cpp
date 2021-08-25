#include<iostream>
using namespace std;
const int maxn=1e5+5;
int l[maxn],r[maxn],e[maxn],cnt=2;
//在第k的右边插入x
void insert(int k,int x){int z=r[k];e[cnt]=x;r[k]=cnt;l[z]=cnt;r[cnt]=z;l[cnt]=k;cnt++;}
//删除第k个插入的数
void del(int k){int x=l[k],y=r[k];r[x]=y;l[y]=x;}
int main(){
    int n;cin>>n;
    r[0]=1;l[1]=0;
    while(n--){
        int x,k;string op;cin>>op;
        //表示在链表的最左端插入数 x。
        if(op=="L"){cin>>x;insert(0,x);}
        //表示在链表的最右端插入数 x。
        else if(op=="R"){cin>>x;insert(l[1],x);}
        //表示将第 k 个插入的数删除。
        else if(op=="D"){cin>>k;del(k+1);}
        //表示在第 k 个插入的数右侧插入一个数。
        else if(op=="IR"){cin>>k>>x;insert(k+1,x);}
        //表示在第 k 个插入的数左侧插入一个数。
        else if(op=="IL"){cin>>k>>x;insert(l[k+1],x);}
    }
    for(int i=r[0];i!=1;i=r[i]) cout<<e[i]<<" ";
    cout<<endl;
    return 0;
}