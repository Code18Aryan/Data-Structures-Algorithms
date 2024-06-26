
   #include<bits/stdc++.h>
   using namespace std;


   int partition(vector<int>& nums , int low , int high){
     
       int pivot = nums[low];

       int i = low;
       int j = high;

       while( i < j){
         
            while( nums[i] <= pivot && i <= high-1) i++;

            while( nums[j] > pivot && j >= low +1) j--;

            if( i < j) swap(nums[i],nums[j]);
       }

       swap(nums[low],nums[j]);

       return j;
   }


   void quickSort(vector<int>&nums , int low , int high){
     
       if( low < high){
         
           int partitionIndex = partition(nums , low , high);

           quickSort(nums , low , partitionIndex-1 );
           quickSort(nums , partitionIndex +1 , high);
       }
   }


   int main(){
     
        vector<int> nums = {8,66,43,46,86,33,27,63,87,30,37,90};
        int n = nums.size();

        quickSort(nums,0,n-1);

        for(auto x : nums){
             
              cout<<x<<" ";
        }


        return 0;

   }