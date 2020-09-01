#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    answer.reserve(speeds.size());
    vector<int> remainDates;
    remainDates.resize(speeds.size());
    vector<bool> complete;
    complete.resize(speeds.size());
    
    // calculate remaining dates
    for (int i = 0; i < remainDates.size(); ++i) {
        remainDates[i] = ceil((100 - progresses[i])/(double)speeds[i]);
    }
    
    // simulate
    for (int i = 0; i < remainDates.size(); ++i) {
        int count = 1;
        if (complete[i]) continue; // 이 기능이 이전기능과 함께 Release 되었는지 확인 후 넘어감.
        complete[i] = true;
        for (int j = i+1; j < remainDates.size(); ++j) {
            if (!complete[j] && remainDates[i] >= remainDates[j]) {
                complete[j] = true;
                count++;
            }
            else {
                break;
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}

#include <iostream>
int main() {
    auto ret = solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1});
    
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << "\n";
    }
    
    return 0;
}