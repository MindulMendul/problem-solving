#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // N: 입력개수, M: 관개수, K: 강의실개수
  // 입력: 강의실관, 선생번호, 시작시간, 끝시간
  int N, M, K; cin>>N>>M>>K;

  // <강의실, 강의시간>
  vector<vector<vector<int>>> schedule(M+1, vector<vector<int>>(K+1, vector<int>(24,0)));

  for(int i=0; i<N; i++){
    // 각각의 스케줄을 입력받음
    int building, teacher, start, end;
    cin>>building>>teacher>>start>>end;

    // 강의실 확인
    for(int t=start; t<end; t++){
      // 만약 building관 스케줄러에 모든 스케줄이 있다면
      // 방금 입력받은 스케줄은 유효하지 않은 스케줄이므로 예외처리 
      if(schedule[building][0][t]>=K) {
        cout<<teacher<<"선생님은 "<<start<<":00~"<<end<<":00 에는 "<<building<<"관에서 수업을 못합니다~";
        return 0;
      }

      // 모든 schedule[building][0][time]은 그 강의실에 몇 명이 있는지 알려주는 값임
      // building관의 스케줄러에 새로운 스케줄을 추가로 입력받음
      schedule[building][0][t]++;
      
      // 그리고 그 시간대에 선생님 고유번호를 배정해줌
      schedule[building][schedule[building][0][t]][t]=teacher;
    }
  }

  // 출력
  for(int building=1; building<=M; building++){
    cout<<building<<"관"<<endl;
    for(int time=0; time<=23; time++){
      cout<<time<<":00~"<<time+1<<":00 | ";
      for(int room=1; room<=6; room++){
        cout<<schedule[building][room][time]<<" ";
      }cout<<endl;
    }
    cout<<endl;
  }

  return 0;
}