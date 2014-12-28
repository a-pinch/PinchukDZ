#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Input number: ");
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
        for(int i=0; i<=k; i++){
            for(int j=0;j<=n*2; j++){
                printf("%c", (i == k && (j>n-i && j<n+i)) || n - i == j || n + i == j ? '*' : ' ');
            }
            printf("\n");
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<=n+1;j++){
            printf("%c",j == n-1 || j == n+1 ? '*' : ' ');
        }
        printf("\n");
    }
    return 0;
}
