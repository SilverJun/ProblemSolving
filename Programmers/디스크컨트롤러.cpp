#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

using task_t = pair<int, int>;

struct comp {
    bool operator() (task_t a, task_t b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0;
    int time = 0;
    int jobSize = jobs.size();
    
    vector<task_t> jobList(jobSize);
    
    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });

    for (int i = 0; i < jobSize; i++)
    {
        jobList[i] = make_pair(jobs[i][0], jobs[i][1]);
    }

    while (!jobList.empty()) {
        for (int i = 0; i < jobList.size(); i++) {
            if (jobList[i].first <= start) {
                start += jobList[i].second;
                time += start - jobList[i].first;
                jobList.erase(jobList.begin() + i);
                break;
            } 
            if (i == jobList.size()-1) start++;
        }
    }
    return time/jobs.size();
}

int main() {
    auto ret = solution({{0, 3}, {1, 9}, {500, 6}});
    cout << ret << "\n";
    return 0;
}
