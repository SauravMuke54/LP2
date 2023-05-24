/******************************************************************************
N Queen Using Branch and Bound
*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;


void solve(vector<vector<bool>> &board,int row,vector<bool> &cols,
vector<bool> &ndiag,vector<bool> &rdiag){
   
    if(row==board.size()){
        cout<<endl;
        cout<<"Printing a possible solution\n";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]==true){
                    cout<<"1 ";
                }else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
       
    }
   
    for(int col=0;col<board[0].size();col++){
       
        if(cols[col]==false && ndiag[row+col]==false &&
        rdiag[row-col+board.size()-1]==false){
           
            board[row][col]=true;
            cols[col]=true;
            ndiag[row+col]=true;
            rdiag[row-col+board.size()-1]=true;
            solve(board,row+1,cols,ndiag,rdiag);
            board[row][col]=false;
             cols[col]=false;
            ndiag[row+col]=false;
            rdiag[row-col+board.size()-1]=false;
           
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the n\n";
    cin>>n;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    vector<bool> cols(n);
    vector<bool> ndiag(2*n-1);
    vector<bool> rdiag(2*n-1);
    cout<<"Printing all possible solution\n\n";
   
    solve(board,0,cols,ndiag,rdiag);
   

    return 0;
}