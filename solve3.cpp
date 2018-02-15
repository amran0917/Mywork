
#include<bits/stdc++.h>

using namespace std;

int visited[100],unvisited[100],finish[100],order[100];

typedef vector<int>myVec;
	myVec graph[100];
	myVec graphRev[100];
	
int t =-1;
int parent =0;

void dfs(int i) {
    visited[i] = true;
    unvisited[i] = parent;
    
    for(myVec::iterator it = graph[i].begin(); it != graph[i].end(); it++)
	if(!visited[*it])
	    dfs(*it);
}
void dfs_reverse(int i) {
    visited[i] = true;
    for(myVec::iterator it = graphRev[i].begin(); it != graphRev[i].end(); it++)
        if(!visited[*it])
            dfs_reverse(*it);
    t++;
    finish[i] = t;
}

int main()
{
	
	int testcase;
	cin>>testcase;
	
	int n,m,count=0;
	
	

	int domino_number,line_number;
	cin>>domino_number>>line_number;

	
	for(int i=0;i<line_number;i++)
	{
		cin>>n>>m;
		
		if(!graph[i].empty())   {
            		
            			
            	for(myVec::iterator it = graph[i].begin(); it != graph[i].end(); it++){
            	}
                	
        	}
	}
	
	for(int i=0;i<line_number;i++){
		if(!graphRev[i].empty())   {
            		
            	for(myVec::iterator it = graphRev[i].begin(); it != graphRev[i].end(); it++){
            	}
                	
        	}
	}
	
  
   
    for(int i=line_number; i>=0; i--){
       
        if(!visited[order[i]]) {
            parent = order[i];
            dfs(i);
            count++;
	}
	}
	
	int countR=0;
	for(int i=0; i<line_number; i++)  {
        if(!visited[i]){
           dfs_reverse(order[i]);
       	   order[finish[i]] = i;
        }
       
    }
     	countR++;
    	cout<<"\n"<<countR<<endl;
}


