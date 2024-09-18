#include<bits/stdc++.h>
using namespace std;


class Solution{

     public:

     // recursive code

     int knapSackRecursion(int weight[] , int profit[] , int wt , int n){
         
          if( n == 0 || wt == 0) return 0;

          if(weight[n-1] <= wt){
             
               return max( profit[n-1] + knapSackRecursion(weight, profit , wt - weight[n-1] , n-1) , knapSackRecursion(weight, profit, wt , n-1));
          }

          else if( weight[n-1] > wt){
             
              return  knapSackRecursion(weight, profit, wt , n-1);
          }
     }


        // Memoizatio  Code

     int knapSackMemo(int weight[] , int profit[] , int wt , int n , vector<vector<int>> &dp){
         
          if( n == 0 || wt == 0) return 0;

          if(dp[wt][n] != -1) return dp[wt][n];

          if(weight[n-1] <= wt){
             
               return dp[wt][n] = max( profit[n-1] + knapSackMemo(weight, profit , wt - weight[n-1] , n-1, dp) , knapSackMemo(weight, profit, wt , n-1, dp));
          }

          else if( weight[n-1] > wt){
             
              return dp[wt][n] =  knapSackMemo(weight, profit, wt , n-1, dp);
          }
     }


     // Tabulation bottom Up approach


       int knapSackTabulation(int value[] , int weight[], int wt , int n){
           
           vector<vector<int>> dp(n + 1 , vector<int>(wt + 1 ));

           for(int i=0; i<n+1; i++){
                
                 for(int j=0; j<wt+1; j++){
                     
                      if(i == 0 || j == 0) dp[i][j] = 0;
                 }
           }


          for(int i=1; i<n+1; i++){
                
                 for(int j=1; j<wt+1; j++){
                     
                       if(weight[i-1] <= j){
                          
                           dp[i][j] = max(value[i-1] + dp[i-1][j- weight[i-1]] , dp[i-1][j]);
                       }

                       else{
                          
                            dp[i][j] = dp[i-1][j];
                       }
                 }
          }

          return dp[n][wt];

     }

     








};




int main(){
     
     int profit[] = {60, 100, 120 };
     int weight[] = {10, 20, 30};

     int wt = 50;
     int n = 3;

     Solution leetcode;

     vector<vector<int>> dp(wt+1 , vector<int>(n+1,-1));

     int maxProfit = leetcode.knapSackRecursion(weight,profit,wt,n); 

     int maxProfitOptimal = leetcode.knapSackMemo(weight,profit,wt,n,dp);

     int maxProfitTabu = leetcode.knapSackTabulation(profit,weight,wt,n);

     cout<<maxProfit; cout<<endl;
      
     cout<<maxProfitOptimal; 

     cout<<maxProfitTabu;


     for(int i=0; i<dp.size(); i++){
           
            for(int j=0; j<dp[0].size(); j++){
                
                 cout<<dp[i][j]<<" ";
            }

            cout<<endl;
     }
}
