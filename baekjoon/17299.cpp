#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<int> v;
unordered_map<int, int> um;
vector<int> ans;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  cin>>N;
  for(int i=0; i<N; i++){
    int a; cin>>a;
    v.push_back(a);
    ans.push_back(0);
  }
    
  for(int i=0; i<N; i++){
    if(um.count(v[i])==0) um[v[i]]=1;   
    else um[v[i]]++;
  }

	vector<int> stack;
	for(int i=N-1; i>=0; i--){
		int top=stack.size()-1;
		while(top>=0){
			if(um[v[i]]<um[stack[top]]) break;
			stack.pop_back();
			top--;
		}
		if(top<0) ans[i]=-1;
		else ans[i]=stack[top];
		stack.push_back(v[i]);
	}
    
  for(int i=0; i<N; i++){
    cout<<ans[i]<<' ';
  }
    
  return 0;
}