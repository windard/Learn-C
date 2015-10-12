#include<stdio.h>
int main()
{
   char     str[80],m;
   int      i=0;
   int      a,b,c,d;

    printf("Input a string:\n");


 

//	gets(str);


    while(1)
    {
        m=getchar();
		str[i]=m;
        if(m=='\n')
            break;
        i++;

    }
		

    printf("\n");
    a=b=c=d=0;

/*
    for(i=0;i<80;i++)
    {
        if('A'<=str[i]<='Z')
            a++;
        else    if('a'<=str[i]<='z')
            b++;
        else    if(0<=str[i]<=9)
            c++;
        else
            d++;
    }

 */

	for(i=0;str[i]!='\n';i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
			a++;
		else if(str[i]>='a'&&str[i]<='z')
			b++;
		else if(str[i]>='0'&&str[i]<='9')
			c++;
		else
			d++;
	}

    printf("Upper: %d\nLower: %d\nDigit: %d\nOther: %d\n",a,b,c,d);

    return 0;
}
