/*
N은 50,000이고, N 길이의 배열에는 각 학생이 있습니다. 각 학생은 [수학 점수, 영어 점수]로 주어집니다.
예: 학생배열 = [[50, 40], [70, 60], ...]
목표는 3명의 학생을 선택했을 때:
그 학생들의 수학 점수 중 최소값 (min_math)
그 학생들의 영어 점수 중 최소값 (min_eng)
두 값을 더한 (min_math + min_eng) 값이 최대가 되는 경우를 찾기

입력 점수 제한은 0이상 1,000,000,000 이하
*/

#include <iostream>

using namespace std;

#define INF 1999999999

typedef long long int lli;
typedef struct {
  int math;
  int eng;
} Student;

Student student[50000];

int main(){
  // init
  freopen("input.txt", "rt", stdin);
  int N, sum_math, sum_eng;
  cin>>N;
  for(int i=0; i<N; i++){
    cin>>student[i].math>>student[i].eng;
  }

  // 최초 3명 init
  Student arr[3];
  lli mm=INF, me=INF;
  int front=0, tail=2;
  for(int i=0; i<3; i++){
    arr[i].math=student[i].math;
    arr[i].eng=student[i].eng;
    if(mm>student[i].math) mm=student[i].math;
    if(me>student[i].eng) me=student[i].eng;
  }

  for(int i=3; i<N; i++){
    lli min_math, min_eng;
    
    for(int j=0; j<3; j++){
      min_math=INF, min_eng=INF;
      Student frontArr=arr[front];
      front=(front+1)%3;
      if(min_math>arr[front].math) min_math=arr[front].math;
      if(min_eng>arr[front].eng) min_eng=arr[front].eng;
      if(min_math>arr[tail].math) min_math=arr[tail].math;
      if(min_eng>arr[tail].eng) min_eng=arr[tail].eng;
      
      lli minf_math=min_math, minf_eng=min_eng;
      if(minf_math>frontArr.math) minf_math=frontArr.math;
      if(minf_eng>frontArr.eng) minf_eng=frontArr.eng;

      lli mins_math=min_math, mins_eng=min_eng;
      if(mins_math>student[i].math) mins_math=student[i].math;
      if(mins_eng>student[i].eng) mins_eng=student[i].eng;

      tail=(tail+1)%3;
      min_math=minf_math;
      min_eng=minf_eng;

      if(min_math+min_eng<mins_math+mins_eng){
        arr[(front+2)%3].math=student[i].math;
        arr[(front+2)%3].eng=student[i].eng;
        min_math=mins_math;
        min_eng=mins_eng;

        break;
      }
    }
    
    if(mm+me<min_math+min_eng){
        mm=min_math;
        me=min_eng;
    }
  }

  cout<<mm+me<<endl;
  return 0;
}
