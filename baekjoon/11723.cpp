#include <iostream>
#include <string>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int Set[20]={0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};
	int M; cin>>M;
	int sw=0;

	for(int i=1; i<=M; i++){
		string cmd; int j;
		cin >> cmd;
		if(cmd=="add"){
			cin>>j;
			Set[j-1]=i;
		}

		if(cmd=="remove"){
			cin>>j;
			Set[j-1]=-i;
		}

		if(cmd=="check"){
			cin>>j;
			if(sw!=0){
				int abs_sw=(sw>0)?sw:-sw, abs_set=(Set[j-1]>0)?Set[j-1]:-Set[j-1];
				if(abs_sw>=abs_set){ // sw 로 갱신된 사실이 있다면 반영해주기.
					Set[j-1]=(abs_sw==sw)?i:-i;
				}
			}
			j=(Set[j-1]>0)?1:0;
			cout<<j<<"\n";
		}

		if(cmd=="toggle"){
			cin>>j;
			if(sw!=0){
				int abs_sw=(sw>0)?sw:-sw, abs_set=(Set[j-1]>0)?Set[j-1]:-Set[j-1];
				if(abs_sw>=abs_set){ // sw 로 갱신된 사실이 있다면 반영해주기.
					Set[j-1]=(abs_sw==sw)?-i:i;
				}
			}
			Set[j-1]=(Set[j-1]>0)?-i:i;
		}

		if(cmd=="all"){ 
			sw=i;
		}

		if(cmd=="empty"){ 
			sw=-i;
		}
	}
		
    return 0;
}
