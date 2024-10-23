 
 #include<bits/stdc++.h>
 using namespace std;


  class Node{
     
     public:

      int data;
      Node* left;
      Node* right;

      Node(int data){
         
          this -> data = data;
          this -> left = NULL;
          this -> right = NULL;
      }
  };


  class Solution{
     
       
   private:
  
   bool getPathSum(Node* root, int target , int & sum){
        
         if(root == NULL) return false;
         
         sum += root -> data;
         
         if( sum == target && root -> left == NULL && root -> right == NULL) return true;
         
         if( getPathSum( root -> left , target , sum) || getPathSum(root -> right , target , sum)) return true;
         
         sum -= root -> data;
         
         return false;
   }
    
    
      
    public:

    bool hasPathSum(Node *root, int target) {
        
        int sum = 0;
       
       return getPathSum(root,target,sum);
    }
};
  





  int main(){

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    Solution gfg;

    cout<<"Checking for path sum equal to 2"<<endl;

    if(gfg.hasPathSum(root , 2 )){
         
          cout<<"True"<<endl;
    }

    else cout<<"False"<<endl;

    cout<<"Checking for path sum equal to 4"<<endl;

     if(gfg.hasPathSum(root , 4 )){
         
          cout<<"True"<<endl;
    }

    else cout<<"False"<<endl;



     
  }