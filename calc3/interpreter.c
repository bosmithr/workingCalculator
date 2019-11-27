#include "interpreter.h"


void interpret()
{
    float array[40];
    int j=0;
    char s[100];
    FILE *fp = NULL;
    
    fp = fopen("code.txt", "r");
   if ( fp == NULL) {
        fprintf(stderr, "File %s does not exist.\n", "infix.txt");
        exit(1);
    }

   while(!feof(fp))
    {
       char item = readchar(fp);
       if(item=='L')
        {
            fscanf(fp,"%s %f\n",&s,&array[j]);
            j++;
        }
       if(item=='M')
        { 
            fscanf(fp,"%s\n",&s);
            array[j-2]=array[j-2]*array[j-1];j--;
        }
        if(item=='A')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=array[j-2]+array[j-1];j--;
        }
        if(item=='D')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=array[j-2]/array[j-1];j--;
        }
        if(item=='E')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=pow(array[j-2],array[j-1]);j--;
        }
        if(item=='m')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=(array[j-2]-array[j-1]*((int)array[j-2] / (int)array[j-1])); j--;
        }
        if(item=='S')
        {
            fscanf(fp,"%s\n",&s);
            array[j-2]=array[j-2]-array[j-1];j--;
        }
    }
     printf("%f\n",array[0]);
  
}

/*
int main()
{
    interpret();
    return 0;
}
*/