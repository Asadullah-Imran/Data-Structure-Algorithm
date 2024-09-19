# include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkPalindrome(string str){
    stack <char> s1,s2,s3;
    //step 1
    for(int i=0;str[i]!='\0';i++) {
        s1.push(str[i]);
    }
    s2=s1;

    while(!s1.empty()){
        char c= s1.top();
        s1.pop();
        s3.push(c);
    }

    //step 4

    while(!s2.empty()){
        if(s2.top()!=s3.top()) return false;

        s2.pop();
        s3.pop();
    }
    //if stacks are empty   it is pallindrome
    return true;
}

int main(){
    string str="aba";
    
    if(checkPalindrome(str)){
        cout<<"This is pallindrome"<<endl;
    }else{
        cout<<"This is not pallindrome"<<endl;

    }
}