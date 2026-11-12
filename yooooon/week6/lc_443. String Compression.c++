//https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int read = 0;
        int write = 0;
        // read : 원본 데이터를 읽는 위치
        // write : 압축 결과를 덮어쓰는 위치

        while (read < n) {
            char current = chars[read];
            int end = read;

            // 1. 연속된 같은 문자 개수 세기
            while (end < n && chars[end] == current) {
                end++;
            }

            int count = end - read;

            // 2. 문자 저장
            chars[write] = current;
            write++;

            // 3. 2개 이상이면 개수 저장
            if (count > 1) {
                string num = to_string(count);

                for (char c : num) {
                    chars[write++] = c;
                }
            }

            // 4. 다음 그룹으로 이동
            read = end;
        }

        return write;
    }
};
