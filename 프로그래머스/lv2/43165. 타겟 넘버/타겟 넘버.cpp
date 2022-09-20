#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[]={-1, 1};
int cnt=0;
int visited[21]={0};
vector<int> path;
void dfs(vector<int> numbers, int n, int target, int level, int res){
    
    if(level==n){
        if(res==target){
            cnt+=1;
        }
        return;
    }

    dfs(numbers, n, target, level+1, res+numbers[level]);
    dfs(numbers, n, target, level+1, res-numbers[level]);
    
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, numbers.size(), target, 0, 0);
    answer=cnt;
    return answer;
}