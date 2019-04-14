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
