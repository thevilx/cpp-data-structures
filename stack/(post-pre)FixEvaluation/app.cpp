#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool is_operator(char ch){
  string op = "*-+/";

  for(int i = 0 ; i < 4 ; i++){
    if(op[i] == ch) return true;
  }

  return false;
}

// calculate operation
void calOperation(stack<int> &stack , char operation , bool reverse = false){
  int a = stack.top();
  stack.pop();
  int b = stack.top();
  stack.pop();
  
  if(reverse){
   swap(a , b); 
  }

  switch (operation)
  {
      case '+': stack.push(a + b); break;
      case '-': stack.push(a - b); break;
      case '*': stack.push(a * b); break;
      case '/': stack.push(a / b); break;
  }
}


int evaluatePostFix(string operation){
  stack<int> stack;
  int a , b;
  for(int i = 0 ; i < operation.length() ; i++){
    
    // skip spaces    
    if(operation[i] == ' ') continue;

    // if char is operator
    else if(is_operator(operation[i])){
      calOperation(stack , operation[i] , true);      
    }

    // if char is digit
    else{

      int num = 0;
      
      while(isdigit(operation[i])){
          num = num * 10 + (int)(operation[i] - '0');
          i++;
      }
      i--;

      stack.push(num);
    }

  }
  return stack.top();
}


int evaluatePreFix(string operation){
    stack<int> stack;
 
  for(int i = operation.length() - 1 ; i >= 0  ; i--){
    // skip spaces    
    if(operation[i] == ' ') continue;

    // if char is operator
    else if(is_operator(operation[i])){
      
      calOperation(stack , operation[i]);
    }

    // if char is digit
    else{
      int num = 0;
      int start = i;

      // go to start of number digit 
      while(isdigit(operation[i])){
          i--;
      }
      i++;

      int end = i;

      // str digits to integer
      while(i <= start){
        num = num * 10 + (int)(operation[i] - '0');
        i++;
      }
      
      i = end; // set the i to the start of digits

      stack.push(num);
    }

  }
  return stack.top();
}


int main(){

  string postfix = "11 11*9-" , prefix = "-+* 2 3 * 5 4 19";  
  cout<<evaluatePostFix(postfix)<<endl;
  cout<<evaluatePreFix(prefix);  
}
