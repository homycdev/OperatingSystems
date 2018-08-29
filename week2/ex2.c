#include <stdio.h>

main(void)
{
    int amount;
    printf("How many letters in your word?\n");
    scanf("%d", &amount);
 
    char a[amount]; 
    scanf("%s" , a);
    printf("Your reversed word: \n");
    for(int i = amount; i >= 0; i--){
        printf("%c", a[i]);
    }
    printf("\n");
    
    
    return 0;
}