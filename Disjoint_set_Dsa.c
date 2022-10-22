#include <stdio.h>
#include <math.h>
int parent[100];
int rank[100];

void makeset(int v)
{
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findset(int v)
{
    while (parent[v] != v)
    {
        v=parent[v];
    }
    return v;
}
int munion(int u, int v)
{
    int r = findset(u);
    int s = findset(v);
    if (r == s)
        return r;
    else
    {
        if (rank[r] > rank[s])
            {
                parent[s] = r;
                rank[r] = rank[r] + rank[s] ;
                return r;
            }
        else
        {
            parent[r] = s;
            return s;
        }
    }
}

    int main()
    {
        int n, i, j, t;
        printf(" How many disjoint set you want to create?\n");
        scanf("%d", &n);
        makeset(n);
        printf("%d number of makeset operations are executed\n",n);
        printf("To stop Union operation, press -1\n");
        while (t != -1)
        {
            printf("Enter the value of t");
            scanf("%d", &t);
            if (t != -1)
            {
                printf("Enter i and j to perform Union(i,j) operation");
                printf("I = ");
                scanf("%d", &i);
                printf("J = ");
                scanf("%d", &j);
                munion(i, j);
                printf("UNION(%d,%d) is finished", i, j);
            }
        }
        int count=0,f;
        printf("Do you want to find the connected components");
        printf("Press ' 1 ' for YES or, ' 0 ' for NO\n");
        scanf("%d",&f);
        if (f == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d   ",findset(i));
                if (findset(i) == i){
                    count = count + 1;
                }
            }
            printf("The number of connected component is %d", count);
        }
        else
        {
            printf("We do not want to find the connected components");
        }
        return 0;
    }
