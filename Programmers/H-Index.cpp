#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    if (citations.front() == 0) return 0;
    // 모든 논문 citation수가 논문 갯수보다 많으면 논문의 수를 리턴해야 함.
    if (citations.back() > citations.size()) return citations.size();

    int i = 0;
    for (; i < citations.size(); i++)
    {
        if (citations[i] <= i) {
            return i;
        }
    }

    return i;
}

#include <iostream>
int main() {
    //auto ret = solution({3, 0, 6, 1, 5});
    auto ret = solution({4,4,4});
    cout << ret << "\n";
    
    return 0;
}