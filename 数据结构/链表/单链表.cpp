#include<iostream>
using namespace std;
const int maxn=1e5+5;
int da[maxn],ne[maxn],Singlelist_cnt=2;
//在第k个节点后面插入x
void insert(int Singlelist_k,int Singlelist_x){
    da[Singlelist_cnt]=Singlelist_x;
    ne[Singlelist_cnt]=ne[Singlelist_k];
    ne[Singlelist_k]=Singlelist_cnt;
    Singlelist_cnt++;
}
//删除第k个节点后面的节点
void del(int Singlelist_k){
    ne[Singlelist_k]=ne[ne[Singlelist_k]];
}
int main(){
    //将0，1两个节点分别作为(伪)头尾节点连接起来，真实的头节点在0节点后面
    ne[0]=1;
    int n;cin>>n;
    while(n--){
        char op;cin>>op;
        //表示向链表头插入一个数 x
        if(op=='H'){
            int x;cin>>x;
            //在头节点的后面插入x，x即为头节点
            insert(0,x);
        }
        //表示删除第 k 个插入的数后面的数（当 k 为 0 时，表示删除头结点）。
        else if(op=='D'){
            int k;cin>>k;
            //0节点后面就是头节点，删除即可
            if(k==0) del(0);
            //删除第k个插入的节点后面的节点，由于第一个节点从下标2开始，所以第k个节点的下表为k+1
            else del(k+1);
        }
        //表示在第 k 个插入的数后面插入一个数 x（此操作中 k 均大于 0）。
        else{
            int x,k;cin>>k>>x;
            insert(k+1,x);
        }
    }
    for(int i=ne[0];i!=1;i=ne[i]) cout<<da[i]<<" ";
    cout<<endl;
    return 0;
}