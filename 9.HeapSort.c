#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count,count2=0;
int i;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}
void heapify(int *heap,int n,int root){
	int largest=root;
	int left=2*root+1;
	int right=2*root+2;
	if(left<n){
		count++;
		if(heap[left]>heap[largest])
		 largest=left;
	}
	if(right<n){
		count++;
		if(heap[right]>heap[largest])
		  largest=right;
	}
	if(largest != root){
		swap(&heap[root],&heap[largest]);
		heapify(heap,n,largest);
	}
}
void heapsort(int *heap,int n){
	for( i=(n/2)-1;i>=0;i--)
	  heapify(heap,n,i);

count2=count;
count=0;
for(i=n-1;i>=0;i--){
	swap(&heap[0],&heap[i]);
	heapify(heap,i,0);
}}
int max(int a,int b){
	int temp=a>b?a:b;
	return temp;
}

void tester(){
	int *arr,n;
	printf("\n Enter the number of elements");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	printf("\n Enter the elemnts of the array");
	for(i=0;i<n;i++)
	  scanf("%d",&arr[i]);
	printf("\n");
	heapsort(arr,n);
	printf("\n The elemnts of the array after sorting");
		for(i=0;i<n;i++)
	  printf("%d ",arr[i]);
}
void plotter(){
	int *arr,n;
	srand(time(NULL));
	FILE *f1,*f2,*f3;
	f1=fopen("heapbest.txt","a");
	f2=fopen("heapworst.txt","a");
	f3=fopen("heapavg.txt","a");
	n=100;
	while(n<=1000){
		arr=(int *)malloc(sizeof(int)*(n+1));
		for(i=0;i<n;i++)
		*(arr+i)=n-i+1;
		count=0;
		//best case
		heapsort(arr,n);
		count=max(count,count2);
		fprintf(f1,"%d\t%d\n",n,count);
		//worst case
		count=0;
		for(i=0;i<n;i++)
		*(arr+i)=i+1;
			heapsort(arr,n);
		count=max(count,count2);
		fprintf(f2,"%d\t%d\n",n,count);
		//avg case
		count=0;
		for(i=0;i<n;i++)
		*(arr+i)=rand()%n;
		heapsort(arr,n);
		count=max(count,count2);
		fprintf(f3,"%d\t%d\n",n,count);
		n=n+100;
		free(arr);
		
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
}
void main(){
	int ch;
	for(;;){
		printf("\n 1.Tester 2.Plotter 3.Exit");
		printf("\n Enter your choice");
		scanf("%d",&ch);
		switch(ch){
			case 1:tester();
			        break;
			case 2:plotter();
			        break;
			case 3:exit(0);
		    default:printf("\n Invalid Choice");
		}
	}
}
