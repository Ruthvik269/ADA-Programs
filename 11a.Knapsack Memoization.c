#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount = 0, t[25][25], w[25], v[25],i;

int max(int a,int b){
	return (a>b)?a:b;
}
int knapsackMemo(int n, int m)
{
    if (t[n][m] != -1)
        return t[n][m];

    opcount++;
    if (w[n - 1] <= m)
        return t[n][m] = max(knapsackMemo(n - 1, m), v[n - 1] + knapsackMemo(n - 1, m - w[n - 1]));
    else
        return t[n][m] = knapsackMemo(n - 1, m);
}

void init(int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
                t[i][j] = -1;
    }
}

void tester()
{
    int n, m;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Sack capacity: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and value of item %d :", i + 1);
        scanf("%d%d", &w[i], &v[i]);
    }
    init(n, m);
    printf("Max profit is %d\n", knapsackMemo(n, m));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
   printf("\n Composition :\n");
    for(i=n;i>0;i--){
    	if(t[i][m]!=t[i-1][m]){
		
    	  printf("%d ",i);
    	m=m-w[i];}
	}
    printf("\nOpcount:%d", opcount);
}

void plotter()
{
    FILE *fp = fopen("knapsackMemo.txt", "w");
    for (int i = 5; i <= 10; i++)
    {
        int m = i * 2;
        for (int j = 0; j < i; j++)
        {
            w[j] = rand() % 10 + 1;
            v[j] = rand() % 50 + 1;
        }
        init(i, m);
        opcount = 0;
        knapsackMemo(i, m);
        fprintf(fp, "%d\t%d\n", i, opcount);
    }
    fclose(fp);
}

void main()
{
    int ch;
    printf("Enter \n1.Tester\n2.Plotter\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        printf("Invalid choice.\n");
    }
}
