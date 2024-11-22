#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2100000000

using namespace std;

struct Edge {
    int e;
    int s;
    int cost;
    Edge(int ee, int ss, int cc): e(ee), s(ss), cost(cc) {}
};

bool cmp_edge(Edge a, Edge b){ return a.cost<b.cost; }

int N;
vector<Edge> edge;
int parent[100000];

int getParent(int x){
    if(x==parent[x]) return x;
    else return parent[x]=getParent(parent[x]);
}

void unionFind(int a, int b){
    int pa=getParent(a);
    int pb=getParent(b);

    if(pa>=pb){parent[pa]=pb;}
    else {parent[pb]=pa;}
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> vx;
    vector<pair<int, int>> vy;
    vector<pair<int, int>> vz;

    cin>>N;
    for(int i=0; i<N; i++){
        int x, y, z;
        cin>>x>>y>>z;
        vx.push_back(make_pair(x,i));
        vy.push_back(make_pair(y,i));
        vz.push_back(make_pair(z,i));
        parent[i]=i;
    }

    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    sort(vz.begin(), vz.end());

    for(int i=0; i<N-1; i++){
        edge.push_back(Edge(vx[i].second, vx[i+1].second, vx[i+1].first-vx[i].first));
        edge.push_back(Edge(vy[i].second, vy[i+1].second, vy[i+1].first-vy[i].first));
        edge.push_back(Edge(vz[i].second, vz[i+1].second, vz[i+1].first-vz[i].first));
    }

    sort(edge.begin(), edge.end(), cmp_edge);

    int ans=0;
    for(int i=0; i<edge.size(); i++){
        if(getParent(edge[i].s)!=getParent(edge[i].e)){
            unionFind(edge[i].s, edge[i].e);
            ans+=edge[i].cost;
        }
    }
    cout<<ans;

    return 0;
}
