//C Space Adventure
#include <stdio.h>
#include <string.h>
// #include <json-c/json.h>

void printIntro()
{
  printf("Welcome to the solar system.\nThere are 9 planets to explore.\n");
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
  printf("Let's go to Neptune\n");
  printf("Neptune - A very cold planet, furthest from the sun.\n");
}

void playerPlanet(char choice[120]){
    printf("Good choice. Let's go to Mars!\n");
    printf("Mars - Known as the red planet.\n");
}

int main(int argc, char *argv[])
{
  // FILE *fp;
  // char json_buffer[1024];
  printIntro();
  printGreeting(getInput("What is your name? : "));
  if(askRandomPlanet(getInput("\nWould you like to travel to a random planet? (Y/N) : "))){
    randomPlanet();
  }
  else{
    playerPlanet(getInput("Where to instead? : "));
  }
}