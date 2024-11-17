#include<iostream>

using namespace std;

typedef struct {
  int data;
  int left;
  int right;
} Node;

Node node[26];

void preOrder(int i){
  cout<<(char)(i+65);
  int l=node[i].left; if(l>-19) preOrder(l);
  int r=node[i].right; if(r>-19) preOrder(r);
}

void inOrder(int i){
  int l=node[i].left; if(l>-19) inOrder(l);
  cout<<(char)(i+65);
  int r=node[i].right; if(r>-19) inOrder(r);
}

void postOrder(int i){
  int l=node[i].left; if(l>-19) postOrder(l);
  int r=node[i].right; if(r>-19) postOrder(r);
  cout<<(char)(i+65);
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N; cin>>N;
  for(int i=0; i<N; i++){
    char p, l, r;
    cin>>p>>l>>r; // .은 -19로 나옴!
    node[p-65].data=p-65;
    node[p-65].left=l-65;
    node[p-65].right=r-65;
  }

  preOrder(0);cout<<'\n';
  inOrder(0);cout<<'\n';
  postOrder(0);

  return 0;
}
