#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include "input.h"
#include "./cJSON/cJSON.h"

//Max of 20 planets.
char *planet_names[20];
char *planet_descs[20];
char *system_name;
int system_size;

void createJSONtree(char *filePath)
{
    //Opening the file and storing it as a string.
    FILE *fptr = fopen(filePath ,"rb");
    fseek(fptr, 0L, SEEK_END);
    long bytes = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);
    char *rawJSON = (char*)calloc(bytes, sizeof(char));
    fread(rawJSON, sizeof(char), bytes, fptr);
    fclose(fptr);

    //Using cJSON to create the JSON tree.
    const cJSON *name = NULL;
    const cJSON *planets = NULL;
    const cJSON *planet = NULL;

    cJSON *planets_json = cJSON_Parse(rawJSON);

    name = cJSON_GetObjectItemCaseSensitive(planets_json, "name");
    system_name = name->valuestring;

    planets = cJSON_GetObjectItemCaseSensitive(planets_json, "planets");
    int i = 0;
    cJSON_ArrayForEach(planet, planets){
        cJSON *planet_name = cJSON_GetObjectItemCaseSensitive(planet, "name");
        cJSON *planet_desc = cJSON_GetObjectItemCaseSensitive(planet, "description");
      planet_names[i] = planet_name->valuestring;
        planet_descs[i] = planet_desc->valuestring;
      i += 1;
    }
    system_size = i;
}
void printIntro()
{
    printf("Welcome to the %s. There are %u planets to explore.\n", system_name, system_size);
}

char * getInput(char prompt[120])
{
    static char input[120];
    printf("%s", prompt);
    fgets(input, 120, stdin);
    input[strcspn(input, "\n")] = 0;
    return input;
}

void printGreeting(char name[120])
{
    printf("Welcome ");
    printf("%s", name);
}

int askRandomPlanet(char choice[120])
{
  //Function returns 1 if player chooses random planet, 0 if they choose not to go to a random planet.
    if(strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0){
    return 1;
    }
    else if(strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0){
    return 0;
    }
  else{
    printf("Sorry, I didn't understand.");
    askRandomPlanet(getInput("\nWould you like to travel to a random planet? (Y/N) : "));
  }
}

void randomPlanet()
{
  srand(time(NULL));
    int planet_i = rand() % system_size;
    printf("Let's go to %s\n", planet_names[planet_i]);
    printf("%s\n", planet_descs[planet_i]);
}

void playerPlanet(char choice[120])
{
    for(int i = 0; i < system_size; ++i){
    if(strcmp(choice, planet_names[i]) == 0){
        printf("Good choice. Let's go to %s!\n", planet_names[i]);
        printf("%s\n", planet_descs[i]);
        exit(0);
        }
    }
    printf("Sorry, I didn't understand.");
    playerPlanet(getInput("Where to instead? : "));
}