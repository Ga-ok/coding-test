#include <string>
#include <vector>
#include <iostream>

using namespace std;

int person1[]={1, 2, 3, 4, 5};
int person2[]={2, 1, 2, 3, 2, 4, 2, 5};
int person3[]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    for(int i=0; i<answers.size(); i++){
        
        if(i==0){
            if(answers[i]==person1[i]) cnt1+=1;
            if(answers[i]==person2[i]) cnt2+=1;
            if(answers[i]==person3[i]) cnt3+=1;
        }
        else {
            if(answers[i]==person1[i%5]) cnt1+=1;
            if(answers[i]==person2[i%8]) cnt2+=1;
            if(answers[i]==person3[i%10]) cnt3+=1;
        }
        
    }
   
    int maxPoint=-2134567890;
    if(maxPoint < cnt1){
        maxPoint=cnt1;
    }
    if(maxPoint < cnt2){
        maxPoint=cnt2;
    }
    if(maxPoint < cnt3){
        maxPoint=cnt3;
    }
    
    if(maxPoint==cnt1) answer.push_back(1);
    if(maxPoint==cnt2) answer.push_back(2);
    if(maxPoint==cnt3) answer.push_back(3);
    
    
    return answer;
}