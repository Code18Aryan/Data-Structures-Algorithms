#include<bits/stdc++.h>
using namespace std;

int lowerBound(const vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    int ans = -1;
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target) {

            left = mid + 1; 
            ans = mid;
        }
        
        else {
            right = mid; 
        }
    }

    return ans; 
}
                 
int main(){
           
       vector<int> nums = {8, 66, 43, 46, 86, 33, 27, 63, 87, 30, 37, 90};
       int n = nums.size();
       sort(nums.begin(), nums.end());
       for(auto x : nums){
           cout << x << " ";
           // This will print the sorted array
       }
       cout << endl;
       int target = 46;
       int result = lowerBound(nums, target);
       if (result != -1) {
           cout << "Lower bound of " << target << " is at index: " << result << endl;
       } else {
           cout << "No lower bound found for " << target << endl;
       }     
   
            
            
 return 0;
}