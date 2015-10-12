#include<stdio.h>
int is_prefect_num(int x)
{
   int i,sum=0;
   for(i=1;i<x;i++)
   {
    if(x%i==0)
     sum=sum+i;
   }
   if(sum==x)
    return 1;
   else
    return 0;
}
