#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int stack[8];
int visited[8];
vector<int> candidate;

void print(){
    for(int i=0; i<M; i++){
        cout<<stack[i]<<" ";
    }cout<<'\n';
}

void dfs(int a, int level){
    if(level==M) {print(); return;}
    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i]=1;
            stack[level]=candidate[i];
            dfs(i, level+1);
            visited[i]=0;
        }
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int a; cin>>a;
        candidate.push_back(a);
    }
    sort(candidate.begin(), candidate.end());

    dfs(0,0);
    
    return 0;
}
