#include <stdio.h>

int main(void)
{
    int i;
    char words[200];
    float result,sum;
    printf("Please input a char and word:\n");
    while(1){
        float arr[26] = {0};
        fgets(words, 200, stdin);

        for(i = 2; words[i] != '\0'; i++){
            if(words[i] >= 'A' && words[i] <= 'Z'){
                words[i] += 32;
            }
            arr[words[i] - 97]++;
        }

        for(i = 0, sum = 0; i < 26; i++){
            sum += arr[i];
        }

        result = arr[words[0] - 97]/sum;
        printf("Output:\nThe ans is %.5f", result);break;
    }
    return 0;
}
