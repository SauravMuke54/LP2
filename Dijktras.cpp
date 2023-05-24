/******************************************************************************
Dijktras ALgorithm 
*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int V,E;
    cout<<"Enter number of vertices and edges"<<endl;
    cin>>V>>E;
    
    vector<pair<int,int>> adj[V+1]; 
    
    while(E--){
        int source,destination,weight;
        cout<<"Enter source, destination  and weight of edge"<<endl;
        cin>>source>>destination>>weight;
        adj[source].push_back({destination,weight});
        adj[destination].push_back({source,weight});
    }
    
    vector<int> distance(V+1,INT_MAX);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    int start;
    cout<<"Enter the starting node to calculate distance"<<endl;
    cin>>start;
    
    distance[start]=0;
    
    pq.push({0,start});
    
    while(!pq.empty()){
        int dist=pq.top().first;
        int node=pq.top().second;
        
        pq.pop();
        
        for(auto it:adj[node]){
            
            int nextnode=it.first;
            int wght=it.second;
            
            if(dist+wght<distance[nextnode]){
                distance[nextnode]=dist+wght;
                pq.push({dist+wght,nextnode});
            }
            
            
            
        }
    }
    
    cout<<"Printing distance :"<<endl;
    
    for(int i=0;i<V;i++){
         cout<<"Distance from "<<start<< " to "<<i << " is "<<distance[i]<<endl;
    }
    

    return 0;
}