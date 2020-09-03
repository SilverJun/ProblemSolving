#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    // 들어오는 순서대로 정렬
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });
    

    // 단속 카메라는 기본적으로 나가는 곳을 기준으로 설치함.
    int minExit = routes[0][1];
    for (int i = 0; i < routes.size() - 1; i++) {
        minExit = min(minExit, routes[i][1]); // 나가는 위치의 바운더리를 좁혀간다.

        if (minExit < routes[i + 1][0]) { // 바운더리 체크, 다음 차가 늦게 들어온다면, 단속카메라를 지금 설치해야 이전 차들을 찍을 수 있음.
            ++answer;
            minExit = routes[i + 1][1];
        } 
    }

    return answer;
}

// [[-20,15], [-14,-5], [-18,-13], [-5,-3]]	2

#include <iostream>
int main() {
    auto ret = solution({{-20,15}, {-14,-5}, {-18,-13}, {-5,-3}});
    cout << ret << "\n";
    
    return 0;
}
