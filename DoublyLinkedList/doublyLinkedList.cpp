#include <iostream>

using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
      this->data = value;
      next = NULL;
      prev = NULL;
    }
};

class dlinkList{
  public:
    Node* head;
    int count;

    dlinkList(){
      head = NULL;
      count = 0;
    }

    void addToHead(int value){
      Node* newNode = new Node(value);
      
      newNode->next = head;
      newNode->prev = NULL;

      head = newNode;

      count++;
    }

    void addToTail(int value){
      Node* newNode = new Node(value);
      Node* endNode = head;

      while(endNode->next != NULL){
        endNode = endNode->next;
      }
          
      endNode->next = newNode;
      newNode->prev = endNode;
      count++;
    }

    void addToAt(int pos , int value){
      Node* newNode = new Node(value);
      Node* posNode = head;
      
      if(pos == 0){
        this->addToHead(value);
        return;
      }

      for(int i = 0 ; i < pos - 1 ; i++){
          posNode = posNode->next;
      }
      
      Node* tmp = posNode->next;
      posNode->next = newNode;
      newNode->prev = posNode;
      newNode->next = tmp;
      tmp->prev = newNode;
      count++;
    }

    void deleteHead(){      
      Node* nextElement = head->next;
      nextElement->prev = NULL;
      head = nextElement;
      count--;
    }

    void deleteTail(){
      
      if(head->next == NULL){
        head = NULL;
        return;
      }

      Node* end = head;
      
      while(end->next->next != NULL){
          end = end->next;
      }
      
      end->next = NULL;
      count--;
    }

    void deleteAt(int pos){
      
      if(pos == 0){
        this->deleteTail();
        return;
      }

      if(pos > count || pos < 0){
        cout<<"Position out of bond !";
        return;
      }



      Node* current = head;

      for(int i = 0 ; i < pos ; i++){
        current = current->next;
      }
     
      Node* nextElement = current->next;
      Node* prevElement = current->prev;

      prevElement->next = nextElement;
      nextElement->prev = prevElement;
      count--;
    }

      
    void reverse(){
      Node* temp = NULL;
      Node* current = head;

      while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
      }

      if(temp != NULL){
        head = temp->prev;
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
  dlinkList d;

  d.addToHead(5);
  d.addToHead(3);
  d.addToHead(8);
  d.addToTail(4);
  d.addToAt(2 , 24);
  d.deleteHead();
  d.deleteAt(1);
  d.reverse();
  d.describe();
}
