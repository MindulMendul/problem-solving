#include <iostream>
#include <vector>

using namespace std;

#define MAX 1'000'001

int N;

vector<int> edge[MAX];
bool visited[MAX];
int human[MAX];
int earlyAdapter[MAX];

void search(int parent){
    visited[parent]=true;

    for(int i=0; i<edge[parent].size(); i++){
        int child=edge[parent][i];
        if(visited[child]) continue;
        search(child);
        human[parent]+=earlyAdapter[child];
        earlyAdapter[parent]+=min(earlyAdapter[child], human[child]);
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=1; i<=N; i++) {
        visited[i]=false;
        human[i]=0;
        earlyAdapter[i]=1;
        int s, e;
        cin>>s>>e;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }

    search(1);

    cout<<min(human[1], earlyAdapter[1]);
    
    return 0;
}