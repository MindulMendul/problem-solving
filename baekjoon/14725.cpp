#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, ind;

typedef struct {
    string food;
    vector<int> children;
} Node;

Node node[15001];

void print(int p, int dep){
    for(int i=0; i<node[p].children.size(); i++){
        for(int j=0; j<dep; j++) cout<<"--";
        cout<<node[node[p].children[i]].food<<"\n";
        print(node[p].children[i], dep+1);
    }
}

struct cmp {
    bool operator()(int a, int b){
        return node[a].food<node[b].food;
    }
};

void branch(int p, int dep, vector<string> line){
    if(dep==line.size()) return;

    for(int i=0; i<node[p].children.size(); i++){
        if(line[dep]==node[node[p].children[i]].food){
            branch(node[p].children[i], dep+1, line);
            return;
        }
    }

    node[ind].food=line[dep];
    node[p].children.push_back(ind);
    sort(node[p].children.begin(), node[p].children.end(), cmp());
    ind++;
    branch(ind-1, dep+1, line);
}



int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    // init
    ind=1;
    for(int i=0; i<15001; i++) {
        node[i].food="";
        vector<int> a; node[i].children=a;
    }

    for(int i=0; i<N; i++) {
        int k; cin>>k;
        string a; 
        vector<string> line; for(int j=0; j<k; j++) {cin>>a; line.push_back(a);}
        branch(0, 0, line);
    }

    print(0, 0);
    
    return 0;
}