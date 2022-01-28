#include <iostream>

using namespace std;

#define MAX_STACK_SIZE 10

class Stack{
    public:
        int *arr;
        int top;  
        Stack(int n = MAX_STACK_SIZE){
            arr = new int[n];
            top = -1;
        }

        bool isFilled(){
            return MAX_STACK_SIZE < top;
        }

        void push(int n){
            if(isFilled()){
               cout<<"Stack is full\n";
               exit(EXIT_FAILURE);
            }
            arr[++top] = n;
        }

        int pop(){
            if(isFilled()){
               cout<<"Stack is full\n";
               exit(EXIT_FAILURE);
            }

            return arr[--top];
        }

        bool isEmpty(){
            return top == -1;
        }

        int peek(){
            if (isEmpty()) {
                cout<<"Stack is empty\n";
                exit(EXIT_FAILURE);
            }
            return arr[top];
        }

        void describe(){
            for(int i=0;i <= top ; i++){
                cout<<arr[i]<<endl;
            }
        }
};

int main(){
    Stack stack;
    stack.push(1);
    // cout<<stack.peek()<<endl;
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.push(6);
    stack.describe();
    return 0;
}

