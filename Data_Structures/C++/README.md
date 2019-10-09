#Add C++ Program Here

Adding an AVL program (in C++) here :


#include<bits/stdc++.h>

using namespace std;

class Node
{

  public:
    int data;
    Node* left;
    Node* right;
    int bal;
    int ht;
    Node(int data){
       this->data = data;
       this->left = NULL;
       this->right = NULL;
       this->ht = 1;
       this->bal = 0;
    }
};

void sethnb(Node* root){
    int lh = root->left == NULL? 0 : root->left->ht;
    int rh = root->right == NULL? 0: root->right->ht;
    
    root->ht = max(lh, rh) +1;
    root->bal = lh -rh;
}
Node* rotate_right(Node* z){
    Node* y = z->left;
    Node* t2 = y->right;

    y->right = z;
    z->left = t2;

    sethnb(z);
    sethnb(y);

    return y;
}
Node* rotate_left(Node* z){
    Node* y = z->right;
    Node* t2 = y->left;

    y->left = z;
    z->right = t2;

    sethnb(z);
    sethnb(y);

    return y;
}

Node* handlebalance(Node* root){
     if(root->bal > 1 && root->left->bal > 0){   // == 2 && == 1   || >1 && >0  || ==2 && > 0
        // LL problem
        root = rotate_right(root);
     }
     else if(root->bal > 1 && root->left->bal <= 0){ // == 2 && == -1  || >1 && <0 || ==2 && <=0
        // LR problem
        root->left = rotate_left(root->left);   // rotating left
        root = rotate_right(root);              // then rotate right
     }
     else if(root->bal < -1 && root->right->bal < 0)   //  == -2 && == -1  || <-1 && <0  || == -2  &&  <0
     { // RR problem
         root = rotate_left(root);        

     }
     else if(root->bal < -1 && root->right->bal >= 0 ){   // == -2  && == 1  || <-1 && >0  || == -2  &&  >=0
          // RL problem
          root->right = rotate_right(root->right);
          root = rotate_left(root);
     }
     return root;
}


Node* construct(vector<int> &dlist, int start, int end){

    if(start> end){
        return NULL;
    }
    int mid = (start+end)/2;

    Node* root = new Node (dlist[mid]);

    root->left = construct(dlist, start, mid-1);
    root->right = construct(dlist, mid+1, end);
    sethnb(root);
    return root;

}

void display(Node* root){

    if(root->left != NULL && root->right != NULL){
        cout<<root->left->data<<"<-";
        cout<<root->data<<"["<<root->ht<<","<<root->bal<<"]";
        cout<<"->"<<root->right->data<<endl;
        display(root->left);
        display(root->right);
    }
    else if(root->left != NULL){
        cout<<root->left->data<<"<-";
        cout<<root->data<<"["<<root->ht<<","<<root->bal<<"]"<<"."<<endl;
        display(root->left);
    }
    else if(root->right != NULL){
        cout<<"."<<root->data<<"->"<<"["<<root->ht<<","<<root->bal<<"]";
        cout<<root->right->data<<endl;
        display(root->right);
    }
    else{
        cout<<"."<<root->data<<"["<<root->ht<<","<<root->bal<<"]"<<"."<<endl;
    }
    
}

int mymin(Node* root){
    if(root == NULL){
      return 0;
    }
    
    if(root->left != NULL){
        return mymin(root->left);
    }else{
        return root->data;
    }
  
}

int mymax(Node* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}



void replace(Node*root, int &sum){
    
    if(root == NULL){
        return;
    }
    replace(root->right, sum);

    int orv = root->data;
    root->data = sum;
    sum += orv;  

    replace(root->left, sum);

}




Node* add(Node*root, int data){

    if(root == NULL){
        root = new Node(data);
        return root;
    }else if(root->data > data){
        root->left = add(root->left, data);
    }
    else if(root->data < data){
        root->right = add(root->right, data);
    }

    sethnb(root);
    root = handlebalance(root);
   return root;
}

Node* remove(Node* root, int data){

    if(root == NULL){
       return NULL;
    }
    if(data > root->data){
        root->right = remove(root->right, data);
    }
    else if(data < root->data){
        root->left = remove(root->left, data);
    }
    else{
          if(root->left != NULL && root->right != NULL){
              int lmax = mymax(root->left);  // calculate the max from the LHS tree and make it the root
              root->data = lmax;
              root->left = remove(root->left, lmax);
          }
          else{
              Node* temp = root;
              root = root->left != NULL?root->left : root->right;
              delete temp;
          }
        //   else if(root->left != NULL){
        //       Node* temp = root;
        //       root= root->left;
        //       delete root;
        //   }
        //   else if(root->right != NULL){
        //       Node* temp = root;
        //       root = root->right;
        //       delete root;
        //   }else{
        //       Node* temp = root;
        //       root = NULL;
        //       delete temp;
        //   }
    }

    if(root != NULL){
       sethnb(root);
       root = handlebalance(root);
    }
    return root;
 
}


int countBST(int n){
    if(n ==0 || n == 1){
        return 1;
    }
    int count = 0;
    for(int i =0; i<n; i++){
        count += countBST(i)+countBST(n-i-1);
    }
    return count;
}

int main(int argc, char** argv){
  
  vector<int> dlist {12,25,37,50,62,75,87};
  Node* root = construct(dlist, 0, dlist.size() -1);
  display(root);
  cout<<endl;
  add(root, 10);
  add(root, 5);
  display(root);
  cout<<"******************************"<<endl;
  add(root, 15);
  display(root);
  cout<<"******************************"<<endl;
  remove(root, 5);
  display(root);
  cout<<"******************************"<<endl;
  remove(root, 10);
  display(root);
}