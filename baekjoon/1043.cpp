#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> party_people[51];
int parent[51];
int known;

int getParent(int i){
    return (parent[i]==i)?i:parent[i]=getParent(parent[i]);
}

void unionFind(int a, int b){
    int pa=getParent(a);
    int pb=getParent(b);
    if(pa>pb) parent[pa]=pb;
    else parent[pb]=pa;
}

bool isUnion(int a, int b){
    int pa=getParent(a);
    int pb=getParent(b);
    return pa==pb;
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;
    int K; cin>>K;

    // 아무도 없으면 모든 파티에 참석 가능
    if(K==0) { cout<<M; return 0; }

    // union find용 parent
    for(int i=0; i<=N; i++){
        parent[i]=i;
    }

    // 아는 애들끼리는 union find 해놓음
    vector<int> kkk;
    for(int i=0; i<K; i++){
        int a; cin>>a;
        kkk.push_back(a);
    }
    known=*min_element(kkk.begin(), kkk.end()); // 아는 애들 끼리의 union find 값
    for(auto e:kkk){
        unionFind(getParent(known), e);
    }

    int ans=0;
    for(int i=0; i<M; i++){
        int P; cin>>P;
        for(int j=0; j<P; j++){
            int a; cin>>a;
            party_people[i].push_back(a);
        }

        int _min=10000000;
        for(int j=0; j<P; j++){
            int _tmp=getParent(party_people[i][j]);
            if(_tmp<_min)_min=_tmp;
        }

        for(int j=0; j<P; j++){
            unionFind(_min, party_people[i][j]);
        }
    }


    for(int i=0; i<M; i++){
        if(!isUnion(getParent(known), party_people[i][0])) {ans++;}
    }
    cout<<ans;
    
    return 0;
}
