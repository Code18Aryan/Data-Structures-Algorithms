
    
  #include<bits/stdc++.h>
  using namespace std;


   // BruteForce 
   // TC - O(n2)


   int bruteForce(vector<int>&nums , int n){
     
       for(int i=0; i<n; i++){

          int cnt = 0;
         
          for(int j=0; j<n; j++){
             
               if(nums[i] == nums[j]) cnt++;
          }

          if(cnt >= n/2) return nums[i];
       }

       return -1;
       
   }

   // BetterSolution

   int betterSol(vector<int>&nums , int n){

        unordered_map<int,int> mpp;

        for(auto x : nums) mpp[x]++;

        for(auto x : mpp){
             
            if(x.second >= n/2) return x.first;
        }

        return -1;
   }

   // Optimal using moore voting algo


   int mooreVoting(vector<int>&nums , int n){
     
       int cnt = 0;
       int element;

       for(int i=0; i<n; i++){
         
           if(cnt == 0){
             
              element = nums[i];
              cnt++;
           }

           else if( nums[i] == element){
             
              cnt++;
           }

           else cnt--;
       }

       return element;
   }





  int main(){
      

      vector<int> nums = {2,3,3,5,7,4,2,3,3,3,4,5,3,3};

      int n = nums.size();

     // cout<<bruteForce(nums,n);
     
    // cout<<betterSol(nums,n);

    cout<<mooreVoting(nums,n);




  }