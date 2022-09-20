#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int dy[]={-1, 1, 0, 0};
int dx[]={0, 0, -1, 1};
int visited[101][101];

int n;
int m;

struct node{
    int y;
    int x;
};

void bfs(int y, int x, vector<vector<int> > maps){
    
    queue<node> q;
    q.push({y, x});
    visited[y][x]=1;
    
    while(!q.empty()){
        
        node now = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int ny=now.y+dy[i];
            int nx=now.x+dx[i];
            
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(visited[ny][nx]!=0) continue;
            if(maps[ny][nx]==0) continue;
            
            visited[ny][nx]=visited[now.y][now.x]+1;
            q.push({ny, nx});
        }
        
    }
    
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    bfs(0, 0, maps);
    
    answer = visited[n-1][m-1];
    
    if(answer==0) answer = -1;
    
    return answer;
}