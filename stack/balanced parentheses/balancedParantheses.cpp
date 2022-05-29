#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool in_array(string input , char ch){
    int len = input.length();

    for(int i = 0 ; i < len ; i++){
      if(input[i] == ch) return true;
    }

    return false;
}

// true when {} false when {]
bool sameType(char peak , char ch){
  switch(peak){
    case '{':
        return (ch == '}');

    case '[':
        return (ch == ']');

    case '(':
        return (ch == ')');

  }

  return false;
}

bool isBalanced(string input){
    stack<char> stack;
    char current , peak;
    
    string open = "{([" , close = "})]";

    // loop throw input string
    for(int i = 0 ; i < input.length() ; i++){
        current = input[i]; 

        // current char is close char like {
        if(in_array(open , current)){ 
          stack.push(current);
        }    
        // current char is close char like }
        else if(in_array(close , current)){
            
            // empty stack
            if(stack.empty()) return false;

            peak = stack.top();

            if(sameType(peak , current))  stack.pop();
            else  return false;
      
        }
    }

    return true;
}

int main(){
    string input;
   
    cout<<"Please enter the parentheses : (etc. ' { (  [ ] ) } '  )"<<endl;
    cin>>input;

    if(isBalanced(input)){
      cout<<"Balanced !";
    }
    else{
      cout<<"Unbalenced !";
    }

}
