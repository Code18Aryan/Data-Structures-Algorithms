
 
  

       #include<bits/stdc++.h>

       using namespace std;


                  //   BETTER APPROACH

            
            bool  binarySearch(vector<int> & nums, int target){

                  int n=nums.size();

                int low = 0;   int high = n-1;


               while (low <= high){

                      int mid=(low + high)/2;

                      if(nums[mid] ==  target ) return true;

                      else if ( nums[mid]  <= target)  low = mid+1;

                      else high = mid-1;
               }

               return false;

            }

         

           bool search2DBetterForce( vector<vector<int>> & nums, int target){

                int m = nums.size();
                int n = nums[0].size();

                
                for(int i=0; i<m; i++){

                    if( nums[i][0] <= target && target >= nums[i][n-1] ){


                      if( binarySearch( nums[i], target) == true )  return true;

                    }

                    else false;
                }

                return false;
                
           }




                    //  OPTIMAL APPRAOCH 


            
            bool  searchOptimal(vector<vector<int>> &nums, int target){

                  int m = nums.size();
                  int n = nums[0].size();

                  int totalElement= (m*n-1);

                  int low = 0;

                  int high = totalElement;

                  while( low <= high){

                      int mid = (low + high)/2;

                      int row = mid/n;
                      int col = mid%n;

                      if( nums[row][col] == target) return true;

                      else if ( nums[row][col] < target) low = mid+1;

                      else high = mid-1;
                  }

                  return false;

            }

             

                 //   SEARCH WHEN COL AND ROW ARE SORTED NOT THE ENTIRE 2D ARARY

  
                            //  BRUTE SIMPLE JUST ITERATE THROUGH ENTIRE ARRAY 

             bool searchBruteII( vector<vector<int>> & nums, int target){


                    int m = nums.size();
                    int n = nums[0].size();

                    for(int i=0; i<m; i++){

                        for(int j=0; j<n; j++){

                            if( nums[i][j] == target) return true;
                        }
                    }
                        return false;
             }    

                       

                        //  BETTER USES ONE LOOP AND IN THAT SPECIFIC ROW IT SEARCH FOR ARRAY USING BINARY SEARCH
                        

             bool searchBetterII(vector<vector<int>> & nums, int target){

                    int m = nums.size();
                    int n = nums[0].size();

                    for(int i=0; i<m; i++){

                        if( binarySearch(nums[i],target) == true)  return true;
                    }

                    return false;
             }

              

               

                      // OPTIMAL PICK THE SPECIFIC ROW AND COL THAT IS INCRESING AND DECREASING 



                bool searchOptimalII(vector<vector<int>> & nums, int target){

                      int m = nums.size();
                      int n = nums[0].size();


                        int row = 0;
                        int col = n-1;

                        while ( row < m && col >= 0){

                            if ( nums[row][col] == target) return true;

                            else if( nums[row][col] < target)  row++;

                            else col--;
                        }

                           return  true;
                }      







       int main(){


          int nums[3][3] = { {12,3,4},
                             {12,10,13}, 
                             {2,5,7}
                              };

              vector<vector<int>> nums2 =  {{1,3,4},
                                        {6,10,13}, 
                                        {22,25,37}                      
              };            


  vector<vector<int>> matrix = {

        {1,  4,  7,  11, 15},
        {2,  5,  8,  12, 19},
        {3,  6,  9,  16, 22}, 
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}

          };        


           // cout<<search2DBruteForce(nums2,69);
           // cout<<searchOptimal( nums2, 13);


            //    row and col are sorted 


            cout<<searchBetterII(matrix,15);
            cout<<searchBetterII(matrix,13);
            cout<<searchOptimalII(matrix,16);




        
       }