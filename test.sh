#!/bin/bash

cd ..
make
cd ft_printf_tester
gcc test.c ../libftprintf.a -o tester 2> /dev/null
if [ $# -gt 1 ]; then
echo -e "\033[1;4;30m            TO RUN TYPE ./test.sh PLUS           \033[0;39m"
echo -e "\033[1;4;30m|              ONE OF THESE FLAGS:              |\033[0;39m"
echo -e "\033[1;4;30m|                   MANDATORY                   |\033[0;39m"
echo -e "\033[1;4;30m|                       a                       |\033[0;39m"
echo -e "\033[1;4;30m|                     BONUS                     |\033[0;39m"
echo -e "\033[1;4;30m|                       b                       |\033[0;39m"
echo -e "\033[1;4;30m|                     BOTH                      |\033[0;39m"
echo -e "\033[1;4;30m|                       a                       |\033[0;39m"
echo -e "\033[1;31m          ############################\033[0m"
echo -e "\033[1;31m          #  cookies, i like cookies #\033[0m"
echo -e "\033[1;31m          ############################\033[0m"
echo -e "\033[1;31m           Check test.c for the tests \033[0m"
exit 0
elif [ "$1" = "m" ]; then
echo -e "\033[1;31m############################\033[0m"
echo -e "\033[1;31m#     FT_PRINTF_TESTER     #\033[0m"
echo -e "\033[1;31m############################\033[0m"
./tester m
elif [ "$1" = "b" ]; then
echo -e "\033[1;31m############################\033[0m"
echo -e "\033[1;31m#     FT_PRINTF_TESTER     #\033[0m"
echo -e "\033[1;31m############################\033[0m"
./tester b
elif [ "$1" = "a" ]; then
echo -e "\033[1;31m############################\033[0m"
echo -e "\033[1;31m#     FT_PRINTF_TESTER     #\033[0m"
echo -e "\033[1;31m############################\033[0m"
./tester a
else
./tester
fi

result=$?

if [ $result -eq 42 ] || [ $result -eq 24 ]; then
    echo -e "\033[1;31m          ############################\033[0m"
	echo -e "\033[1;31m          #  cookies, i like cookies #\033[0m"
	echo -e "\033[1;31m          ############################\033[0m"
    echo -e "\033[1;31m           Check test.c for the tests \033[0m"
elif [ $result -eq 0 ]; then
    printf "\033c"
    echo -e "\n\033[35m♪┏(・o･)┛♪"
    sleep 1
    printf "\033c"
    echo -e "\033[1;33m♪┗(・o･)┓♪"
    sleep 1
    printf "\033c"
    echo -e "\n\033[36m♪┏(・o･)┛♪"
    sleep 1
    printf "\033c"
    echo -e "\033[34m♪┗(・o･)┓♪\n"
	echo -e "\033[1;92m    ############################\033[0m"
	echo -e "\033[1;92m    #            OK            #\033[0m"
	echo -e "\033[1;92m    ############################\033[0m"
	echo -e "\033[1;92mO_0K, you've passed all of my tests"
else
    echo -e "\033[1;31m############################\033[0m"
	echo -e "\033[1;31m#            KO            #\033[0m"
	echo -e "\033[1;31m############################\033[0m"
    echo -e "\033[1;31mCheck test.sh for test cases\033[0m"
fi
