#include <iostream>

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
    // node* nodadd;

    bt(){
      root = NULL;
    }

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

    void add(int val){
        root = Insert(root , val);
    }

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

    bool search(node* nod , int val){
      if(nod == NULL) return false;
      else if(nod->data == val) return true;
      else if(val <= nod->data) return search(nod->left , val);
      else return search(nod->right , val);
    }

};

int main(){
  bt btz;

  btz.add(15);
  btz.add(10);
  btz.add(20);
  btz.add(25);
  btz.add(8);
  btz.add(12);

  btz.describe(btz.root);

  cout<<"Min = "<<btz.findMin()<<endl;
  cout<<"Max = "<<btz.findMax()<<endl;
  
  if(btz.search(btz.root , 20)){
    cout<<"Number Found !"<<endl;
  }

  else{
    cout<<"No Number Found !"<<endl;
  }

}
