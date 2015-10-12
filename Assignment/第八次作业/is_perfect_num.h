int is_perfect_num (int x)
{
	int			i;
	int			j=0;



	for(i=1;i<x;i++)
	{
		if(x%i==0)
			j+=i;
	}

	if(j==x)
		return 1;
	else
		return 0;
}