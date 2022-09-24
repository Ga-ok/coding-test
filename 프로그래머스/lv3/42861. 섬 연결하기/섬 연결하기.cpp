#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
    int from;
    int to;
    int cost;
};

int parent[101];
vector<Node> island;

bool cmp(Node a, Node b){
    if(a.cost<b.cost) return true;
    if(a.cost > b.cost) return false;
    return false;
}

int Find(int now){
    if(parent[now]==now) return now;
    int root = Find(parent[now]);
    parent[now]=root;
    return root;
}

void Union(int a, int b){
    int pa=Find(a);
    int pb=Find(b);
    
    parent[pb]=pa;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<101; i++){
        parent[i]=i;
    }
    
    for(int i=0; i<costs.size(); i++){
        island.push_back({costs[i][0], costs[i][1], costs[i][2]});
    }
    
    sort(island.begin(), island.end(), cmp);
    
    for(int i=0; i<island.size(); i++){
        int from=island[i].from;
        int to=island[i].to;
        
        if(Find(from)==Find(to)) continue;
        
        Union(from, to);
        answer+=island[i].cost;
    }
    
    return answer;
}