  
  #include<bits/stdc++.h>
  using namespace std;

   
    // Brute Force solution using extra space 
    // TC - O(2n)



    void bruteForce(vector<int>&nums){
         
          int cntZero = 0, cntOne = 0, cntTwo = 0;

          for(int i=0; i<nums.size(); i++){

             if(nums[i] == 0) cntZero++;

             else if( nums[i] == 1) cntOne++;

             else cntTwo++;
          }

          for(int i=0; i<cntZero; i++){
             
             nums[i] = 0;
          }

          for(int i=cntZero;i<cntZero+cntOne; i++){
             
              nums[i] = 1;
          }

          for(int i=cntZero+cntOne; i<nums.size(); i++){
             
              nums[i] = 2;
          }


    }


    // Better Force using sorting 
    // TC - O(nlogn)


    void merge(vector<int>&nums , int low , int mid , int high){
         
          vector<int>ans;

          int left = low;
          int right = mid+1;

          while( left <= mid && right <= high){
             
              if(nums[left] <= nums[right]){
                 
                  ans.push_back(nums[left++]);
              }

              else{
                 
                  ans.push_back(nums[right++]);
              }
          }

          while(left <= mid){
             
             ans.push_back(nums[left++]);
          }

          while( right <= high){
             
               ans.push_back(nums[right++]);
          }

          for(int i=low; i<=high; i++){
             
               nums[i] = ans[i-low];
          }

    }




    void mergeSort(vector<int>&nums , int low , int high){
         
          if( low >= high) return;

          int mid = (low + high)/2;

          mergeSort(nums , low , mid);
          mergeSort(nums , mid+1 , high);
          merge(nums, low , mid , high);
    }


    // Optimal using Dutch National Flag Algo
    // TC - O(n)


     void dutchNationalFlag(vector<int>&nums){
          
          int n = nums.size();

          int low = 0;
          int mid = 0;
          int high = nums.size()-1;

          while( mid <= high){
             
              if(nums[mid] == 0){
                 
                  swap(nums[low++],nums[mid++]);
              }

              else if( nums[mid] == 1){
                 
                  mid++;
              }

              else{
                  
                  swap(nums[mid],nums[high]);

                  high--;
              }
          }
     }



  int main(){
     
      vector<int> nums = { 0,1,1,0,2,2,1,2,0,0,2,0,2,1};

      int n = nums.size();

      cout<<"Before Sorting"<<endl;

      for(auto x : nums) cout<<x<<" ";

      cout<<endl;

      cout<<"After Sorting"<<endl;

      mergeSort(nums,0,nums.size()-1);

      bruteForce(nums);

      dutchNationalFlag(nums);


      for(auto x : nums) cout<<x<<" ";

      cout<<endl;

    
    





  }