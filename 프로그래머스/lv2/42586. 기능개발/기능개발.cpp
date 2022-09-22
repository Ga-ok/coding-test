#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> time;
    for(int i=0; i<progresses.size(); i++){
        if((100 - progresses[i])%speeds[i]==0){
            time.push_back((100 - progresses[i])/speeds[i]);
        }
        else{
            time.push_back((100 - progresses[i])/speeds[i] + 1);
        }
    }
    
    int cnt=0;
    for(int i=0; i<time.size(); i++){
        int now=time[i];
        
        int j=i;
        while(j<time.size()){
            if(now >= time[j]) {
                cnt++;
                j++;
            }
            else{
                // i=j;
                answer.push_back(cnt);
                cnt=0;
                break;
            }
        }
        i=j-1;
    }
    
    answer.push_back(cnt);
    
    return answer;
}