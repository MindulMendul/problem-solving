#include <iostream>
#include <set>

using namespace std;

int G, P;
set<int> gate;

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>G>>P;
	for(int i=1; i<=G; i++){
		gate.insert(-i);
	}
	for(int i=0; i<P; i++){
		int x; cin>>x;
		auto gate_it=gate.lower_bound(-x);
		int gate_x=-(*(gate_it));
		if(gate_x<=0) {
			cout<<i;
			return 0;
		}
		gate.erase(-gate_x);
	}

	cout<<P;
	return 0;
}

