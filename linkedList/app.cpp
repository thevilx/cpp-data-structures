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

class LinkedList{
    public:
      Node* head;
      int count;

      LinkedList(){
        head->next = NULL;
        count = 0;
      }

      // insert at the start of the linked list
      void insertHead(int value){
        Node *newNode = new Node(value);
        newNode->next = head->next;
        head->next = newNode;

        count++;
      }

      // insert at the end of the linked list
      void insertTail(int value){
        Node *newNode = new Node(value);
      
        Node* end = head->next;
          
        while(end->next != NULL){
          end = end->next;
        }
        
        end->next = newNode;  
        count++;
      }        

      // Insert a node at givin posision 
      void insertAt(int pos  ,int value){       
        if(count <= pos || pos < 0){
          cout<<"Position out of bonds\n";
          return;
        }

        if(pos == 0){
          this->insertHead(value);
          return;
        }
          
        Node* current = head;

        for(int i = 0 ; i < pos ; i++){
          current = current->next;
        }
        
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;

        count++;
      }
      
      // remove firstElement of linkedList
      void deleteHead(){
          if(count == 0){
            cout<<"Empty Array !";
            return;
          }

          head->next = head->next->next;
      }
      
      // remove last element of linkedList
      void deleteTail(){
        Node* current = head->next;
        Node* end;

        while(current->next != NULL){
          end = current;
          current = current->next;
        }

        end->next = NULL;
      }
      
      // Delete a node at givin postion if postion is valid
      void deleteAt(int pos){

          Node* current = head->next;
          Node* perv;
          
          if(pos == 0){
            this->deleteHead();
            return;
          }

          for(int i = 0 ; i < pos ; i++){
            perv = current;
            current = current->next;
          } 
          
          perv->next = current->next;
          current->next = NULL;
          
      }

      // reverse the linked list
      void reverse(){
        Node *current = head->next;
        Node *prev = NULL;
        Node *next;
        
        while(current != NULL){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
        }
        // set head to end of the linked list
        head->next = prev;
      }
     
      // Reverse Linked List in recursive algo
      void recursiveReverse(Node *node){
          if(node->next == NULL){
            head->next = node;
            return;
          }

          recursiveReverse(node->next);
          
          Node* newNode = node->next;
          newNode->next = node;
          node->next = NULL;
      }

      void describe(){
        Node *current = head->next;

        while(current != NULL){
          cout<<current->data<<" ";
          current = current->next;
        }

      }

};

int main(){
   LinkedList a;
   a.insertHead(5);
   a.insertHead(3);
   a.insertHead(8);
   a.insertTail(1);
   a.insertTail(2);
   a.insertTail(9);
   a.insertAt(1 , 25);
   a.deleteTail();
   a.deleteTail();
   a.deleteAt(0);
   // a.reverse();
   // a.recursiveReverse(a.head);
   a.describe();
}
