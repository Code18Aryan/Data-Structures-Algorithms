
   #include<bits/stdc++.h>
   using namespace std;



   void merge(vector<int> &nums, int low, int mid, int high){

                  int left = low;
                  int right = mid+1;

                  vector<int> ans;

                  while( left <= mid && right <=high){
                          
                         if(nums[left] <= nums[right]){
                              
                               ans.push_back(nums[left]);
                               left++;
                         } 

                         else{
                               
                               ans.push_back(nums[right]);
                               right++;
                         }
                  }

                  while(left <= mid){

                      ans.push_back(nums[left]);
                      left++;
                  }

                  while(right <= high){

                      ans.push_back(nums[right]);
                      right++;
                  }

                  for(int i=low; i<=high; i++){
                      
                        nums[i] = ans[i-low];
                  }
            }



            void mergeSort(vector<int> &nums, int low, int high){

                    if(low>=high) return;

                    int mid = (low+high)/2;

                    mergeSort(nums, low , mid);

                    
                    mergeSort(nums , mid+1, high);
                    
                    
                    merge(nums, low, mid,high);
            }





   int main(){
     
        vector<int> nums = {8,66,43,46,86,33,27,63,87,30,37,90};
        int n = nums.size();

        mergeSort(nums,0,n-1);

        for(auto x : nums){
             
              cout<<x<<" ";
        }


   }