
/*151044029-HW5-ANIL AKBULUT*/
#include <stdio.h>
#include <string.h>
#define LENGHT 250
void tire(int num,FILE *fp2)
{
	if(num==0)
	{
		return;
	} 
	fprintf(fp2,"-");
	tire(num-1,fp2);
}

void rec(char arr[],FILE *fp2,int i,int j,int k,int space)
{	
	if(i-space==j) return;
	if(arr[j]=='(')
	{
		k++;
		if(arr[j+1]!=')' && arr[j+1]!='(' && arr[j+1]!=','){
			tire(k,fp2);
		}
	}
	if(arr[j]==')')
	{
		k--;
	}
	if(arr[j]==',')
	{
		fprintf(fp2,"\n");
		if(arr[j+1]!=')' && arr[j+1]!='(' && arr[j+1]!=','){
			tire(k,fp2);
		}
		
	}
	if(arr[j]!=')' && arr[j]!='(' && arr[j]!=',')
	{
		fprintf(fp2,"%c",arr[j]);
	}
	rec(arr,fp2,i,j+1,k,space);
}
int main()
{
	FILE *fp1;
	FILE *fp2;
	int i=0,j=0,k=0,space1=0,space2=0;
	char input_text[LENGHT];
	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w+");
	while(fscanf(fp1,"%c",&input_text[i])!=EOF) 
	{
		i++;  
	}
	for(k=0;k<i;k++)
	{
		if(input_text[k]==' ')
		{
			space1++;
		}
		else
		{
			j=space1;
			break;
		}
	}
	for(k=i-2;k>=0;k--)
	{
		if(input_text[k]==' ')
		{
			space2++;
		}
		else
		{
			break;
		}
	}
	k=0;
	i=i-j;
	rec(input_text+j,fp2,i ,0,k,space2);
	return 0;	
}