#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    // 각 장르별로 베스트재생횟수 두곡 수록, 많이 재생된 장르 순번대로.
    vector<int> answer;
    answer.reserve(plays.size());

    unordered_map<string, int> sumOfGenre;
    unordered_map<string, vector<pair<int, int>>> category; // <unique id, plays>
    sumOfGenre.reserve(plays.size());
    
    // get total sum of each genre
    for (int i = 0; i < genres.size(); ++i) {
        sumOfGenre[genres[i]] += plays[i];
        category[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    // sort genre
    vector<pair<string, int>> rank(sumOfGenre.begin(), sumOfGenre.end());
    sort(rank.begin(), rank.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    });

    // for (int i = 0; i < rank.size(); i++)
    // {
    //     cout << rank[i].first << ", " << rank[i].second << "\n";
    // }
    // cout << "\n";

    for (int i = 0; i < rank.size(); i++)
    {
        auto curGenre = category[rank[i].first];
        if (curGenre.size() >= 2) { 
            sort(curGenre.begin(), curGenre.end(), [](pair<int, int> a, pair<int, int> b){
                return a.second > b.second;
            });
            answer.push_back(curGenre[0].first);
            answer.push_back(curGenre[1].first);
        }
        else {
            answer.push_back(curGenre[0].first);
        }
    }
    
    return answer;
}

int main() {
    auto ret = solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500});
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << ", ";
    }
    cout << "\n";
    
    return 0;
}