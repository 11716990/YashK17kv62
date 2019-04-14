#include<stdio.h>
#include<conio.h>
int main()
{
	int temp[20],segment[50],tempVar, sc=0,count=0,limit,f,i,j,k=0,n,r,t,priority[20],matchCount[20];
	printf("Enter no of pages:");
	scanf("%d",&n);
	printf("Enter the reference string:");
	while(1)
	{
		if(sc<n)
		{
			scanf("%d",&tempVar);
			if(tempVar>=0 && tempVar<=9)
			{
				segment[sc]=tempVar;
				sc++;
			}
			else
			{
				printf("\nInvalid Range. Enter the value of segments in rangr from {0,9} instead of %d:\t",tempVar);
			}
		}
		else
		{
			printf("\nALL THE ENTRIES ARE SUCCESSFULLY ENTERED. PRESS ANY KEY TO CONTINUE\n");
			getch();
			break;
		}
	}
	entry:
	printf("\nEnter no of frames:");
	scanf("%d",&f);
	if(f>7||f<0)
		{
			printf("please enter the number of frames between 0 to 7.Press any key to enter");
			getch();
			goto entry;
		}
	temp[k]=segment[k];//storing the first element of segment in temporary variable
	printf("\n\t%d\n",temp[k]);
	count++;
	k++;
	for(i=1;i<n;i++)
	{
		limit=0;//limit is used to find whther the current frame if filled or not
		for(j=0;j<f;j++)
		{
			if(segment[i]!=temp[j])
			limit++;//it will increment when the page is not find in the meomry
		}
		if(limit==f)//if required page is not present then replacement algo will be applied
		{
			count++;
			if(k<f)
			{
				temp[k]=segment[i];
				k++;
				for(j=0;j<k;j++)
				printf("\t%d",temp[j]);
				printf("\n");
			}
			else
			{
				for(r=0;r<f;r++)
				{
					matchCount[r]=0;
					for(j=i-1;j<n;j--)
					{
						if(temp[r]!=segment[j])//that the string going to enter in frame is present or not
						matchCount[r]++;
						else
						break;    
					}
				}
				for(r=0;r<f;r++)
				priority[r]=matchCount[r];
				for(r=0;r<f;r++)
				{
					for(j=r;j<f;j++)//setting priority on the basis of count
					{
						if(priority[r]<priority[j])
						{
							t=priority[r];
							priority[r]=priority[j];
							priority[j]=t;
						}
					}
				}
				for(r=0;r<f;r++)
				{
					if(matchCount[r]==priority[0])
					temp[r]=segment[i];
					printf("\t%d",temp[r]);
				}
				printf("\n");
			}
		}
	}
	printf("\nThe no of page faults is %d",count);
}


