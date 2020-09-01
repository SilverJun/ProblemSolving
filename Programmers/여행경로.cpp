#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

enum {
    MAX_CITY = 10000,
};
int ticketSize = 0;
vector<string> path;
unordered_map<string, vector<pair<string, bool>>> dict;

void DFS(int depth) {
    if (path.size() == ticketSize+1) {
        // cout << path.size() << ", " <<ticketSize+1 << "FIND MIN PATH\n";
        return;
    }

    auto& vec = dict[path[depth-1]];
    for (int i = 0; i < vec.size(); i++) // 이전 도시에서 갈 수 있는 도시들.
    {
        if (false == vec[i].second) { // 해당 티켓을 이미 사용했는지 체크.
            vec[i].second = true;
            path.push_back(vec[i].first);
            DFS(depth+1);
            if (path.size() == ticketSize+1) return;
            vec[i].second = false;
            path.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // vector<string> answer;
    ticketSize = tickets.size();
    
    // adj list 만들기.
    for (int i = 0; i < ticketSize; ++i) {
        dict[tickets[i][0]].push_back(make_pair(tickets[i][1], false));
    }

    // adj list를 sorting하기.
    for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
        auto& vec = (*iter).second;
        sort(vec.begin(), vec.end());
    }

    // traveling ICN에서 시작
    path.reserve(MAX_CITY);
    path.push_back("ICN");
    DFS(1);
    return path;
}

int main() {
    auto ret = solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}});
    
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << "\n";
    }
    
    return 0;
}