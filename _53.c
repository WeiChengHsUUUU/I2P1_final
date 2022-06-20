#include <stdio.h>
#define MAXNV 5

int water[6];
int tempcup[6];
int cup[6];
int ans = -1;

void show(int n);
void filling(int amount, int wc, int N);

int main(void)
{
    int N, amount;

    scanf("%d", &N);
    for(int x = 1;x <= N;x++){
        scanf("%d", &water[x]);
    }

    scanf("%d", &amount);
    filling(amount, 1, N);

    show(N);

    return 0;
}

void show(int n)
{
    int i;
    //printf("(%d", tempcup[1]);
    printf("(%d", cup[1]);
    for (i=2; i<=n; i++) {
        //printf(",%d", tempcup[i]);
        printf(",%d", cup[i]);
    }
    printf(")\n");
}

void filling(int amount, int wc, int N)
{
    //printf("1");
    if(amount == 0 && N < wc){
        int tempans = 0;
        for(int x = 1;x <= N;x++){
            tempans += tempcup[x];
        }
        if(ans > tempans || ans == -1){
            ans = tempans;
            for(int x = 1;x <= N;x++){
                cup[x] = tempcup[x];
            }
        }
    }
    if(amount >= 0 && N >= wc){
        for(int x = 0;x*water[wc] <= amount;x++){
            tempcup[wc] = x;
            filling(amount - x*water[wc], wc+1, N);
        }
    }
}
