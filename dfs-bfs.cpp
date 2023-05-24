/******************************************************************************
DFS BFS

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
void dfs(int node,vector<int> adj[],vector<int> &visited){
    visited[node]=1;
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!visited[it]){
            visited[it]=1;
            dfs(it,adj,visited);
        }
    }
}
void bfs(int start,vector<int> adj[],vector<int>& visited){
    
    visited[start]=1;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        
        for(auto it:adj[node]){
            
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
            
        }
        
        
    }
    
}

int main()
{
    int V,E; //vertex and edges;
    cout<<"Enter number of vertex and edges";
    cin>>V>>E;
    
    vector<int> adj[V+1]; //works for both 0 and 1 indexed graph
    
    cout<<"Enter the edges"<<endl;
    while(E--){
        
        int source,destination;
        cout<<"Enter source and destination"<<endl;
        cin>>source>>destination;
        adj[source].push_back(destination);
        adj[destination].push_back(source);// remove this for directed graph
        
    }
    
     int ch=1;
    while(ch!=3){
    
    vector<int> visited(V+1,0);
    
    cout<<"ENter your choice \n";
    cout<<"1. DFS"<<endl;
    cout<<"2. BFS"<<endl;
    cout<<"3. Exit"<<endl;
    
   
    cin>>ch;
    
    switch(ch){
        
        case 1:{
            cout<<"Enter the starting vertex"<<endl;
            int start;
            cin>>start;
            
            dfs(start,adj,visited);
            
            break;
            
            
            
        }
        
     case 2: {
         
         cout<<"Enter the starting vertex"<<endl;
            int start;
            cin>>start;
            
            bfs(start,adj,visited);
            
            break;
            
         
         
     }
        
        
    }
    
    
    }
    
    
    

    return 0;
}
