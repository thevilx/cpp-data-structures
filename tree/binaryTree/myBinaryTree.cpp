#include <iostream>
#include <cmath>
using namespace std;

class node{
  public:
      int data;
      node* left;
      node* right;

      node(int val){
        data = val;
        left = NULL;
        right = NULL;
      } 
};

// binary tree class

class bt{
  public:
    node* root;

  // empty tree in constructor 
    bt(){
      root = NULL;
    }

  // create a node with givin value and insert it to the tree in recursion way
    node* Insert(node* nod , int val){
        
        if(root == NULL){
          node* newNode = new node(val);
          root = nod = newNode;
        }

        else if(nod == NULL){
          node* newNode = new node(val);
          nod = newNode;
        }

        else if(val <= nod->data){
          nod->left = Insert(nod->left , val);
        }
        else{
          nod->right = Insert(nod->right , val);
        }

        return nod;
    }

  // add is a function for inserting to tree without requrment to use root outside of the class
    void add(int val){
        root = Insert(root , val);
    }

    // min is the value of the leftmost node in tree which we can find with recursion
    int findMin(){
      
      if(root == NULL){
        cout<<"Tree Is Empty!"<<endl;
        return -1;
      }

      node* current = root;
      
      while(current->left != NULL){
        current = current->left;
      }

      return current->data;
    }

    // max is the value of the rightmost node in tree which we can find with recursion
    int findMax(){
      
      if(root == NULL){
        cout<<"Tree Is Empty!"<<endl;
        return -1;
      }

      node* current = root;
      
      while(current->right != NULL){
        current = current->right;
      }

      return current->data;
    }
   
   // this is a function for showing all elements of tree also in a recursion way
    void describe(node* node){
        
        cout<<"Value :"<<node->data<<endl;

        if(node->left != NULL){
          cout<<"Left Node : "<<endl;
          describe(node->left);
        }

        if(node->right != NULL){
          cout<<"Right Node : "<<endl;
          describe(node->right);
        }
    }

    // this function goes into all elements of tree with recursion
    // and check if the givin val variable is present in tree or not
    bool search(node* nod , int val){
      if(nod == NULL) return false;
      else if(nod->data == val) return true;
      else if(val <= nod->data) return search(nod->left , val);
      else return search(nod->right , val);
    }
 
    // this function returns the max number of ways to reach a leaf node which we call height of the tree
    int getNodeHeight(node* root){
      if(root == NULL)
        return -1;
      return max(getNodeHeight(root->left), getNodeHeight(root->right)) + 1;
    }

  // returns true if tree is balanced
    bool isTreeBalanced(){
      if(root == NULL){
        return true;
      }

      int leftHeight = getNodeHeight(root->left);
      int rightHeight = getNodeHeight(root->right);

      return abs(rightHeight - leftHeight) <= 1;
    }
};

int main(){
  bt bt;

//  bt.add(15);
  // bt.add(10);
  // bt.add(20);
  // bt.add(25);
  // bt.add(8);
  // bt.add(12);
  bt.add(1);
  bt.add(2);
  bt.add(3);
  bt.add(4);
  bt.add(5);
  bt.add(6);


  bt.describe(bt.root);

cout<<endl<<"Tree Info : "<<endl<<endl;

  cout<<"Min = "<<bt.findMin()<<endl;
  cout<<"Max = "<<bt.findMax()<<endl;
  
  if(bt.search(bt.root , 20)){
    cout<<"20 Found !"<<endl;
  }
  else{
    cout<<"20 not Found !"<<endl;
  }

  cout<<"Height of root = "<<bt.getNodeHeight(bt.root)<<endl;

  if(bt.isTreeBalanced()){
    cout<<"Tree is balanced !"<<endl;
  }
  else{
    cout<<"Tree is not balanced"<<endl;
  }


}
