#include<bits/stdc++.h>
using namespace std;

class solution{

 public:

    vector<int> nearGreatestToLeft(vector<int>&nums){
         
          vector<int> ans;

          int n = nums.size();

          if( n == 0) return ans;

          stack<int> st;

          for(int i=0; i<n; i++){
             
              if(st.empty()) ans.push_back(-1);

              else if(st.size() > 0 && st.top() > nums[i]) ans.push_back(st.top());

              else if(st.size() > 0 && st.top() <= nums[i]){
                 
                  while(st.size() > 0 && st.top() <= nums[i]) st.pop();

                  if(st.empty()) ans.push_back(-1);

                  else ans.push_back(st.top());
              }

              st.push(nums[i]);
          }

          return ans;
    }


};




int main(){


    solution leetcode;

    vector<int> nums = {1,3,5,2,1,4,5};

   vector<int> ans =  leetcode.nearGreatestToLeft(nums);

   for(auto x : ans){
     
      cout<<x<<" ";
   }

    

     
      
}