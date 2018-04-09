#include<stdio.h>
#include<stdlib.h>

#define max(a,b)(a>b?a:b)

int lcs(char *a,char *b,int m,int n,char **s){
    int i,j,k,l,t;
    int *z = calloc((n+1)*(m+1),sizeof(int));
    int **c = calloc((n+1),sizeof(int *));
    for(i = 0;i<=n;i++){
        c[i]= &z[i*(m+1)];
    }
    for(i = 1;i<=n;i++){
        for(j = 1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                c[i][j]= c[i-1][j-1]+1;
            }
            else{
                c[i][j]= max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    t = c[n][m];
    *s = malloc(t);
    for(i = n,j = m,k = t -1;k>=0;){
        if(a[i-1]==b[j-1]){
            (*s)[k]= a[i-1],i--,j--,k--;
        }
        else if(c[i][j-1]>c[i-1][j])
            j--;
        else
            i--;
    }
    free(c);
    free(z);
    return t;
}

int main(){
    char x[]="bdcaba";
    char y[]= "abcbdab";
    int m = sizeof(x);
    int n = sizeof(y);
    char *s = NULL;
    int re= lcs(x,y,m,n,&s);
    printf("% .*s \n %d",re,s,re);
    //printf("%s",s);
return 0;
}
