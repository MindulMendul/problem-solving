#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E; cin>>V>>E;
    vector<int> e[V];
    int visited[V];

    for(int i=0; i<V; i++){
        visited[i]=0;
    }

    for(int i=0; i<E; i++){
        int start, end; cin>>start>>end;
        e[start-1].push_back(end-1);
        e[end-1].push_back(start-1);
    }

    queue<int> q;
    visited[0]=1;
    q.push(0);
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(int i=0; i<e[cur].size(); i++){
            if(!visited[e[cur][i]]){
                visited[e[cur][i]]=1;
                q.push(e[cur][i]);
            }
        }
    }

    int ans=0;

    for(int i=1; i<V; i++){
        if(visited[i]) ans++;
    }

    cout<<ans;

    return 0;
}
