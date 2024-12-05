#include <iostream>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	string inOrder;
	char stack[101];
	int top=-1;
	cin>>inOrder;
	for(auto e:inOrder){
		if(e=='+' || e=='-'){
			while(top>-1 && (stack[top]!='(')) cout<<stack[top--];
			stack[++top]=e;
		}
		else if(e=='*' || e=='/'){
			while(top>-1 && (stack[top]=='*' || stack[top]=='/')) cout<<stack[top--];
			stack[++top]=e;
		}
		else if(e=='('){
			stack[++top]=e;
		}
		else if(e==')'){
			while(stack[top]!='('){
				cout<<stack[top--];
			} top--;
		}
		else {cout<<e;}
	}

	for(int i=top; i>=0; i--){
		cout<<stack[i];
	}

  return 0;
}
