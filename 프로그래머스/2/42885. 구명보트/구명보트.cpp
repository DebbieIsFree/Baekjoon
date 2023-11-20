#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());  // 사람들을 몸무게 순으로 정렬
    
    int left = 0;  // 가장 가벼운 사람을 가리키는 인덱스
    int right = people.size() - 1;  // 가장 무거운 사람을 가리키는 인덱스

    while (left <= right) {
        // 가장 가벼운 사람과 가장 무거운 사람을 함께 태울 수 있으면 함께 태우고 인덱스를 이동
        if (people[left] + people[right] <= limit) {
            left++;
            right--;
        } else {
            // 가장 무거운 사람만 태울 수 있으면 가장 무거운 사람만 태우고 인덱스 이동
            right--;
        }
        answer++;  // 보트 개수 증가
    }

    return answer;
}