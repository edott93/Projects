#include <stdio.h>

int main()
{
    char word[7] = "racecar";
    char temp_word[7];
    int count = 0;
    int i = 6;
    while(i > 0)
    {
        if(i == 0)
            count++;
        temp_word[count] = word[i];
        count++;
        i--;
        printf("count is %d, i is %d\n", count, i);
    }
    printf("%s\n", word);
    printf("%s\n", temp_word);
    for(i = 0; i < 6; i++)
    {
        if(temp_word[i] != word[i])
        {
            printf("%s is not a palindrome\n", word);
            return 0;
        }
    }
    printf("%s is a palindrome\n", word);
    return 0;
}
