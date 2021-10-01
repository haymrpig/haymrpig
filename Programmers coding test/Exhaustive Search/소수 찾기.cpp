#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

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
