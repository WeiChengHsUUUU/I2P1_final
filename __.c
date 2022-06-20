#include <stdio.h>

char word[12][16];
char letter[301];
int score[26];

int main(void)
{
    int t;

    scanf("%d", &t)
    while(t--){
        int wordlen, letterlen;
        scanf("%d%D", &wordlen, &letterlen);
        for(int i = 0;i < wordlen;i++) scanf("%s", &word[i]);
        scanf("%s", letter);

    }

    return 0;
}
