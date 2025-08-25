// https://www.crocus.co.kr/660

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[100001];
int depth[100001]; // first: level, second: parent
int ancestor[100001][18]; // log_2(100000)=15.xxxxx

void makeTree(){
    queue<int> q;
    q.push(1);
    depth[1]=1;
    while(!q.empty()){
        int parent=q.front(); q.pop();        
        for(int j=0; j<edge[parent].size(); j++){
            int child=edge[parent][j];
            if(!depth[child]){
                q.push(child);
                depth[child]=depth[parent]+1;

                // ancestor 채워넣기
                ancestor[child][0]=parent;
                for(int i=1; i<=16; i++){
                    ancestor[child][i]=ancestor[ancestor[child][i-1]][i-1];
                }
            }
        }
    }
}

int findAncestor(int x, int y){
    if(x==1 || y==1) return 1;

    int a=x, b=y;
    if(depth[a]<depth[b]) {
        int tmp=a; a=b; b=tmp;
    }

    // 일단 높이부터 맞추기
    if(depth[a]!=depth[b]){
        for(int i=16; i>=0; i--){
            if(depth[b]<=depth[ancestor[a][i]]){
                a=ancestor[a][i];
            }
        }
    }

    // 조상찾기
    int res=a;
    if (a != b) {
        for (int i = 16; i >= 0; i--) {
            if (ancestor[a][i] != ancestor[b][i]) {
                a = ancestor[a][i];
                b = ancestor[b][i];
            }
            res = ancestor[a][i];
        }
    }

    return res;
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N;

    // 노드로부터 트리 구성하기
    depth[0]=-1;

    for(int i=1; i<N; i++){
        int a, b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    makeTree();
    
    // 만들어진 트리를 기반으로 공통조상 찾기
    cin>>M;
    for(int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        cout<<findAncestor(a, b)<<'\n';
    }
    
    return 0;
}
