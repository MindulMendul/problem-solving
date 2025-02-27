#include <iostream>
#include <vector>

using namespace std;

static int parent[1'000'001];

//시간 복잡도가 상수시간
int find_parent(int x){
    if(x==parent[x]) return x;
    else return parent[x]=find_parent(parent[x]);
}

void union_parent(int a, int b){
    int pa=find_parent(a);
    int pb=find_parent(b);

    if(pa>=pb){parent[pa]=pb;}
    else {parent[pb]=pa;}
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M; cin>>N>>M;
  for(int i=0; i<=N; i++){
    parent[i]=i;
  }

  for(int tc=0; tc<M; tc++){
    int cmd, a, b;
    cin>>cmd>>a>>b;
    if(cmd){
      // 확인 연산
      if(find_parent(a)==find_parent(b)) cout<<"yes\n";
      else cout<<"no\n";
    } else {
      //  합집합 연산
      union_parent(a,b);
    }
  }

  return 0;
}