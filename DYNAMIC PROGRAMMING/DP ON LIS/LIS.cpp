#include<bits/stdc++.h>
using namespace std;

int Lis(int index, int prevIndex, vector<int>& nums, vector<vector<int>>& dp) {
    if (index == nums.size()) return 0;

    if (dp[index][prevIndex + 1] != -1) return dp[index][prevIndex + 1];

    int take = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
        take = 1 + Lis(index + 1, index, nums, dp);
    }
    
    int notTake = Lis(index + 1, prevIndex, nums, dp);

    return dp[index][prevIndex + 1] = max(take, notTake);
}
                 
int main(){
           
            
   vector<int> nums = {8, 66, 43, 46, 86, 33, 27, 63, 87, 30, 37, 90};

   vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
   int n = nums.size();

   int maxLength = Lis(0, -1, nums, dp);

   cout << "Length of Longest Increasing Subsequence: " << maxLength << endl;


            
            
 return 0;
}