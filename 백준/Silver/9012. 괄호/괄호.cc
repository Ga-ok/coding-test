#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    int test;
    cin>>test;

    for(int testcase=0; testcase<test; testcase++){

        string str;
        cin>>str;

        int flag=0;
        vector<int> stack;
        for(int i=0; i<str.length(); i++){
            if(str[i]=='(') stack.push_back(str[i]);
            else if(str[i]==')') {
                if(stack.size()==0){
                    flag=1;
                    break;
                }
                else stack.pop_back();
            }
        }

        if(flag) cout<<"NO\n";
        else{
            if(stack.size()!=0) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }   

    return 0;
}