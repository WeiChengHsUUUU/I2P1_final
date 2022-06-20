#include <stdio.h>

int arr[1024];

void dfs(int now, int n);

int main(void)
{
    int n;

    scanf("%d", &n);
    for(int x = 1;x <= n;x++){
        scanf("%d", &arr[x]);
    }
    dfs(1, n);

    return 0;
}

void dfs(int now, int n)
{
    if(now < n)
        dfs(2*now, n);
    if(now < n)
        printf("%d ", arr[now]);
    if(now == n)
        printf("%d\n", arr[now]);
    if(now < n)
        dfs(2*now+1, n);

}
