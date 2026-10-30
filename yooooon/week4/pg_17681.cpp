// https://school.programmers.co.kr/learn/courses/30/lessons/17681

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string tmp = "";
    
    for(int i=0; i<n; i++){
        tmp = "";
        
        int a = arr1[i] | arr2[i];
        
        for(int j= n-1; j>=0; j--){
            if(a & (1<<j)) tmp += "#";
            else tmp += " ";

            a >> 1;
        }
        answer.push_back(tmp);
    }
    return answer;
}

// // https://school.programmers.co.kr/learn/courses/30/lessons/17681

// #include <string>
// #include <vector>

// using namespace std;

// vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
//     vector<string> answer;
//     string tmp = "";
    
//     for(int i=0; i<n; i++){
//         tmp = "";
        
//         int a = arr1[i] | arr2[i];

//         for (int j = 0; j < n; j++){
//             if((a & 1) == 1)
//                 tmp = "#" + tmp;
//             else
//                 tmp = " " + tmp;
            
//             a >>= 1;
//         }
//             answer.push_back(tmp);
//     }
//     return answer;
// }