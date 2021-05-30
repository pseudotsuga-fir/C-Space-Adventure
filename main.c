//C Space Adventure
#include <stdio.h>
#include <string.h>
#include "input.h"
// #include <json-c/json.h>

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