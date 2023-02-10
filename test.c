#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../ft_printf.h"

#define OK printf("\033[1;92m             OK\033[0;39m\n")
#define ALRIGHT ("\033[1;33m             OK\033[0;39m\n")
#define KO printf("\033[1;91m             KO\033[0;39m\n")

int    mandatory(int exit_status);
int    bonus(int exit_status);

int main(int argc, char **argv) {
    int         exit_status = 0;

    if (argc == 1)
    {
        printf("\033[1;4;30m            TO RUN TYPE ./test.sh PLUS           \033[0;39m\n");
        printf("\033[1;4;30m|              ONE OF THESE FLAGS:              |\033[0;39m\n");
        printf("\033[1;4;30m|                   MANDATORY                   |\033[0;39m\n");
        printf("\033[1;4;30m|                       a                       |\033[0;39m\n");
        printf("\033[1;4;30m|                     BONUS                     |\033[0;39m\n");
        printf("\033[1;4;30m|                       b                       |\033[0;39m\n");
        printf("\033[1;4;30m|                     BOTH                      |\033[0;39m\n");
        printf("\033[1;4;30m|                       a                       |\033[0;39m\n");
        exit_status = 42;
        exit(exit_status);
    } 
    else if (argc == 2) {
        if (strcmp(argv[1], "m") == 0) {
            exit(mandatory(exit_status));
        }
        else if (strcmp(argv[1], "b") == 0) {
            exit(bonus(exit_status));
        }
        else if (strcmp(argv[1], "a") == 0) {
			exit_status = mandatory(exit_status);
			exit_status = bonus(exit_status);
            exit(exit_status); 
        }
    }
    exit(exit_status);
}

int    mandatory(int exit_status)
{
    int         result;
    char        c = 'A';
    char        *s = "hello";
    int         i = 42;
    unsigned int u = 24;
    void        *p = &result;
    unsigned int hex_x = 3197704835;
    unsigned int hex_X = 3197704835;
    int         min = -2147483648;
    int         max = 2147483647;
    long int    wrong_min = -2147483680;
    long int    wrong_max = 2147483680;

            printf("\033[1;4;30m       MANDATORY PART       \033[0;39m\n");
            // case 1:
            printf("\033[1;4;30m           TEST 1           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %c\n", c);
            if (result == printf("       \x1B[1;36m[-_-printf]: %c\n", c)) OK;
            else { KO; exit_status = 1; };

            // case 2:
            printf("\033[1;4;30m           TEST 2           \033[0;39m\n");
            result = ft_printf("     \x1B[1;36m[ft_printf]: %s\n", s);
            if (result == printf("     \x1B[1;36m[-_-printf]: %s\n", s)) OK;
            else { KO; exit_status = 1; };

            // case 3:
            printf("\033[1;4;30m           TEST 3           \033[0;39m\n");
            result = ft_printf("\x1B[1;36m[ft_printf]: %p\n", p);
            if (result == printf("\x1B[1;36m[-_-printf]: %p\n", p)) OK;
            else { KO; exit_status = 1; };
            
            // case 4:
            printf("\033[1;4;30m           TEST 4           \033[0;39m\n");
            result = ft_printf("      \x1B[1;36m[ft_printf]: %d\n", i);
            if (result == printf("      \x1B[1;36m[-_-printf]: %d\n", i)) OK;
            else { KO; exit_status = 1; };

            // case 5:
            printf("\033[1;4;30m           TEST 5           \033[0;39m\n");
            result = ft_printf("      \x1B[1;36m[ft_printf]: %i\n", i);
            if (result == printf("      \x1B[1;36m[-_-printf]: %i\n", i)) OK;
            else { KO; exit_status = 1; };
            
            // case 6:
            printf("\033[1;4;30m           TEST 6           \033[0;39m\n");
            result = ft_printf("      \x1B[1;36m[ft_printf]: %u\n", u);
            if (result == printf("      \x1B[1;36m[-_-printf]: %u\n", u)) OK;
            else { KO; exit_status = 1; };
            
            // case 7:
            printf("\033[1;4;30m           TEST 7           \033[0;39m\n");
            result = ft_printf("   \x1B[1;36m[ft_printf]: %x\n", hex_x);
            if (result == printf("   \x1B[1;36m[-_-printf]: %x\n", hex_x)) OK;
            else { KO; exit_status = 1; };
            
            // case 8:
            printf("\033[1;4;30m           TEST 8           \033[0;39m\n");
            result = ft_printf("   \x1B[1;36m[ft_printf]: %X\n", hex_X);
            if (result == printf("   \x1B[1;36m[-_-printf]: %X\n", hex_X)) OK;
            else { KO; exit_status = 1; };
            
            // case 9:
            printf("\033[1;4;30m           TEST 9           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %%\n");
            if (result == printf("       \x1B[1;36m[-_-printf]: %%\n")) OK;
            else { KO; exit_status = 1; };

            // case 10:
            printf("\033[1;4;30m          TEST 10           \033[0;39m\n");
            result = ft_printf("     \x1B[1;36m[ft_printf]: %% %%%% %%\n");
            if (result == printf("     \x1B[1;36m[-_-printf]: %% %%%% %%\n")) OK;
            else { KO; exit_status = 1; };

            // case 11 where you probably fail:
            printf("\033[1;4;30m          TEST 11           \033[0;39m\n");
            result = ft_printf("%");
            if (result == -1) OK;
            else { KO; exit_status = 1; };

            // case 12:
            printf("\033[1;4;30m          TEST 12           \033[0;39m\n");
            result = ft_printf("  \x1B[1;36m[ft_printf]: %d\n", min);
            if (result == printf("  \x1B[1;36m[-_-printf]: %d\n", min)) OK;
            else { KO; exit_status = 1; };

            // case 13:
            printf("\033[1;4;30m          TEST 13           \033[0;39m\n");
            result = ft_printf("  \x1B[1;36m[ft_printf]: %d\n", max);
            if (result == printf("  \x1B[1;36m[-_-printf]: %d\n", max)) OK;
            else { KO; exit_status = 1; };

            // case 14:
            printf("\033[1;4;30m          TEST 12           \033[0;39m\n");
            result = ft_printf("  \x1B[1;36m[ft_printf]: %d\n", wrong_min);
            if (result == printf("  \x1B[1;36m[-_-printf]: %d\n", wrong_min)) OK;
            else { KO; exit_status = 1; };

            // case 15:
            printf("\033[1;4;30m          TEST 13           \033[0;39m\n");
            result = ft_printf("  \x1B[1;36m[ft_printf]: %d\n", wrong_max);
            if (result == printf("  \x1B[1;36m[-_-printf]: %d\n", wrong_max)) OK;
            else { KO; exit_status = 1; };
            return(exit_status);
}

int    bonus(exit_status)
{
    int         result;
    char        c = 'A';
    char        *s = "hello";
    int         i = 42;
    unsigned int u = 24;
    void        *p = &result;
    unsigned int hex_x = 3197704835;
    unsigned int hex_X = 3197704835;
    int         min = -2147483648;
    int         max = 2147483647;
    long int    wrong_min = -2147483680;
    long int    wrong_max = 2147483680;

            printf("\033[1;4;30m         BONUS PART         \033[0;39m\n");

            // case 1:
            printf("\033[1;4;30m           TEST 1           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %0c\n", c);
            if (result == printf("       \x1B[1;36m[-_-printf]: %0c\n", c)) OK;
            else { KO; exit_status = 1; };

            // case 2:
            printf("\033[1;4;30m           TEST 2           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %5c\n", c);
            if (result == printf("       \x1B[1;36m[-_-printf]: %5c\n", c)) OK;
            else { KO; exit_status = 1; };

            // case 3:
            printf("\033[1;4;30m           TEST 3           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %#5x\n", 42);
            if (result == printf("       \x1B[1;36m[-_-printf]: %#5x\n", 42)) OK;
            else { KO; exit_status = 1; };

            // case 4:
            printf("\033[1;4;30m           TEST 4           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %+d\n", 42);
            if (result == printf("       \x1B[1;36m[-_-printf]: %+d\n", 42)) OK;
            else { KO; exit_status = 1; };

            // case 5:
            printf("\033[1;4;30m           TEST 5           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %+.2f\n", 42.0);
            if (result == printf("       \x1B[1;36m[-_-printf]: %+.2f\n", 42.0)) OK;
            else { KO; exit_status = 1; };

            // case 6:
            printf("\033[1;4;30m           TEST 6           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: % d\n", 123);
            if (result == printf("       \x1B[1;36m[-_-printf]: % d\n", 123)) OK;
            else { KO; exit_status = 1; };

            // case 7:
            printf("\033[1;4;30m           TEST 7           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %-.3f\n", 42.0);
            if (result == printf("       \x1B[1;36m[-_-printf]: %-.3f\n", 42.0)) OK;
            else { KO; exit_status = 1; };

            // case 8:
            printf("\033[1;4;30m           TEST 8           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %-5c\n", 'a');
            if (result == printf("       \x1B[1;36m[-_-printf]: %-5c\n", 'a')) OK;
            else { KO; exit_status = 1; };

            // case 9:
            printf("\033[1;4;30m           TEST 9           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %0s\n", "hello");
            if (result == printf("       \x1B[1;36m[-_-printf]: %0s\n", "hello")) OK;
            else { KO; exit_status = 1; };

            // case 10:
            printf("\033[1;4;30m           TEST 10           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %#x\n", 42);
            if (result == printf("       \x1B[1;36m[-_-printf]: %#x\n", 42)) OK;
            else { KO; exit_status = 1; };

            // case 11:
            printf("\033[1;4;30m           TEST 11           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %+.3d\n", -42);
            if (result == printf("       \x1B[1;36m[-_-printf]: %+.3d\n", -42)) OK;
            else { KO; exit_status = 1; };

            // case 12:
            printf("\033[1;4;30m           TEST 12           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %#X\n", 42);
            if (result == printf("       \x1B[1;36m[-_-printf]: %#X\n", 42)) OK;
            else { KO; exit_status = 1; };

            // case 13:
            printf("\033[1;4;30m           TEST 13           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %05u\n", 42);
            if (result == printf("       \x1B[1;36m[-_-printf]: %05u\n", 42)) OK;
            else { KO; exit_status = 1; };

            // case 14:
            printf("\033[1;4;30m           TEST 14           \033[0;39m\n");
            result = ft_printf(" \x1B[1;36m[ft_printf]: %.2p\n", &result);
            if (result == printf(" \x1B[1;36m[-_-printf]: %.2p\n", &result)) OK;
            else { KO; exit_status = 1; };

            // case 15:
            printf("\033[1;4;30m           TEST 15           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %+5d\n", 42);
            if (result == printf("       \x1B[1;36m[-_-printf]: %+5d\n", 42)) OK;
            else { KO; exit_status = 1; };

            // case 16:
            printf("\033[1;4;30m           TEST 16           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %0d\n", -42);
            if (result == printf("       \x1B[1;36m[-_-printf]: %0d\n", -42)) OK;
            else { KO; exit_status = 1; };

            // case 17:
            printf("\033[1;4;30m           TEST 17           \033[0;39m\n");
            result = ft_printf("       \x1B[1;36m[ft_printf]: %.2%\n");
            if (result == printf("       \x1B[1;36m[-_-printf]: %.2%\n")) OK;
            else { KO; exit_status = 1; };
            return(exit_status);
}