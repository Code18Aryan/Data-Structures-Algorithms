
   #include<bits/stdc++.h>
   using namespace std;



   void sort(vector<int>& nums , int n){
     
       for(int i=0; i<n-1; i++){
         
           int mini = i;

           for(int j=i+1; j<n; j++){
             
               if(nums[j] < nums[mini]) mini = j;
           }

           swap(nums[i],nums[mini]);
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