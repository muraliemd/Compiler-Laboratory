#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<alloc.h>
#include<string.h>
#include<math.h>

void main()
{
	int i=0,j=0,k=0,n,flag=0;
	void *p,*add[5];
	char ch,b[15],d[15],c,srch;
	clrscr();
	printf("Expression terminated by '$' \n");
	while( (c=getchar())!='$')
	{
		b[i]=c;
		i++;
	}
	n=i-1;
	printf("Given expression: ");
	i=0;
	while(i<=n)
	{
		printf("%c",b[i]);
		i++;
	}

	printf("\n Symbol table \n");
	printf("\nSymbol \t address \t type");

	while(j<=n)
	{
		c=b[j];
		if(isalpha(toascii(c)))
		{
			p=malloc(c);
			add[k]=p;
			d[k]=c;
			printf("\n %c \t %d \t identifier\n",c,p);
			k++;
		}
		else
		{
			if(c=='+' || c=='-' || c=='*'||c=='=')
			{
				p=malloc(c);
				add[k]=p;
				d[k]=c;
				printf("\n %c \t %d \t Operator \n",c,p);
				k++;
			}
			else if(c=='e'||c=='#'||c=='^')
			{
				p=malloc(c);
				add[k]=p;
				d[k]=c;
				printf("\n %c \t %d \t Special Character \n",c,p);
				k++;
			}
			else if(isdigit(c))
			{
				p=malloc(c);
				add[k]=p;
				d[k]=c;
				printf("\n %c \t %d \t Constant \n ",c,p);
				k++;
			}
		}
		j++;
	}

	printf("\n Symbol table is to be searched");
	srch=getch();
	for(i=0;i<=k;i++)
	{
		if(srch==d[i])
		{
			printf("\n %c \t %d \n",d[i],add[i]);
			flag=1;
		}
	}

	if(flag==0)
	printf("\n Symbol not found");

	getch();

}


