#include<limits.h>
 #include<stdio.h>
 #include<stdlib.h>
 int n,i,j,cost[10][10],cnt=0,visited[10],removed[10];
 int heapsize=0;
 int heapcount,graphcount,max;
 
 struct edge{
 	int v;
 	int dist;
 	int u;
 }heap[10],VT[10];
 
 typedef struct edge edg;
 
 void swap(struct edge *a,struct edge *b){
 	struct edge temp=*a;
 	*a=*b;
 	*b=temp;
 }
 void heapify(struct edge arr[],int n,int i){
 	int smallest=i;
 	int left=2*i+1;
 	int right=2*i+2;
 	heapcount++;
 	if(left<n && arr[left].dist < arr[smallest].dist)
 	     smallest = left;
 	if(right<n && arr[right].dist<arr[smallest].dist)
 	      smallest=right;
 	if(smallest!=i)
 	{
 		swap(&arr[i],&arr[smallest]);
 		heapify(arr,n,smallest);
	 }
   }
   void heapsort(struct edge arr[],int n){
   	  for(i=n/2-1;i>=0;i--)
   	    heapify(arr,n,i);
   }
   void makegraph(){
   	printf("Enter the total number of vertices");
   	scanf("%d",&n);
   	printf("\n Enter the cost matrix");
   	for(i=0;i<n;i++){
   		for(j=0;j<n;j++){
   			scanf("%d",&cost[i][j]);
   			if(cost[i][j] == 0)
   			  cost[i][j]=INT_MAX;
		   }
	   }
   }
   edg deleteheap(edg heap[]){
   	edg min=heap[0];
   	heap[0]=heap[heapsize-1];
   	heapsize=heapsize-1;
   	return min;
   }
   void prim(){
   	visited[0]=1;
   	heap[heapsize].v=-1;
   	heap[heapsize].u=0;
   	heap[heapsize].dist=0;
   	heapsize++;
   	while(cnt!=n){
   		edg min=deleteheap(heap);
   		VT[cnt].v=min.v;
   		VT[cnt].u=min.u;
   		VT[cnt].dist=min.dist;
   		cnt++;
   		int v=min.u;
   		removed[v]=1;
   		for(i=1;i<n;i++)
   		{
   			graphcount++;
   			if(!visited[i] && cost[v][i]!=INT_MAX && !removed[i]){
   				visited[i]=1;
   				heap[heapsize].v=v;
   				heap[heapsize].u=i;
   				heap[heapsize].dist=cost[v][i];
   				heapsize++;
			   }
			   if(visited[i] && cost[v][i]!=INT_MAX && !removed[i]){
			   	for(j=0;j<heapsize;j++){
			   		if(heap[j].u == i && cost[v][i]<heap[j].dist){
			   			heap[j].dist=cost[v][i];
			   			heap[j].v=v;
			   			break;
					   }
				   }
			   }
		   }
		   heapsort(heap,heapsize);
	   }
   }
   
   void tester(){
   	int sum=0;cnt=0;heapsize=0;heapcount=0;graphcount=0;max=0;
   	makegraph();
   	prim();
   	for(i=1;i<cnt;i++)
   	  {
   	  	printf("%c-->%c == %d\n",VT[i].v+65,VT[i].u+65,VT[i].dist);
   	  	sum+=VT[i].dist;
		 }
		printf("\n Minimum distance is:%d",sum);
   }
   void plotter(){
   	FILE *f1;
   	f1=fopen("primsgraph.txt","a");
   	int sum=0;cnt=0;heapsize=0;heapcount=0;graphcount=0;max=0;
   	makegraph();
   	prim();
   	for(i=1;i<cnt;i++)
   	  {
   	  	printf("%c-->%c == %d\n",VT[i].v+65,VT[i].u+65,VT[i].dist);
   	  	sum+=VT[i].dist;
		 }
		 max =(graphcount>heapcount)?graphcount:heapcount;
		 printf("basic count = %d",max);
		 fprintf(f1,"%d\t%d\n",n,max);
   }
   void main(){
   	int ch;
   	for(;;){
   		printf("\n Enter your choice");
   		printf("\n 1.tester 2.Plotter 3.Exit");
   		scanf("%d",&ch);
   		switch(ch){
		   
   		case 1:tester();
   		        break;
   		case 2:plotter();
   		       break;
   		case 3:exit(0);
   		default:printf("\n Invalid choice");}
	   }
   }
 
 
