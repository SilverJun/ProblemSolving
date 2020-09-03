#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // copy all elements to min heap
    for (auto elem : scoville)
    {
        minHeap.push(elem);
    }

    // pop top element and check
    while (!minHeap.empty())
    {
        int first = minHeap.top();
        minHeap.pop();

        if (first >= K) { // 모든 음식의 스코빌 지수가 K를 넘을때.
            return answer;
        }
        else if (!minHeap.empty()) {
            int second = minHeap.top();
            minHeap.pop();
            
            // 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
            minHeap.push(first + (second * 2));
            answer++;
        }
        else {
            return -1;
        }
    }
    
    return -1;
}