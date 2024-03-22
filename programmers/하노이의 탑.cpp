#include <string>
#include <vector>

using namespace std;

static vector<vector<int>> answer;

vector<vector<int>> recursive(int floor, int src, int dest){
    vector<int> tmp = {src, dest};
    vector<vector<int>> result;
    
    if(floor==1) {
        result.push_back(tmp);
    } else {
        int mid=6-src-dest;
        vector<vector<int>> left=recursive(floor-1, src, mid);
        vector<vector<int>> right=recursive(floor-1, mid, dest);

        for(int i=0; i<left.size(); i++) result.push_back(left[i]);
        result.push_back(tmp);
        for(int i=0; i<right.size(); i++) result.push_back(right[i]);
    }
    
    return result;
}

vector<vector<int>> solution(int n) {
    return recursive(n, 1, 3);
}