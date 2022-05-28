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
  node* node;
  node = btz.Insert(node , 15);
  node = btz.Insert(node , 10);
  node = btz.Insert(node , 20);
  node = btz.Insert(node , 25);
  node = btz.Insert(node , 8);
  node = btz.Insert(node , 12);
   btz.describe(btz.root);

  if(btz.search(btz.root , 200)){
    cout<<"Found that shit"<<endl;
  }
  else{
    cout<<"No bitch number found !"<<endl;
  }
  //btz.describe(btz.root);
  //btz.Insert(25);
  //btz.Insert(8);
  //btz.Insert(12);
}
