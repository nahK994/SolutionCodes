#include<stdio.h>
#include<math.h>
long prime(long p);

int main()
{
	long n,m,l,max,c;
	while(scanf("%ld",&n)!=EOF)
	{
		if(n==0)
			break;
		if(n<0)
			n=n*(-1);
		if(prime(n)==1)
			printf("-1\n");
		else
		{
			l=0;
			m=n;
			max=0;
		long a[50]={0},i,j=0;
			while(prime(n)==0)
			{
				for(i=2;i<=(long)sqrt(n);i++)
				{
					if(n%i==0)
					{
						if(i>max)
							max=i;
						n=n/i;
						a[j]=i;
						j++;
						break;
					}
				}
			}
			if(n>0)
			{
				a[j]=n;
				j++;
				if(n>max)
					max=n;
			}
			c=0;
			for(i=0;i<j-1;i++)
			{
				if(a[i]!=a[i+1])
					c++;
			}
			if(c==0)
				printf("-1\n");
			else
				printf("%ld\n",max);
		}
	}
	return 0;
}

long prime(long p)
{
	long k;
	if(p==2)
		return 1;
	for(k=2;k<=(long)sqrt(p);k++)
		if(p%k==0)
		return 0;
		return 1;
}