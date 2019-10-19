#include <stdio.h>
#define MAXN 10

int a[MAXN][MAXN];
int b[MAXN][MAXN];

int main(){
        int n,i,j,mark=0;
        scanf("%d",&n);
                for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                                scanf("%d",&a[i][j]);
                        }
                }
                for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                                scanf("%d",&b[i][j]);
                        }
                }
                for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                                if(a[i][j]!=b[i][j]){
                                        mark =1;
                                        i=n;
                                        j=n;
                                }
                        }
                }
				printf("Output:");
                if(mark==0){
                        printf("0\n");
                }else{
                        for(i=0;i<n;i++){
                                for(j=0;j<n;j++){
                                        if(a[i][j]!=b[j][n-i-1]){
                                                mark=0;
                                                i=n;
                                                j=n;
                                        }
                                }
                        }
                        if(mark==1){
                                printf("90\n");
                        }else{
                                for(i=0;i<n;i++){
                                        for(j=0;j<n;j++){
                                                if(a[i][j]!=b[n-i-1][n-j-1]){
                                                        mark=1;
                                                        i=n;
                                                        j=n;
                                                }
                                        }
                                }
                                if(mark==0){
                                        printf("180\n");
                                }else{
                                        for(i=0;i<n;i++){
                                                for(j=0;j<n;j++){
                                                        if(a[i][j]!=b[n-j-1][i]){
                                                                mark=0;
                                                                i=n;
                                                                j=n;
                                                        }
                                                }
                                        }
                                        if(mark==1){
                                                printf("270\n");
                                        }
                                        if(mark==0)
                                                printf("-1\n");
                                }
                        }

        }
        return 0;
}
