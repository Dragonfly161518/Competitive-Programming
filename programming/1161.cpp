#include<stdio.h>
#include<queue>
using namespace std;
typedef pair <int,int> p;
bool check;
int a,b;
int x[]={0,1,0,-1},y[]={1,0,-1,0};
queue<p> q;

struct district
{
	bool n,e,s,w;
	int time;
}d[101][101];

void flow(p xy)
{
	if(check)
		return;
		
	int r=xy.first,c=xy.second;
	//printf("r=%d c=%d | n=%d s=%d e=%d w=%d\n",r,c,d[r][c].n,d[r][c].s,d[r][c].e,d[r][c].w);
	for(int i=0;i<4;i++)
	{
		int xx=x[i]+xy.first,yy=y[i]+xy.second;
		//printf("xx=%d yy=%d\n",xx,yy);
		
		if( d[r][c].n==0 && i==3 )
			continue;	
		if( d[r][c].s==0 &&i==1 )
			continue;
		if( d[r][c].e==0 &&i==0 ) 
			continue;
		if( d[r][c].w==0 &&i==2 )
			continue;
					
		if(xx>0&&xx<=a&&yy>0&&yy<=b)
		{		
			//printf("time %d time %d\n",d[xx][yy].time,d[r][c].time+1);
			if(d[xx][yy].time!=0&&d[xx][yy].time==d[r][c].time+1)
			{
				check=1;
				printf("%d\n",d[xx][yy].time);
				printf("%d %d",xx,yy);
				return;	
			}
			
			q.push(p(xx,yy));
			
			if(d[xx][yy].time==0)
				d[xx][yy].time=d[r][c].time+1;
				
			if(i==0)
				d[xx][yy].w=0;
			else if(i==1)
				d[xx][yy].n=0;
			else if(i==2)
				d[xx][yy].e=0;
			else
				d[xx][yy].s=0;
		}
	}
}

main()
{
	char c,w;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			scanf("%c%c",&w,&c);
			
			if(c=='R')
				d[i][j].e=1,d[i][j+1].w=1;
			else if(c=='D')
				d[i][j].s=1,d[i+1][j].n=1;
			else if(c=='B')
				d[i][j].e=1,d[i][j].s=1,d[i][j+1].w=1,d[i+1][j].n=1;
				
		}
	}
	
	d[1][1].time=1;
	q.push(p(1,1));
	
	while(!q.empty())
	{
		flow(q.front());
		q.pop();
	}
	
}
