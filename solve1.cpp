#include <bits/stdc++.h>


using namespace std;

int **adjacencyMatrix;
int numberOfVertex;

int testcase;
string arr;


void dfsVisit(int *color, int &time, int *prev, int *d, int *f, int u)
{
	color[u]=1;
	time++;
	d[u]=time;
	for(int v=0; v<numberOfVertex; v++)
	{
		if(adjacencyMatrix[u][v]==1)
		{
			if(color[v]==0)
			{
				prev[v]=u;
				dfsVisit(color, time, prev, d, f, v);
			}
		}
	}
	color[u]=2;
	time++;
	f[u]= time;
}

void dfs(int *color, int &time, int *prev, int *d, int *f)
{
	for(int u=0; u<numberOfVertex; u++)
	{
		color[u]=0;
		prev[u]=-1;//-1 for NULL
		f[u] = (int) pow(2,31)-10;
		d[u] = (int) pow(2,31)-10;
	}
	
	for(int u=0; u<numberOfVertex; u++)
	{
		if(color[u]==0) dfsVisit(color, time, prev, d, f, u);
	}
}



struct code
{
	int f;
	string item;
};

bool sortingRule (code i, code j)
{
	return i.f > j.f;
}

void printResultForTopological(int *color, int *prev, int *d, int*f,int i,int testcase)
{
	
	
	for(int i=0;i<testcase;i++)
	{
	
		cin>>arr;
	}
	
	vector <code> pairVec;
	
	for(int i=0; i<testcase; i++)
	{
		code temp;
		temp.f = f[i];
		temp.item = arr[i];
		pairVec.push_back(temp);
	}
	
	sort(pairVec.begin(), pairVec.end(), sortingRule);
	
	
	for(int i=1;i<testcase;i++)
	{	
		cout << "Case # "<<i<<": Dilbert should drink bevarages in this order:" << pairVec[i].item << "\t";
	}
	cout << endl;
}

int main()

{

	int *color,*prev,*d,*f;
	
	
	int i=0,time=0;
	while((cin>>testcase)!=0)
	{
		cout<<endl;
		
		color  = new int[testcase];
		prev = new int[testcase];
		d =  new int[testcase];
		f = new int[testcase];
		
		dfs(color,time,prev, d,f);
		
	
		printResultForTopological(color, prev, d, f,i,testcase);
	
	
	}
	

	return 0;
}



