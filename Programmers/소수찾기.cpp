#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<bool> primes;

// n보다 작은 소수를 구함, 에라토스테네스의 체 사용.
void get_prime(int n)
{
    primes = vector<bool>(n, false);
    
    // setup numbers
    vector<int> n_list(n, 0);
    
    for (int i = 0; i < n_list.size(); i++) // 0...n
        n_list[i] = i;

    n_list[1] = 0; // 1 없앰
    for (int i = 2; i < n; i++)
    {
        if (n_list[i] == 0) continue;
        primes[n_list[i]] = true;
        for (int j = i+i; j < n; j+=i) // 배수 찾아서 지우기
            n_list[j] = 0;
    }
}

string numCandidates;
string curNum;
vector<bool> check;
int numberSize;
int primeCount = 0;

void search(int depth) {

    for (int i = 0; i < numberSize; i++)
    {
        if (!check[i]) {
            curNum.push_back(numCandidates[i]);
            check[i] = true;

            int num = stoi(curNum);
            if (primes[num]) {
                primeCount += 1;
                primes[num] = false;
            }
            search(depth + 1);

            check[i] = false;
            curNum.pop_back();
        }
    }
}

int solution(string numbers) {
    numberSize = numbers.size();
    numCandidates = numbers;
    check.resize(numberSize);
    curNum.reserve(numberSize);
    get_prime(pow(10, numbers.size()));
    
    // 완전 탐색으로 가능한 후보군 모두 소수인지 비교.
    search(0);

    return primeCount;
}


int main() {
    auto ret = solution("011");
    cout << ret << "\n";
    
    return 0;
}
