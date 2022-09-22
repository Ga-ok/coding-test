#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<int> v;
    for(int i=0; i<s.length(); i++){
        if(s[i]==')' && i==0) {
            answer=false;
            break;
        }
        
        if(s[i]==')' && v.size()!=0){
            v.pop_back();
        }
        else if(s[i]=='('){
            v.push_back('(');
        }
    }
    
    if(v.size()!=0) answer=false;
        
    return answer;
}