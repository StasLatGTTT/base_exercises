ARG=main
g++ $ARG.cpp -Wall -Werror -std=c++11 -o $ARG
./$ARG
rm $ARG
