#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    printf("Input two numbers: ");
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            i%2==0?
            printf("%c", j%2==0?'*':' '):
            printf("%c", j%2!=0?'*':' ');
        }
        printf("\n");
    }
    return 0;
}
