
  #include<bits/stdc++.h>
  using namespace std;


   class Solution{
     
       public:

       vector<int> findShortest(vector<vector<int>>&edges , int v, int destination){


           vector<pair<int,int>> adj[v];

           for(auto x : edges){
             
               int u = x[0];
               int v = x[1];
               int wt = x[2];

               adj[u].push_back({v,wt});
               adj[v].push_back({u,wt});
           }

          priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
          pq.push({0,0});

          vector<int> distance(v,1e9);
          distance[0] = 0;
          
          vector<int> parent(v,1e9);
          parent[0] = 0;

          while(!pq.empty()){
             
               auto it = pq.top();

               pq.pop();

               int dist = it.first;
               int node = it.second;



               for(auto adjNode : adj[node]){
                 
                   int v = adjNode.first;
                   int wt = adjNode.second;

                   if( dist + wt < distance[v]){
                     
                        distance[v] = dist + wt;
                        parent[v] = node;

                        pq.push({distance[v],v});
                   }


               }
          }

          vector<int> path;

          
        while( destination != parent[destination]){
           
              path.push_back(destination);

              destination = parent[destination];
        }

         path.push_back(0);


          reverse(path.begin(),path.end());

          return path;
          
       }


   };




  int main(){


     vector<vector<int>> edges = {

          {0,2,6} ,{0,1,2},{2,3,8},{1,3,5},{3,4,10},{3,5,15},{4,6,2},{5,6,6}
     };

     // Given it is a undirected graph represent in vector of vector carrying { u, v , wt} means there is a edge between u -> v and v -> u having weight wt

     Solution leetcode;

     int destination = 6;

     vector<int> distance = leetcode.findShortest(edges,7,destination);

     for(auto x : distance){
       
        cout<<x<<" -> ";
     }


     
      
  }