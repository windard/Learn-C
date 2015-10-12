double tri_area (int a,int b,int c)
{

	double			p;
	double			m;
	
	if(a<=0||b<=0||c<=0)
	return -1;
	else if (a+b<=c||a+c<=b||b+c<=a)
	return -1;
	else
	{
	
	p=(a+b+c)/2;
	m=sqrt(p*(p-a)*(p-b)*(p-c));

	return m;
	}
	
}



