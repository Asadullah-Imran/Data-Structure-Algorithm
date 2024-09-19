#include <iostream>
#include <string>
#include <stack>
using namespace std ;

bool validateBrackets(string input){
stack<char> brackets;

for(int i=0;i<input.size();i++){
    if(input.at(i)=='('){
        // handle case
        brackets.push('(');
    }else if (input.at(i)==')'){
        // handle case
        if(brackets.empty()){
            return false;
        }
    }
}
}


int main(){

string input;



input = "(()())()(())";

validateBrackets(input);



}
