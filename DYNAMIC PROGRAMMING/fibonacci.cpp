#include<bits/stdc++.h>
using namespace std;


class Solution{
     
     public:

     // Normal Recursive Approach

     int fiboRecursion(int n){
         
          if(n <= 1) return 1;

          return fiboRecursion(n-1) + fiboRecursion(n-2);
     }
       

     // using memoization top - down appraoch ( last n to base case)


     int fiboMemo(int n, vector<int>&dp){
         
          if(n <= 1) return 1;

          if(dp[n] != -1) return dp[n];

          return dp[n] = fiboMemo(n-1,dp) + fiboMemo(n-2,dp);
     }


};



int main(){


      Solution leetcode;

      int n  = 6;

      vector<int> dp(n+1,-1);

      int fifth  = leetcode.fiboMemo(n,dp);

      cout<<fifth;


}