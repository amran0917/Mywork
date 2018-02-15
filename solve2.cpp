#include<bits/stdc++.h>

using namespace std;


int main()
{

	int number_testcase;
	cin>>number_testcase;
	
	cout<<endl;
	
	vector <int > nodes[1000];
	int p,d;
	int edges;
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>p>>d;
		nodes[p].push_back(d);
		nodes[d].push_back(p);
	
	
	}
	
	cout<<endl;
	
	for(int i=0;i<1000;i++)
	{
		
		if(!nodes[i].empty())
		{
			//cout<<"[ "<<i<<" ]"<<"-->";
			
			for(vector<int>::iterator it=nodes[i].begin();
				it!=nodes[i].end();++it)
			{
				//cout<<*it<<"-->";
			}
				//cout<<"NULL"<<endl;
		}	

	}
	
	stack <int> mystack;
	bool visited[1000] = {false};
	int start=0;
	
	mystack.push(start);
	visited[start]=true;
	
while(!mystack.empty())
{
		
		int top = mystack.top();
		cout<<top<<endl;
		mystack.pop();
		
	for(vector<int>::iterator it=nodes[top].begin();it!=nodes[top].end();++it)
		{
			if(visited[*it]==false)
			{
				visited[*it]=true;
				mystack.push(*it);
			}
		}
}		
		
		
	return 0;

}
