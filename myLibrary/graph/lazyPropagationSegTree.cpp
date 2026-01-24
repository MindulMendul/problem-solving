#include <iostream>

using namespace std;

typedef long long int lli;

int N, M, K;
lli arr[1'000'001];
lli segtree[4'000'001];
lli lazy[4'000'001];

lli init(int ind, int s, int e){
	if(s==e) return segtree[ind]=arr[s];
	if(e<0 || N-1<s) return 0;
	int mid=(s+e)/2;
	lli li=init(ind*2, s, mid);
	lli ri=init(ind*2+1, mid+1, e);
	return segtree[ind]=li+ri;
}

void propagate(int ind, int s, int e){
	if(lazy[ind]==0) return;
	segtree[ind]+=lazy[ind]*(e-s+1);
	if(s<e) { // ind is not leaf
		lazy[ind*2]+=lazy[ind];
		lazy[ind*2+1]+=lazy[ind];
	}
	lazy[ind]=0;
}

void update(int ind, int l, int r, int s, int e, lli k){
	propagate(ind, s, e);

	if(e<l || r<s) return;
	if(l<=s && e<=r) {
		lazy[ind] += k;
		propagate(ind, s, e);
		return;
	}
	int mid=(s+e)/2;
	update(ind*2, l, r, s, mid, k);
	update(ind*2+1, l, r, mid+1, e, k);
	segtree[ind] = segtree[ind*2] + segtree[ind*2+1];
}

lli getValue(int ind, int l, int r, int s, int e){
	propagate(ind, s, e);

	if(e<l || r<s) return 0;
	if(l<=s && e<=r) return segtree[ind];
	
	int mid=(s+e)/2;
	lli li=getValue(ind*2, l, r, s, mid);
	lli ri=getValue(ind*2+1, l, r, mid+1, e);
	return li+ri;
}

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// init
	cin>>N>>M>>K;
	for(int i=0; i<=4'000'000; i++){
		segtree[i]=0;
		lazy[i]=0;
	}
	for(int i=0; i<N; i++) cin>>arr[i];
	init(1, 0, N-1);

	// calculate
	for(int i=0; i<M+K; i++){
		int cmd; cin>>cmd;
		if(cmd==1) {
			int l, r; lli d; cin>>l>>r>>d; l--; r--;
			update(1, l, r, 0, N-1, d);
		} else if(cmd==2) {
			int l, r; cin>>l>>r; l--; r--;
			cout<<getValue(1, l, r, 0, N-1)<<"\n";
		}
	}
}