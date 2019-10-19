#include <stdio.h>
#include <math.h>

int main()
{
    double p1,p21,p2,p31,p3,p41,p4,p51,p5;
    printf("Output:\n");
    p1=1000*(1+5*0.0475);
    p21=1000*(1+2*0.0375);p2=p21*(1+3*0.0425);
    p31=1000*(1+3*0.0425);p3=p31*(1+2*0.0375);
    p41=(1+0.03);p4=1000*pow(p41,5);
    p51=(1+0.0035/4);p5=1000*pow(p51,20);
    printf("P=%.2lf\n",p1);
    printf("P=%.2lf\n",p2);
    printf("P=%.2lf\n",p3);
    printf("P=%.2lf\n",p4);
    printf("P=%.2lf\n",p5);
    return 0;
}
