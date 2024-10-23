class Solution {
  public:
   
   

    struct Node {
        
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    
  
    int sumOfLastN_Nodes(struct Node* head, int n) {
        
        
       if( n == 0) return 0;
       
       if( head == NULL) return 0;
       
       if(head -> next == NULL && n == 1) return head -> data;
       
       Node* temp = head;
       
       int len = 0;
       
       int sum = 0;
       
       while(temp != NULL){
            
            len += 1;
            
            temp = temp -> next;
             
       }
       
       temp = head;
      
       
       int length = len -n;
       
       while(length--){
            
            temp = temp -> next;
            
       }
       
       while(temp != NULL){
            
             sum += temp -> data;
             temp = temp -> next;
       }
       
       return sum;
       
       
    }
};