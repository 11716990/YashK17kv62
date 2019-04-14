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
	
