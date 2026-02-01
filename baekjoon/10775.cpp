#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int G, P;

int parent[100'001];
int get_parent(int x){
	return (x==parent[x])?x:parent[x]=get_parent(parent[x]);
}

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>G>>P;
	for(int i=0; i<=G; i++){
		parent[i]=i;
	}
	for(int i=0; i<P; i++){
		int x; cin>>x;
		x=get_parent(x);
		if(x==0) {
			cout<<i;
			return 0;
		}
		parent[x]=x-1;
	}

	cout<<P;
	return 0;
}

