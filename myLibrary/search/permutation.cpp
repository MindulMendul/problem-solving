// # 15650 문제 확인
// 완전 순회로 구현 (여기서는 dfs로 구현)
// 깊이가 맞을 때까지 search하는 방식으로 구현

#include <iostream>

using namespace std;

int N, M;

int stack[8];

void print(){
    for(int i=0; i<M; i++){
        cout<<stack[i]<<" ";
    }cout<<'\n';
}

void dfs(int a, int level){
    if(level==M) {print(); return;}
    for(int i=a+1; i<=N; i++){
        stack[level]=i;
        dfs(i, level+1);
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;

    dfs(0,0);
    
    return 0;
}
