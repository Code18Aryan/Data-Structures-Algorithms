#include<bits/stdc++.h>
using namespace std;

bool binarySearchIterative(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }
         else if (nums[mid] < target) {
            left = mid + 1; 
        } 
        else {
            right = mid - 1;
        }
    }

    return false; 

}


bool binarySearchRecursive(const vector<int>& nums, int target, int left, int right) {
    
    if (left > right) {
        return false; 
    }

    int mid = left + (right - left) / 2;

    if (nums[mid] == target) {
        return true;
    } 
    else if (nums[mid] < target) {
        return binarySearchRecursive(nums, target, mid + 1, right);
    } 
    else {
        return binarySearchRecursive(nums, target, left, mid - 1);
    }
}
                 
int main(){
           
            
    vector<int> nums = {8, 66, 43, 46, 86, 33, 27, 63, 87, 30, 37, 90};
             int n = nums.size();

             sort(nums.begin(), nums.end());

             for(auto x : nums){
                 cout << x << " ";
             }
             
             cout << endl;
            
            
 return 0;
}