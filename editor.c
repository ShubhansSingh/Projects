#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void print(int *str,int k)
{
    int i;
    system("cls");
    for(i=0;i<k;i++)
    {
        if(str[i]==13)
        printf("\n");
        else
        printf("%c",str[i]);
    }
}
int main()
{
    int i=0,ch,str[5000];
    while(ch=_getch())
    {
        if(ch==13)
            str[i++]=13;
        else if(ch==27){
            if(i>0)
            str[--i]=27;}
        else
            str[i++]=ch;
        print(str,i);
    }
    return 0;
}
