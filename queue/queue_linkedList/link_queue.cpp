#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    Node(int value){
      this->data = value;
      this->next = NULL;
    };
};

class LinkedQueue{
    public:
      Node* head;
      Node* tail;

      LinkedQueue(){
        head = NULL;
        tail = NULL;
      }

      void enQueue(int x){
          Node* newNode = new Node(x);

          if(head == NULL && tail == NULL){
            head = newNode;
            tail = newNode;
          }
          tail->next = newNode;
          tail = newNode;
      }

      void deQueue(){
        Node* temp = head;

        if(head == NULL)  return;
        if(head == tail){
          head = NULL;
          tail = NULL;
        }
        else{
          
          head = head->next;
         
          free(temp);
        }
      }

      void describe(){
        Node* current = head;

        while(current != NULL){
          cout<<current->data<<" ";
          current = current->next;
        }
      }
};

int main(){
 LinkedQueue q;
 q.enQueue(5);
 q.enQueue(6);
 q.enQueue(8);
 q.enQueue(9);
 q.deQueue();
 q.deQueue();
 q.enQueue(11);

 q.describe();
}
