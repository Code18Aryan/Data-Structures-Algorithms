#include<bits/stdc++.h>
using namespace std;

// Defination -> 
// smallest index where the element at that index is greater than the target 


int findUpperBound(vector<int>&nums, int target){

    int low = 0;
    int high = nums.size()-1;
    int ans = -1;

    while(low <= high){

        int mid = low + (high-low)/2;

        if(mid > target){

            ans = mid;
            high = mid-1;
        }

        else low = mid+1;
    }

    return ans;


}


                 
int main(){

    vector<int> nums = {1,3,4,4,5,6,10};
    int target = 7;

    cout<<findUpperBound(nums,target);


    return 0;
}