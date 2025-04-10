#include <iostream>
using namespace std;

// 컨테이너에는 헤드만 있으면 될 것 같고
// 각 아이템에는 컨테이너 번호, 앞 아이템 번호, 뒷 아이템 번호 순으로 저장하면 될 듯?

int N, M;

typedef struct {
    int prev;
    int next;
} Node;

Node items[100'001];
int head[100'001];
int tail[100'001];
int len[100'001];

void add_belt(int belt, int i){
    items[i].next=-1; items[i].prev=-1;
    if(head[belt]==-1) {
        head[belt]=i;
        tail[belt]=i;
        len[belt]=1;
    } else {
        items[tail[belt]].next=i;
        items[i].prev=tail[belt];
        tail[belt]=i;
        len[belt]++;
    }
}

void init(){
    cin>>N>>M;
    for(int b=0; b<=N; b++){head[b]=-1; tail[b]=-1; len[b]=0;}
    for(int i=1; i<=M; i++){
        int belt; cin>>belt;
        add_belt(belt, i);
    }
}
void move_all(){
    int src, dst; cin>>src>>dst;
    items[head[dst]].prev=tail[src];
    items[tail[src]].next=head[dst];
    head[dst]=head[src];
    if(tail[dst]==-1) tail[dst]=tail[src];
    head[src]=-1;
    tail[src]=-1;

    len[dst]+=len[src];
    len[src]=0;
    cout<<len[dst]<<'\n';
}
void move_head(){
    int src, dst; cin>>src>>dst;
    if(head[src]==-1 && head[dst]>-1){
        len[src]++; len[dst]--;
        cout<<len[dst]<<'\n';
        if(len[dst]==0){
            head[src]=head[dst];
            tail[src]=head[dst];
            head[dst]=-1; tail[dst]=-1;
            return;
        }
        int head_dst=items[head[dst]].next;
        items[items[head[dst]].next].prev=-1;
        items[head[dst]].next=-1;
        head[src]=head[dst];
        tail[src]=head[dst];
        head[dst]=head_dst;
        return;
    } else if(head[src]>-1 && head[dst]==-1){
        len[dst]++; len[src]--;
        cout<<len[dst]<<'\n';
        if(len[src]==0){
            head[dst]=head[src];
            tail[dst]=head[src];
            head[src]=-1; tail[src]=-1;
            return;
        }
        int head_src=items[head[src]].next;
        items[items[head[src]].next].prev=-1;
        items[head[src]].next=-1;
        head[dst]=head[src];
        tail[dst]=head[src];
        head[src]=head_src;
        return;
    }
    
    int tmp=items[head[src]].next;
    
    items[items[head[src]].next].prev=head[dst];
    items[items[head[dst]].next].prev=head[src];
    items[head[src]].next=items[head[dst]].next;
    items[head[dst]].next=tmp;
    
    tmp=head[src];
    head[src]=head[dst];
    head[dst]=tmp;

    if(len[src]==1) tail[src]=head[src];
    if(len[dst]==1) tail[dst]=head[dst];

    cout<<len[dst]<<'\n';
}
void divide(){
    int src, dst; cin>>src>>dst;
    if(len[src]<2) {
        cout<<len[dst]<<'\n';
        return;
    }

    int mid=head[src];
    for(int mmid=0; mmid<len[src]/2-1; mmid++){
        mid=items[mid].next;
    }
    //cout<<"mid"<<mid<<"/";
    int head_src=items[mid].next;

    items[items[mid].next].prev=-1;
    items[head[dst]].prev=mid;
    //cout<<"mid"<<mid<<endl;
    items[mid].next=head[dst];
    
    head[dst]=head[src];
    if(tail[dst]==-1) tail[dst]=mid;
    head[src]=head_src;

    len[dst]+=len[src]/2;
    len[src]-=len[src]/2;
    cout<<len[dst]<<'\n';
}
void get_info_item(){
    int p_num; cin>>p_num;
    int a=items[p_num].prev, b=items[p_num].next;
    //cout<<p_num<<": aaa"<<a<<" bbb"<<b<<endl;
    cout<<a+2*b<<'\n';
}
void get_info_belt(){
    int b_num; cin>>b_num;
    int a=head[b_num], b=tail[b_num], c=len[b_num];
    //cout<<b_num<<": aaa"<<a<<" bbb"<<b<<" ccc"<<c<<endl;
    cout<<a+2*b+3*c<<'\n';
}

void print_belt(){
    for(int b=1; b<=N; b++){
        cout<<"belt"<<b<<": head"<<head[b]<<" ";
        for(int i=head[b]; i!=tail[b]; i=items[i].next){
            if(i<0) break;
            cout<<i<<" ";
        }
        if(tail[b]>-1) cout<<tail[b]<<" ";
        cout<<"tail"<<tail[b];
        cout<<endl;
    }
}

int main() {
    int q; cin>>q;
    int cmd;

    for(int query=0; query<q; query++){
        cin>>cmd;
        if(cmd==100){init();}
        else if(cmd==200){move_all();}
        else if(cmd==300){move_head();}
        else if(cmd==400){divide();}
        else if(cmd==500){get_info_item();}
        else if(cmd==600){get_info_belt();}
        // if(query>-1) print_belt();
    }
    return 0;
}
