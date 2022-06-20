#include <stdio.h>
#include <string.h>

void dfs(int now, int n, int *meet, int verx[2001][26]);
int connect(int a, int b, int verx[2001][26]);

char str[2001][1001];
int verx[2001][26];


int main(void)
{
    int t, n;

    scanf("%d", &t);
    while(t--){
        int verx[2001][26] = {0};
        int meet[2001] = {0};
        int ans = 0;

        scanf("%d", &n);
        for(int x = 0;x < n;x++){
            scanf("%s", &str[x]);
            int s_len = strlen(str[x]);
            for(int y = 0;y < s_len/2+1;y++){
                ++verx[x][str[x][y]-'a'];
                ++verx[x][str[x][s_len-1-y]-'a'];
            }
        }

        for(int x = 0;x < n;x++){
            if(meet[x] != 1){
                ans++;
                dfs(x, n, meet, verx);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

void dfs(int now, int n, int *meet, int verx[2001][26])
{
    if(meet[now] == 1)
        return;
    meet[now] = 1;
    for(int x = 0;x < n;x++){
        if((x != now && meet[x] != 1) && connect(now, x, verx) == 1)
            dfs(x, n, meet, verx);
    }
}

int connect(int a, int b, int verx[2001][26])
{
    for(int x = 0;x < 26; x++){
        if(verx[a][x] > 0 && verx[b][x] > 0)
            return 1;
    }
    return 0;
}
