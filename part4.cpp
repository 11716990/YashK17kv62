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


