#include <stdio.h>

int main() {

        int dat[51];

        int n, i, temp;
		printf("Input n: ");

        scanf("%d", &n);
		printf("Input n numbers: ");

        for (i = 0;i < n;i++)

                scanf("%d", &dat[i]);
 				printf("Output:\n");
        for (i = 0;i + i < n;i++) {

                temp = dat[i];

                dat[i] = dat[n - 1 - i];

                dat[n - 1 - i] = temp;

        }

        for (i = 0;i < n;i++)

                printf("%d ", dat[i]);

        puts("");

        return 0;

}
