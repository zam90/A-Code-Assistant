#include <stdio.h>

int main()
{
    int n;
    printf("Please input test times: ");
    scanf("%d",&n);
    double a[n],b[n][3],s=0;
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf:%lf:%lf",&a[i],&b[i][1],&b[i][2],&b[i][3]);
    }
    for(i=0;i<n;i++)
    {
        s=s+a[i]*b[i][1]+a[i]*b[i][2]/60+a[i]*b[i][3]/3600;
    }
    printf("\nOutput:\nHad went [%.2lf] km",s);
    return 0;
}
