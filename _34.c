#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char knucles[1001][1001];
char *p[1001];

int compare(const void *a, const void *b)
{
    return strlen(*(const char**)a) - strlen(*(const char**)b);
}

int main(void)
{
    int n;

    scanf("%d", &n);
    for(int x = 0;x < n;x++){
        scanf("%s", &knucles[x]);
        p[x] = knucles[x];
    }

    qsort(p, n, sizeof(char*), compare);

    for(int x = 0;x < n-1;x++){
        if(strstr(p[x+1], p[x]) == NULL){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(int x = 0;x < n;x++){
        printf("%s\n", p[x]);
    }

    return 0;
}
