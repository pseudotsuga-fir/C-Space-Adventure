gcc -c input.c
gcc -c main.c
gcc -c ./cJSON/cJSON.c
gcc -o main input.o main.o cJSON.o
./main planetarySystem.json