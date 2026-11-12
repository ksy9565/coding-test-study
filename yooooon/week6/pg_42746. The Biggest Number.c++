//https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    vector<string> v;

    // 1. 숫자를 문자열로 변환
    for (int num : numbers) {
        v.push_back(to_string(num));
    }

    // 2. 이어 붙인 결과를 기준으로 정렬
    sort(v.begin(), v.end(), [](string a, string b) {
        return a + b > b + a;
    });

    // 3. 전부 0인 경우
    if (v[0] == "0") {
        return "0";
    }

    // 4. 정렬된 문자열 이어 붙이기
    string answer = "";
    for (string s : v) {
        answer += s;
    }

    return answer;
}
