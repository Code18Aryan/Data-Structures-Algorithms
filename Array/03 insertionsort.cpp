
   #include<bits/stdc++.h>
   using namespace std;



   void sort(vector<int>& nums , int n){
     
       for(int i=0; i<n; i++){
         
          int j = i;

          while( j > 0 && nums[j-1] > nums[j]){
             
              swap(nums[j-1],nums[j]);

              j--;
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