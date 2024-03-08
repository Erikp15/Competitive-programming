//|Encho
#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;
typedef long long llong;

llong C[62][62];
void precomputeC()
{
    int i,j;

    C[0][0] = 1LL;
    for (i=1;i<=60;i++)
    {
        C[i][0] = 1LL;
        for (j=1;j<=i;j++)
        {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

int n, U;
bool exists[62];
int mapped[62];
int seq[1000111];
int uniqueCount = 0;

int fixedVal[62];

llong countByFixed()
{
    int i;
    int L = 1, R = 1;
    int rangeCount = 0;
    llong res = 1;

    fixedVal[uniqueCount+1] = U + 1;
    for (i=1;i<=uniqueCount+1;i++)
    {
        if (fixedVal[i] != 0)
        {
            R = fixedVal[i] - 1;
            if (rangeCount > R - L + 1)
                return 0;
            res *= C[R - L + 1][rangeCount];

            L = fixedVal[i] + 1;
            rangeCount = 0;
        }
        else
            rangeCount++;
    }

    return res;
}

int main()
{
    precomputeC();
    int i,j;

    scanf("%d %d",&n,&U);
    assert(n >= 1 && n <= 1000000 && U >= 1 && U <= 60);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&seq[i]);
        assert(seq[i] >= 1 && seq[i] <= U);

        exists[ seq[i] ] = true;
    }

    for (i=1;i<=U;i++)
    {
        if (exists[i])
        {
            uniqueCount++;
            mapped[i] = uniqueCount;
        }
    }

    llong total = (C[U][uniqueCount] + 1LL) / 2LL;
    for (i=1;i<=n;i++)
    {
        seq[i] = mapped[ seq[i] ];

        if (fixedVal[ seq[i] ])
            continue;

        for (j=seq[i];j<=U;j++)
        {
            fixedVal[ seq[i] ] = j;
            llong curCount = countByFixed();

            if (curCount < total)
                total -= curCount;
            else
                break;
        }
    }

    for (i=1;i<=n;i++)
    {
        printf("%d", fixedVal[ seq[i] ]);
        if (i != n)
            printf(" ");
    }
    printf("\n");

    return 0;
}
