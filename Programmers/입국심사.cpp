#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = ULLONG_MAX;
    // sort times
    sort(times.begin(), times.end());

    unsigned long long low = 1;
	unsigned long long high = times.back() * n;

	while (low <= high) {
		unsigned long long mid = (low + high) / 2;
		unsigned long long cnt = 0;

		for (int i = 0; i < times.size(); i++) {
			cnt += mid / times[i];
		}

        // 심사관이 커버 가능
		if (cnt >= n) {
            answer = min(answer, mid); // 더 짧은 끝나는 시간을 업데이트.
			high = mid - 1;
		}
        // 심사관이 커버 불가능
		else {
			low = mid + 1;
		}
	}
    
    return answer;
}

#include <iostream>
int main() {
    auto ret = solution(6, {7, 10});
    cout << ret << "\n"; // 26
    
    return 0;
}
