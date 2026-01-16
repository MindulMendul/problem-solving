#include <iostream>

using namespace std;

int N;
bool board[1000][1000];

int main() {
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// init
	cin>>N;
	int hy=-1, hx;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			char a; cin>>a;
			board[i][j]=(a=='*');
			if(board[i][j] && hy==-1) {
				hy=i; hx=j;
			}
		}
	}

	hy++; // heart
	cout<<hy+1<<" "<<hx+1<<"\n";

	int ans[5]={0,0,0,0,0};
	
	// left arm
	for(int i=0; i<hx; i++){
		if(board[hy][i]) {
			ans[0]=hx-i;
			break;
		}
	}

	// right arm
	for(int i=hx+1; i<N; i++){
		if(!board[hy][i]) {
			ans[1]=i-1-hx;
			break;
		}
	}
	if(ans[1]==0) ans[1]=N-1-hx;

	// body
	for(int i=hy+1; i<N; i++){
		if(!board[i][hx]){
			ans[2]=i-1-hy;
			hy=i;
			break;
		}
	}

	// left leg
	for(int i=hy; i<N; i++){
		if(!board[i][hx-1]){
			ans[3]=i-hy;
			break;
		}
	}
	if(ans[3]==0) ans[3]=N-hy;

	// right leg
	for(int i=hy; i<N; i++){
		if(!board[i][hx+1]){
			ans[4]=i-hy;
			break;
		}
	}
	if(ans[4]==0) ans[4]=N-hy;
	
	for(int i=0; i<5; i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}