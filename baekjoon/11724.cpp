#include <iostream>
#include <set>

int p[1001];

using namespace std;

int ff(int a){
	if(p[a]==a) return a;
	else return p[a]=ff(p[a]);
}

void uf(int a, int b){
	int pa=ff(a);
	int pb=ff(b);

	if(pa>pb) p[pa]=p[pb];
	else p[pb]=p[pa];
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N, M; cin>>N>>M;
	for(int i=1; i<=N; i++){
		p[i]=i;
	}

	for(int i=0; i<M; i++){
		int x, y;
		cin>>x>>y;
		uf(x, y);
	}

	set<int> s;
	for(int i=1; i<=N; i++){
		s.insert(ff(i));
	}

	cout<<s.size();
    return 0;
}
