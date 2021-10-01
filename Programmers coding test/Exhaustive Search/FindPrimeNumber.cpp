#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

/*
    1. string에서 vector로 숫자 하나씩 저장
    2. 숫자 자리수만큼 배열에 prime number 찾아서 1저장
    3. DFS를 통해 가능한 조합 모두 추출 ( 단, 0이 첫째자리일 경우 제외 ) -> 만들고자하는 자리수의 숫자가 되면 map에 string 형태로 삽입
    4. map에 저장된 string을 int로 변경 후, prime number인지 확인 -> 맞을 경우 answer+1
    
    < 수정해야할 사항 >
    - prime number 찾는 알고리즘 구현을 비효율적으로 for문을 두번 돌렸기에 수정 필요
    - 조합을 구할 때 DFS보다 next_permutation 이용하면 편하게 구현 가능하기에 수정 필요
*/
void DFS(vector<char> v, vector<int>& visited,int num, int depth, string s, map<string, string>& m){
    if( depth == num ){
        m[s]=s; 
        return;
    } 
    for(int i=0;i<v.size();i++){
        if( v[i] == '0' && s.size()==0 ) continue;
        else if( visited[i] == 0 ) {
            visited[i] = 1;
            s += v[i];
            DFS(v, visited, num, depth+1, s, m);
            s.erase(s.size()-1, 1);
            visited[i] = 0;
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    map<string, string> m;
    float max = 9.999999*pow(10,numbers.size()-1);
    int arr[10000000]={1,};
    
    for(int i=2;i<10000000;i++){
        arr[i]=1;
    }
    for(int i=2;i<=sqrt(int(max));i++){
        for(int j=i*2;j<=int(max);j+=i){
            arr[j] = 0;
        }
    }
    for(int i=0;i<numbers.size();i++){
        v.push_back(numbers[i]);
    }
    
    for(int i=1;i<=numbers.size();i++){
        vector<int> visited(numbers.size(), 0);
        string s="";
        DFS(v, visited, i, 0, s, m);
    }
    
    for(auto iter=m.begin();iter!=m.end();iter++){
        if( arr[stoi(iter->second)] == 1 ) answer++;
    }
    
    return answer;
}
