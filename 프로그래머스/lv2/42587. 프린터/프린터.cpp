#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<pair<int, int>> docs;
    for(int i=0; i<priorities.size(); i++){
        docs.push_back({i, priorities[i]});
    }
    
    vector<int> order;
    while(!docs.empty()){
        pair<int,int> doc=docs[0];
        docs.erase(docs.begin());
        
        int flag=0;
        for(int i=0; i<docs.size(); i++){
            if(docs[i].second > doc.second){
                docs.push_back(doc);
                flag=1;
                break;
            }
        }
        
        if(flag==0){
            order.push_back(doc.first);
        }
    }
    
    for(int i=0; i<order.size(); i++){
        if(location==order[i]){
            answer=i+1;
            break;
        }
    }
    
    return answer;
}