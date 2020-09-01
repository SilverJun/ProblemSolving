#include <string>
#include <vector>

using namespace std;

#include <iostream>

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);

    // cout << yellow/2+1 << ", " << yellow+2 << "\n";
    for (int h = 1; h <= yellow; h++)
    {
        if (yellow%h != 0) continue; // 나누어 떨어질때만 확인하도록!
        int w = yellow/h;
        const int check = (w+2)*(h+2)-yellow;
        // cout << w << " * " << h << " = " << w*h << "\n";
        if (check == brown) {
            answer[0] = w+2;
            answer[1] = h+2;
            return answer;
        }
    }
    return answer;
}

/*
10	2	[4, 3]
8	1	[3, 3]
24	24	[8, 6]
*/
int main() {
    //auto ret = solution({3, 0, 6, 1, 5});
    auto ret = solution(24, 24);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << ", ";
    }
    cout << "\n";
    
    return 0;
}