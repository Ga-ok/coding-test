#include <string>
#include <vector>

using namespace std;

int visited[201];

void dfs(int node, int n, vector<vector<int>> computers){
    
    for(int i=0; i<n; i++){
        if(visited[i]!=0) continue;
        if(computers[node][i]!=1) continue;
        
        visited[i]=1;
        dfs(i, n, computers);
        // visited[i]=0;
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<computers[0].size(); j++){
            if(visited[i]!=0) continue;
            if(computers[i][j]!=1) continue;
            
            visited[j]=1;
            dfs(j, computers[0].size(), computers);
            answer++;
        }
    }
    
    return answer;
}