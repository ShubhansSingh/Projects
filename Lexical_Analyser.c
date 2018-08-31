#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct hash
{
    char str[1000];
    struct hash *next;
};
struct hash *get(char *s)
{
    struct hash *p;
    p=(struct hash*)malloc(sizeof(struct hash));
    int i,k;
    k=strlen(s);
    for(i=0;i<=k;i++)
        p->str[i]=s[i];
    p->next=NULL;
    return p;
};
void insert(struct hash **h,char *s)
{
    struct hash *p,*r=NULL,*q;
    q=get(s);
    p=*h;
    while(p!=NULL)
    {
        r=p;
        p=p->next;
    }
    if(r==NULL)
    {
        *h=q;
        return ;
    }
    r->next=q;
}
int present(struct hash **h,char *s)
{
    struct hash *p;
    p=*h;
    while(p!=NULL)
    {
        if(!strcmp(s,p->str))
            return 1;
        p=p->next;
    }
    return 0;
}
void print(struct hash **h)
{
    struct hash *p;
    p=*h;
    printf("\n\t\tThe contents of hash table are : \n");
    while(p!=NULL){
        printf("\t\t\t\t\t\t%s\n",p->str);
        p=p->next;
    }
}
int constant(char p)
{
    if(p=='0' || p=='1' || p=='2' || p=='3' || p=='4' || p=='5' || p=='6' || p=='7' || p=='8' || p=='9')
        return 1;
    return 0;
}
int delimiter(char a)
{
    if (a == ' ' || a == '+' || a == '-' || a == '*' || a == '/' || a == ',' || a == ';' || a == '>' ||
        a == '<' || a == '=' || a == '(' || a == ')' || a == '[' || a == ']' || a == '{' || a == '}')
        return 1;
    return 0;
}
int keyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int")
|| !strcmp(str, "double") || !strcmp(str, "float")|| !strcmp(str, "return") || !strcmp(str, "char")
|| !strcmp(str, "case") || !strcmp(str, "for") || !strcmp(str, "sizeof") || !strcmp(str, "long")
|| !strcmp(str, "short") || !strcmp(str, "typedef")|| !strcmp(str, "switch") || !strcmp(str, "unsigned")
|| !strcmp(str, "void") || !strcmp(str, "static")|| !strcmp(str, "struct") || !strcmp(str, "goto"))
        return 1;
    return 0;
}
int variable(char *str)
{
    int k;
    k=str[0];
    if(k==95 || (k>96 && k<123) || (k>64 && k<91))
        return 1;
    return 0;
}
void substring(char *str,char *sub,int i,int j)
{
    int k=0;
    for(i=i;i<=j;i++){
        sub[k++]=str[i];
        //printf("\t%c",str[i]);
            }
    sub[k]='\0';
    //printf("\n%s\n",sub);
}
void statements(char *str)
{
    struct hash *p=NULL;
    char sub[500];
    int i,len,j;
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        for(j=i;j<len && str[j]!=' ';j++){
            if(delimiter(str[j]))
               break;
        }
        if(j>i)
            substring(str,sub,i,j-1);
        //printf("\n%d %d %s\n",i,j-1,sub);
        if(keyword(sub))
            printf("\t\t%s is a keyword\n",sub);
        else if(variable(sub)){
                if(!present(&p,sub)){
            printf("\t\t%s is a variable\n",sub);
            insert(&p,sub);
        }}
        i=j;
        //printf("\n %d %d ",i,j);
    }
    print(&p);
}
int main()
{
    char str[1000];
    scanf("%[^\n]%*c",str);
    statements(str);
    return 0;
}
