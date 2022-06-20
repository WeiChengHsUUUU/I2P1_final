#include <stdio.h>

typedef struct mat{
    float p[5][5];
}mat;
typedef struct pup{
    float arr[5];
}pup;

void trans(pup pp, mat m, float p, int n);
pup re(pup pp, mat m, int n);

int main(void)
{
    int T, n;
    float p;
    mat m;
    pup pp;

    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int x = 0;x < n;x++){
            for(int y = 0;y < n;y++){
                scanf("%f", &m.p[x][y]);
            }
        }
        for(int x = 0;x < n;x++){
            scanf("%f", &pp.arr[x]);
        }
        scanf("%f", &p);

        trans(pp, m, p, n);
    }

    return 0;
}

void trans(pup pp, mat m, float p, int n)
{
    long long int ans = 0;
    int sign = 0;

    while(pp.arr[0] > p){
        pup temp = re(pp, m, n);
        //printf("1\n");
        if(temp.arr[0] == pp.arr[0]){
            sign = 1;
            break;
        }
        pp = temp;
        ++ans;
    }
    if(sign == 1){
        printf("Never\n");
    }else{
        printf("%lld\n", ans);
    }
}

pup re(pup pp, mat m, int n)
{
    pup temp ;
    for(int x = 0;x < n;x++){
            temp.arr[x] = 0;
            for(int y = 0;y < n;y++){
                temp.arr[x] += pp.arr[y]*m.p[x][y];
            }
    }
    return temp;
}
