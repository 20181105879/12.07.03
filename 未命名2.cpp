#include <iostream>
using namespace std;
struct node {
	long len;
}s[1010][1010];
long dis[1010];
int vis[1010];
long n,m;
long count=1;

long long len;
long tt;
void built()
{
	long t1,t2,l;
	for(long i=1;i<=n;i++)
	{
		for(long j=1;j<=n;j++)
	    {
	    	s[i][j].len=10000;
		}
		s[i][i].len=0;
		dis[i]=10000;
	}
	for(long i=0;i<m;i++)
	{
		cin>>t1>>t2>>l;
		s[t1][t2].len=l;
		s[t2][t1].len=l;
	}
	

}
long findmin()
{
	
	long min=1;
	long minst=10000;
	for(long i=1;i<=n;i++)
	{
		if(vis[i]==0 && dis[i]<minst)
		{
			min=i;
			minst=dis[i];
		}
	}
	if(minst<1000)
	{
		return min;
	}
	return -1;

}
void pri()
{
	long v;	
	dis[1]=0;
	for(long i=1;i<=n;i++)
	{
		dis[i]=dis[1]+s[1][i].len;
	}
    tt=1;
	vis[1]=1;
	while(1)
	{
		v=findmin();
	
		if(v==-1)
		{
			break;
		}
		vis[v]=1;
		len+=s[tt][v].len;
	
		count++;
//		vv[count]=v;
		for(long i=1;i<=n;i++)
		{
			if(vis[i]==0 && s[v][i].len<10000) 
			{
				if(s[v][i].len+dis[v]<dis[i])
				{
					dis[i]=s[v][i].len+dis[v];
			
			    }
	
		    }
		
		
		
	    }	
	
     }
   

}


int main()
{
    cin>>n>>m;
    built();
    pri();
	if(count<n)
	{
		cout<<"-1";
	}
	else
	{

	cout<<len;

	}


	return 0;
 } 
