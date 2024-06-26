
   #include<bits/stdc++.h>
   using namespace std;



   void sort(vector<int>& nums , int n){
     
       for(int i=n-1; i>=0; i--){
         
          for(int j=0; j<=i-1; j++){

               if(nums[j] > nums[j+1]){
                  
                    swap(nums[j],nums[j+1]);
               }
          }
       }
   }


   int main(){
     
        vector<int> nums = {8,66,43,46,86,33,27,63,87,30,37,90};
        int n = nums.size();

        sort(nums,n);

        for(auto x : nums){
             
              cout<<x<<" ";
        }


   }