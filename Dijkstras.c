#include<stdio.h>
#include<stdlib.h>
#define INF 999
int i,j,num,count=0;

void dijkstras(int n,int cost[15][15],int source,int dist[15]){	
	int min=0,u;
	int visited[15]={0};
	for(i=1;i<=n;i++)
	 dist[i]=cost[source][i];
	dist[source]=0;
	visited[source]=1;
	//dikstras core loop
	for(num=2;num<=n;num++){
		min=INF;
		for(j=1;j<=n;j++){
			if(visited[j]==0 && dist[j]<min){
				min=dist[j];
				u=j;
			}
			  
		}
		visited[u]=1;
		for(j=1;j<=n;j++){
			count++;
			if(visited[j]==0 && dist[j]>dist[u]+cost[u][j]){
				dist[j]=dist[u]+cost[u][j];
			}
		}
	}
}
void tester(){
	int n,cost[15][15],source,dist[15];
	printf("\n Enter the number of vertices");
	scanf("%d",&n);
	printf("\n Enter the cost matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	printf("\n Enter the source\n");
	scanf("%d",&source);
	dijkstras(n,cost,source,dist);
	for(i=1;i<=n;i++)
	  printf("%d-%d=%d\n",source,i,dist[i]);
}

void plotter(){
	int v;
	FILE *f=fopen("dikstra.txt","a");
	for(v=2;v<=10;v++){
		int cost[15][15];
		int dis_p[15];
		for(i=1;i<=v;i++){
			for(j=1;j<=v;j++){
				if(i==j)
				   cost[i][j]=0;
				else
				   cost[i][j]=rand()%10+1;
			}
		}
		count=0;
		dijkstras(v,cost,1,dis_p);
		fprintf(f,"%d\t%d\n",v,count);
	}
}

	int main(){
 	int ch;
 		scanf("%d",&ch);
 	printf("\n Enter ur choice");
 	printf("\n1.To test \n2.To plot");
 	switch(ch){
 		case 1:tester();
 		break;
 		case 2:plotter();
 		break;
 		default:printf("invalid choice!!\n");
	 }
	}
 
	

	
