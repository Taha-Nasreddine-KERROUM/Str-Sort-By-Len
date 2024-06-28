#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void pswap ( char **p, char **q )
{
    char *temp = *p;
    *p = *q;
    *q = temp;
}

void get ( char ***t, int n )
{
    *t = ( char** ) malloc ( n * sizeof(char*) );
    int i = 0;
    for ( char **p = *t; p < *t + n; ++p ) {
        char s[100];
        long int u = p - *t;
        printf(" string number %ld: ", u);
        gets (s);
        int l = strlen(s);
        *p = ( char* ) malloc ( l + 1 );
        strcpy(*p, s);
        int L = strlen ( *(*t + u) );
        while (u > 0 && (strlen(*(*t + u - 1)) > strlen(*(*t + u)))) {
            pswap((*t + u), (*t + u - 1));
            u--;
        }
    }
}

void display ( char **t, int n )
{
    for ( char **p = t; p < t + n; p++ )
        puts(*p);
}


int main()
{
    int n;
    char **T;
    printf(" enter strings num: ");
    scanf("%d%*c", &n);
    get ( &T, n );
    display( T, n );
    
    return 0;
}
