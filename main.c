//C Space Adventure
#include <stdio.h>
#include <string.h>
// #include <json-c/json.h>

int main(int argc, char *argv[])
{
  // FILE *fp;
  // char json_buffer[1024];
  char name[120];
  char yn_choice[4];
  char user_planet[120];
  printf("Welcome to the solar system.\nThere are 9 planets to explore.\n");
  printf("What is your name? : ");
  fgets(name, 120, stdin);
  name[strcspn(name, "\n")] = 0;
  printf("Welcome ");
  puts(name);
  printf("Would you like to travel to a random planet? (Y/N) : ");
  fgets(yn_choice, 4, stdin);
  yn_choice[strcspn(yn_choice, "\n")] = 0;
  if(strcmp(yn_choice, "Y") == 0 || strcmp(yn_choice, "y") == 0){
    printf("Let's go to Neptune\n");
    printf("Neptune - A very cold planet, furthest from the sun.\n");
  }
  else if(strcmp(yn_choice, "N") == 0 || strcmp(yn_choice, "n") == 0){
    printf("Where to instead? : ");
    fgets(user_planet, 120, stdin);
    user_planet[strcspn(user_planet, "\n")] = 0;
    printf("Good choice. Let's go to Mars!\n");
    printf("Mars - Known as the red planet.\n");

  }
  else{
    printf("Sorry, I didn't understand.");
  }
}
