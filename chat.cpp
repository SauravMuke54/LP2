/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string inp="";
    map<string,string> mp;
    mp["hi"]="hello";
    mp["hello"]="hi";
    mp["HI"]="Hello";
    mp["who is your principal"]="Dr Gandhe Sir";
    mp["principal"]="Dr. Gandhe Sir";
    mp["where is computer department"]="A1 Building";
    mp["hod computer"]="Dr. G V Kale";
    mp["hod entc"]="Dr. Munoth";
    mp["computer department"]="A1 Building";
    
    while(inp!="exit" || inp!="bye"){
        cout<<"\nYOU>";
        getline(cin,inp);
        if(mp.find(inp)!=mp.end()){
        cout<<"\nBOT>"<<mp[inp];   
        }else if(inp.find("principal")!=-1){
             cout<<"\nBOT>"<<mp["principal"];   
        }else if(inp.find("hod")!=-1){
            
            if(inp.find("computer")!=-1){
                cout<<"\nBOT>"<<mp["hod computer"];   
            }else if(inp.find("entc")!=-1){
                   cout<<"\nBOT>"<<mp["hod entc"];   
            }else{
               cout<<"\nBOT>"<<"Dont know";  
            }
            
        }else{
            cout<<"\nBOT> I am not able to understand";
        }
        
    }
    return 0;
}
