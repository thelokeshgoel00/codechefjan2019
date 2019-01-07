#include<stdio.h>
main()
{
	int i,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,j,x=0;
		scanf("%d",&n);
		if(n%3==0)
		{
			
			x=n/3;
			for(j=0;j<x;j++)
			{
				printf("21 15 35 ");
			}
			printf("\n");
		}
		if(n%3==1)
		{
			x=n/3;
			if(x==1)
			{
				printf("154 35 130 143 ");
				
			}
			else
			{
				printf("154 35 10 ");
				for(j=0;j<x-2;j++)
				{
					printf("14 35 10 ");
				}
				printf("14 35 130 ");
				printf("143");
			}
			printf("\n");
			
		}
		if(n%3==2)
		{
			x=n/3;
			if(x==1)
			{
				printf("66 15 10 14 77");
			}
			else
			{
				printf("66 15 10 ");
				for(j=0;j<x-1;j++)
				{
					printf("6 15 10 ");
				}
				printf("14 77");
			}
			printf("\n");
		}
	}
}
