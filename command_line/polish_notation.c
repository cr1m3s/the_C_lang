#include <stdio.h>
#include <stdlib.h>

/*
    Reversed polish notation from commanf line, using int values:
        a.out 1 2 + --> 1 + 2 --> 3

    In oder to use * use escape symbol or quotes
    i.e

        a.out 1 2 3 \* / --> 1 * 2 / 3 --> 0
        a.out 1 2 3 '*' / --> 1  * 2 / --> 0
*/

int is_number(char *number)
{
    for (int i = 0; number[i] != '\0'; i++)
    {
        if (!(number[i] >= 48 && number[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    //    for (int i = 0; i < argc; i++)
    //    {
    //        printf("i: %d, str: %s\n", i, argv[i]);
    //    }

    int base = atoi(argv[1]);
    int number_counter = 0;
    int action_counter = 0;
    int tmp = 0;

    for (int i = 2; i < argc; i++)
    {
        if (!is_number(argv[i]))
        {
            action_counter = i;
            number_counter = i;
            break;
        }
    }

    //    printf("act: %d num: %d\n", action_counter, number_counter);

    for (int i = 2; i < number_counter && action_counter < argc; i++, action_counter++)
    {
        tmp = atoi(argv[i]);
        //    printf("%d=%c=%d\n", tmp, argv[action_counter][0], action_counter);
        switch (argv[action_counter][0])
        {
        case '-':
            base -= tmp;
            break;
        case '+':
            base += tmp;
            break;
        case '*':
            base *= tmp;
            break;
        case '/':
            base /= tmp;
            break;
        default:
            break;
        }
    }

    printf("%d\n", base);
}
