#include<iostream>
#include<math.h>
using namespace std;
class edge
{
	public:
	int id;
	int src;
	int dest;
	int weight;
	int distance;
	
	void bellman(edge a[],int v,int e,int source);
};
void edge::bellman(edge a[],int v,int e,int source)
{
	int start,end;
	for(int i=0;i<v;i++)
	{
		int flag=0;
		for(int j=0;j<e;j++)
		{
			start=a[j].src;
			end=a[j].dest;
			if(a[start].distance!=999 && ( a[end].distance>a[start].distance+a[j].weight ))
			{
				a[end].distance= a[start].distance + a[j].weight;
				flag=1;
			}
		}
		if(flag==0)
		break;
		cout<<"iteration no."<<i+1;
		cout<<"\nvertex\tdistance\n";
		for(int i=0;i<v;i++)
		{
			cout<<i+1<<"\t"<<a[i+1].distance<<"\n";
		}
	}
	cout<<"final shortest distance:";
	cout<<"\nvertex\tdistance\n";
	for(int i=0;i<v;i++)
	{
		cout<<i+1<<"\t"<<a[i+1].distance<<"\n";
	}
}
int main()
{
	int v,e,source;
	cout<<"enter no. of vertices=";
	cin>>v;
	cout<<"enter no. of edges=";
	cin>>e;
	cout<<"enter source vertices=";
	cin>>source;
	
	edge a[e];
	for(int i=0;i<e;i++)
	{
		a[i].id=i+1;
		cout<<"enter source of edge"<<i+1<<"=";
		cin>>a[i].src;
		cout<<"enter destination of edge"<<i+1<<"=";
		cin>>a[i].dest;
		cout<<"enter weight of edge"<<i+1<<"=";
		cin>>a[i].weight;
		a[i].distance=999;		
	}
	a[source].distance=0;
	cout<<"displaying table:";
	cout<<"\nid\tsrc\tdest\tweight\tdistance\n";
	for(int i=0;i<e;i++)
	{
		cout<<a[i].id<<"\t"<<a[i].src<<"\t"<<a[i].dest<<"\t"<<a[i].weight<<"\t"<<a[i].distance<<"\n";
	}
	
	edge obj;
	obj.bellman(a,v,e,source);
	return 0;
}
/*
output:

mrinmayi@mrinmayi-VirtualBox:~$ cd daa
mrinmayi@mrinmayi-VirtualBox:~/daa$ g++ b.cpp
mrinmayi@mrinmayi-VirtualBox:~/daa$ ./a.out
enter no. of vertices=4
enter no. of edges=4
enter source vertex=1

enter source of edge 1=1
enter destination of edge 1=4
enter weight of edge 1=4

enter source of edge 2=1
enter destination of edge 2=2
enter weight of edge 2=5

enter source of edge 3=2
enter destination of edge 3=3
enter weight of edge 3=3

enter source of edge 4=3
enter destination of edge 4=4
enter weight of edge 4=-10

diplaying table :

id	source	desti	weight	distance
1	1	4	4	999
2	1	2	5	0
3	2	3	3	999
4	3	4	-10	999

iteration no.1=
vertex 	 distance
1	0
2	5
3	8
4	-2

final shortest distance :
1	0
2	5
3	8
4	-2

mrinmayi@mrinmayi-VirtualBox:~/daa$ g++ b.cpp
mrinmayi@mrinmayi-VirtualBox:~/daa$ ./a.out
enter no. of vertices=4
enter no. of edges=4
enter source vertices=1
enter source of edge1=1
enter destination of edge1=2
enter weight of edge1=3
enter source of edge2=4
enter destination of edge2=5
enter weight of edge2=6
enter source of edge3=7
enter destination of edge3=8
enter weight of edge3=9
enter source of edge4=1
enter destination of edge4=2
enter weight of edge4=3
displaying table:
id	src	dest	weight	distance
1	1	2	3	999
2	4	5	6	0
3	7	8	9	999
4	1	2	3	999
iteration no.1
vertex	distance
1	0
2	3
3	999
4	4
final shortest distance:
vertex	distance
1	0
2	3
3	999
4	4
*/



































/*#include<iostream>
using namespace std;

class edge
{
	public:
		int src;
		int dest;
		int weight;
		int distance;
		
		void bellman(edge a[],int v,int e,int source);
};

void edge::bellman(edge a[],int v,int e,int source)
{
	int start;
	int end;
	
	for(int i=0;i<v;i++)
	{
		int flag=0;
		for(int j=0;j<e;j++)
		{
			start=a[j].src;
			end=a[j].dest;
			
			
			if(a[start].dest != 999 && (a[end].distance>a[start].distance + a[j].weight))
			{
				a[end].distance=a[start].distance+a[j].weight;
				flag=1;
			}
		}
		if(flag==0)
		break;
		
		cout<<"\niteration no."<<i+1<<"=\n";
		cout<<"vertex \t distance\n";
		
		for(int i=0;i<v;i++)	
		{
			cout<<i+1<<"\t"<<a[i+1].distance<<"\n";
		}
	}
	
	
	
	//final output
	cout<<"\nfinal shortest distance :\n";
	for(int i=0;i<v;i++)
	{
		cout<<i+1<<"\t"<<a[i+1].distance<<"\n";
	}
}	

int main()
{
	int v,e,source;
	
	cout<<"enter no. of vertices=";
	cin>>v;
	cout<<"enter no. of edges=";
	cin>>e;
	cout<<"enter source vertex=";
	cin>>source;
	
	
	edge a[e];
	for(int i=0;i<e;i++)
	{
		cout<<"\nenter source of edge "<<i+1<<"=";
		cin>>a[i].src;
		cout<<"enter destination of edge "<<i+1<<"=";
		cin>>a[i].dest;
		cout<<"enter weight of edge "<<i+1<<"=";
		cin>>a[i].weight;
		
		a[i].distance=999;  //infinity
	}
	
	a[source].distance=0;
	
	cout<<"\ndiplaying table :\n";
	cout<<"\nid\tsource\tdesti\tweight\tdistance\n";
	for(int i=0;i<e;i++)
	{
		cout<<i+1<<"\t"<<a[i].src<<"\t"<<a[i].dest<<"\t"<<a[i].weight<<"\t"<<a[i].distance<<"\n";
	}
	
	edge obj;
	obj.bellman(a,v,e,source);
	
	return 0;
}*/
