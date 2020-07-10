/**
 * Title: 집합
 * Problem no. 11723
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/11723
 */

#include <iostream>
#include <algorithm>
//#include <set>
#include <array>

using namespace std;

/**
 * add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
 * remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
 * check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
 * toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
 * all: S를 {1, 2, ..., 20} 으로 바꾼다.
 * empty: S를 공집합으로 바꾼다. 
 */
array<bool, 20> S = {false};

const string commands[] = {
    "add",
    "remove",
    "check",
    "toggle",
    "all",
    "empty",
};

void add(int x) {
    S[x-1] = true;
}

void remove(int x) {
    S[x-1] = false;
}

bool check(int x) {
    return S[x-1];
}

void toggle(int x) {
    if (check(x)) {
        remove(x);
        return;
    }
    add(x);
}

void all() {
    for (int i = 0; i < 20; i++)
    {
        S[i] = true;
    }
}

void empty() {
    for (int i = 0; i < 20; i++)
    {
        S[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int nCommand = 0;
    cin >> nCommand; // up to 3,000,000

    for (int c = 0; c < nCommand; c++)
    {
        string command;
        cin >> command;

        // 스트링 비교 보다는 그냥 첫 번째 문자만 비교해서 처리.
        if (command[0] == commands[0][0] && command[1] == commands[0][1]) { // 'a'랑 'd' 문자 비교
            int x;
            cin >> x;
            add(x);
        }
        else if (command[0] == commands[1][0]) { 
            int x;
            cin >> x;
            remove(x);
        }
        else if (command[0] == commands[2][0]) {
            int x;
            cin >> x;
            cout << check(x) << '\n';
        }
        else if (command[0] == commands[3][0]) {
            int x;
            cin >> x;
            toggle(x);
        }
        else if (command[0] == commands[4][0] && command[1] == commands[4][1]) {
            all();
        }
        else if (command[0] == commands[5][0]) {
            empty();
        }

        // cout << "{";
        // for (auto it = S.begin(); it != S.end(); ++it)
        // {
        //     cout << *it << ", ";
        // }
        // cout << "}\n";
    }

    return 0;
}