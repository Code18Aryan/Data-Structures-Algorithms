
  #include<bits/stdc++.h>
  using namespace std;


  vector<int> mergeSorted(vector<int> &nums1 , vector<int>& nums2){
     
       int m = nums1.size();
       int n = nums2.size();

       int left = 0, right = 0;
       
       vector<int>ans;

       while( left < m && right < n){
         
           if(nums1[left] <= nums2[right]){
             
               ans.push_back(nums1[left]);
               left++;
           }

           else{
             
               ans.push_back(nums2[right]);
               right++;
           }
       }


       while( left < m){
         
           ans.push_back(nums1[left]);
           left++;
       }

       while( right < n){
         
          ans.push_back(nums2[right]);
          right++;
       }


       return ans;
  }



  int main(){
     
      vector<int>nums1 = {2,48,98,45,10,30};
      vector<int>nums2 = {46,24,67,27,89,81,97,76,85};

      int m = nums1.size();
      int n = nums2.size();

      vector<int> ans = mergeSorted(nums1,nums2);

      for(auto x : ans){
         
          cout<<x<<" ";
      }
  }