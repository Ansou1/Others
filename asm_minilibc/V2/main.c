#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUT(s)	printf("/* TEST DE %s */\n", s);
#define FIN		printf("/* FIN */\n\n");

int		main()
{
  char		*s1;
  char		*s2;
  char		*s3;
  char		*s4;

  /*
/////////////////////////////////////////////////////
/////////////////////// STRLEN //////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("STRLEN");
  s1 = strdup("azertyu");
  printf("strlen(%s) = [%d].\n", s1, strlen(s1));
  printf("strlen(%s) = [%d].\n", s1, strlen(s1));

  s1 = strdup("abcdefghijklmnopqrstuvwxyz");
  printf("strlen(%s) = [%d].\n", s1, strlen(s1));
  printf("strlen(%s) = [%d].\n", s1, strlen(s1));

  s1 = strdup("");
  printf("strlen(%s) = [%d].\n", s1, strlen(s1));
  printf("strlen(%s) = [%d].\n", s1, strlen(s1));
  FIN;

  /*
/////////////////////////////////////////////////////
/////////////////////// MEMSET //////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("MEMSET");
  s2 = malloc(20);
  printf("Apres: [%s].\n", memset(s2, 'a', 12));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));
  free(s2);

  s2 = malloc(20);
  printf("Apres: [%s].\n", memset(s2, '0', 12));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));
  FIN;
  free(s2);
  DEBUT("MY_MEMSET");
  s2 = malloc(20);
  printf("Apres: [%s].\n", memset(s2, 'a', 12));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));
  free(s2);
  s2 = malloc(20);
  printf("Apres: [%s].\n", memset(s2, '0', 12));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));
  FIN;
  free(s2);

  /*
/////////////////////////////////////////////////////
/////////////////////// STRCMP //////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("STRCMP");
  s1 = strdup("azertyuiop");
  s2 = strdup("azertyuiop");
  if (strcmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcmp(s1, s2));

  s1 = strdup("");
  s2 = strdup("azertyuiop");
  if (strcmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcmp(s1, s2));

  s1 = strdup("azertyuiop");
  s2 = strdup("");
  if (strcmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcmp(s1, s2));

  s1 = strdup("");
  s2 = strdup("");
  if (strcmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  FIN;

  DEBUT("MY_STRCMP");
  s1 = strdup("azertyuiop");
  s2 = strdup("azertyuiop");
  if (strcmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcmp(s1, s2));

  s1 = strdup("");
  s2 = strdup("azertyuiop");
  if (strcmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcmp(s1, s2));

  s1 = strdup("azertyuiop");
  s2 = strdup("");
  if (strcmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcmp(s1, s2));

  s1 = strdup("");
  s2 = strdup("");
  if (strcmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  else if (strcmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcmp(s1, s2));
  FIN;

  /*
/////////////////////////////////////////////////////
/////////////////////// STRNCMP /////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("STRNCMP");

  s1 = strdup("azertyPuiop");
  s2 = strdup("azertyPuiop");
  if (strncmp(s1, s2, 6) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));
  else if (strncmp(s1, s2, 6) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));
  else if (strncmp(s1, s2, 6) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));

  if (strncmp(s1, s2, 9) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));
  else if (strncmp(s1, s2, 9) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));
  else if (strncmp(s1, s2, 9) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));

  s1 = strdup("azertyVuiop");
  s2 = strdup("azertyPuiop");
  if (strncmp(s1, s2, 6) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));
  else if (strncmp(s1, s2, 6) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));
  else if (strncmp(s1, s2, 6) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));

  if (strncmp(s1, s2, 9) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));
  else if (strncmp(s1, s2, 9) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));
  else if (strncmp(s1, s2, 9) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));

  s1 = strdup("azertyuiop");
  s2 = strdup("azertyuiop");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("");
  s2 = strdup("azertyuiop");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("azertyuiop");
  s2 = strdup("");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("");
  s2 = strdup("");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  if (strncmp(s1, s2, 3) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 3));
  else if (strncmp(s1, s2, 3) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 3));
  else if (strncmp(s1, s2, 3) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 3));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  if (strncmp(s1, s2, 0) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 0));
  else if (strncmp(s1, s2, 0) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 0));
  else if (strncmp(s1, s2, 0) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 0));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  if (strncmp(s1, s2, -1) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, -1));
  else if (strncmp(s1, s2, -1) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, -1));
  else if (strncmp(s1, s2, -1) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, -1));
  FIN;

  DEBUT("MY_STRNCMP");

  s1 = strdup("azertyPuiop");
  s2 = strdup("azertyPuiop");
  if (strncmp(s1, s2, 6) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));
  else if (strncmp(s1, s2, 6) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));
  else if (strncmp(s1, s2, 6) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));

  if (strncmp(s1, s2, 9) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));
  else if (strncmp(s1, s2, 9) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));
  else if (strncmp(s1, s2, 9) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));

  s1 = strdup("azertyVuiop");
  s2 = strdup("azertyPuiop");
  if (strncmp(s1, s2, 6) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));
  else if (strncmp(s1, s2, 6) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));
  else if (strncmp(s1, s2, 6) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 6));

  if (strncmp(s1, s2, 9) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));
  else if (strncmp(s1, s2, 9) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));
  else if (strncmp(s1, s2, 9) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 9));

  s1 = strdup("azertyuiop");
  s2 = strdup("azertyuiop");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("");
  s2 = strdup("azertyuiop");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("azertyuiop");
  s2 = strdup("");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("");
  s2 = strdup("");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  if (strncmp(s1, s2, 8) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));
  else if (strncmp(s1, s2, 8) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 8));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  if (strncmp(s1, s2, 3) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 3));
  else if (strncmp(s1, s2, 3) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 3));
  else if (strncmp(s1, s2, 3) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 3));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  if (strncmp(s1, s2, 0) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 0));
  else if (strncmp(s1, s2, 0) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 0));
  else if (strncmp(s1, s2, 0) == 0)
    printf("[%s] = [%s] = [%d]\n", s1, s2, strncmp(s1, s2, 0));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  if (strncmp(s1, s2, -1) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strncmp(s1, s2, -1));
  else if (strncmp(s1, s2, -1) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strncmp(s1, s2, -1));
  else if (strncmp(s1, s2, -1) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strncmp(s1, s2, -1));

  FIN;

  /*
/////////////////////////////////////////////////////
/////////////////////// MEMCPY //////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("MEMCPY");
  s1 = strdup("aaaaaaaaaaaa");
  s2 = strdup("bbbbbbbbbbbb");
  printf("Apres: [%s].\n", memcpy(s1, s2, 4));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memcpy(s2, s1, 4));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  s1 = strdup("aaaaaaaaaaaa");
  s2 = strdup("bbbbbbbbbbbb");
  printf("Apres: [%s].\n", memcpy(s1, s2, 0));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memcpy(s2, s1, 0));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  FIN;

  DEBUT("MY_MEMCPY");
  s1 = strdup("aaaaaaaaaaaa");
  s2 = strdup("bbbbbbbbbbbb");
  printf("Apres: [%s].\n", memcpy(s1, s2, 4));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memcpy(s2, s1, 4));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  s1 = strdup("aaaaaaaaaaaa");
  s2 = strdup("bbbbbbbbbbbb");
  printf("Apres: [%s].\n", memcpy(s1, s2, 0));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memcpy(s2, s1, 0));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  FIN;

  /*
/////////////////////////////////////////////////////
/////////////////////// STRCHR //////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("STRCHR");
  s1 = strdup("aaaaaacaaaaa");
  printf("Apres: [%s].\n", strchr(s1, 'c'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("Bonjour comment tu vas?");
  printf("Apres: [%s].\n", strchr(s1, 'c'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("");
  printf("Apres: [%s].\n", strchr(s1, 'c'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("abcdef");
  printf("Apres: [%s].\n", strchr(s1, 'z'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  FIN;

  DEBUT("MY_STRCHR");
  s1 = strdup("aaaaaacaaaaa");
  printf("Apres: [%s].\n", strchr(s1, 'c'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("Bonjour comment tu vas?");
  printf("Apres: [%s].\n", strchr(s1, 'c'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("");
  printf("Apres: [%s].\n", strchr(s1, 'c'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("abcdef");
  printf("Apres: [%s].\n", strchr(s1, 'z'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  FIN;

  /*
/////////////////////////////////////////////////////
/////////////////////// MEMMOVE //////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("MEMMOVE");

  s1 = strdup("aaaaaaaaaaaa");
  s2 = strdup("bbbbbbbbbbbb");
  printf("Apres: [%s].\n", memmove(s1, s2, 4));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memmove(s2, s1, 4));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  s1 = strdup("aaaaaaaaaaaa");
  s2 = strdup("bbbbbbbbbbbb");
  printf("Apres: [%s].\n", memmove(s1, s2, 0));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memmove(s2, s1, 0));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  s2 = strdup("azertyuiop");
  s1 = strdup("bbbbbbbbbb");
  printf("Apres: [%s].\n", memmove(s1, s2++, 5));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memmove(s2, s1++, 5));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  FIN;


  DEBUT("MY_MEMMOVE");

  s1 = strdup("aaaaaaaaaaaa");
  s2 = strdup("bbbbbbbbbbbb");
  printf("Apres: [%s].\n", memmove(s1, s2, 4));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memmove(s2, s1, 4));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  s1 = strdup("aaaaaaaaaaaa");
  s2 = strdup("bbbbbbbbbbbb");
  printf("Apres: [%s].\n", memmove(s1, s2, 0));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memmove(s2, s1, 0));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));

  s2 = strdup("azertyuiop");
  s1 = strdup("bbbbbbbbbb");
  printf("Apres: [%s].\n", memmove(s1, s2++, 5));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", memmove(s2, s1++, 5));
  printf("strlen([%s]) = [%d].\n", s2, strlen(s2));
  FIN;


  /*
/////////////////////////////////////////////////////
/////////////////////// RINDEX //////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("RINDEX");
  s1 = strdup("aaaaaaaaaaaa");
  printf("Apres: [%s].\n", rindex(s1, 'a'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  printf("Result => a\n");

  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("bbbbbbvbbbbb");
  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  printf("Result => vbbbbb\n");

  printf("Apres: [%s].\n", rindex(s1, ' '));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", rindex(s1, 3000000000));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("bbbbbbvbvbbb");
  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  printf("Result => vbbb\n");

  s1 = strdup("bbbbbbvvvbbb");
  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  printf("Result => vbbb\n");

  s1 = strdup("");
  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", rindex(s1, 0));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", rindex(s1, -1));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  FIN;

  DEBUT("MY_RINDEX");
  s1 = strdup("aaaaaaaaaaaa");
  printf("Apres: [%s].\n", rindex(s1, 'a'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  printf("Result => a\n");

  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("bbbbbbvbbbbb");
  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  printf("Result => vbbbbb\n");

  printf("Apres: [%s].\n", rindex(s1, ' '));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", rindex(s1, 3000000000));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  s1 = strdup("bbbbbbvbvbbb");
  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  printf("Result => vbbb\n");

  s1 = strdup("bbbbbbvvvbbb");
  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));
  printf("Result => vbbb\n");

  s1 = strdup("");
  printf("Apres: [%s].\n", rindex(s1, 'v'));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", rindex(s1, 0));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  printf("Apres: [%s].\n", rindex(s1, -1));
  printf("strlen([%s]) = [%d].\n", s1, strlen(s1));

  FIN;

  /*
/////////////////////////////////////////////////////
/////////////////////// STRCASECMP /////////////////////
/////////////////////////////////////////////////////
*/

  DEBUT("STRCASECMP");
  s1 = strdup("AzerTyuiOp");
  s2 = strdup("azErtyUiop");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("");
  s2 = strdup("azeRtyRiop");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("aZertYuiop");
  s2 = strdup("");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("");
  s2 = strdup("");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("abCdefizefze");
  s2 = strdup("abcDefRzefze");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("abCdefIzefze");
  s2 = strdup("abcDefRzefze");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("aBcDefIzefze");
  s2 = strdup("abCDefrzefze");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("ABCDEFIzefze");
  s2 = strdup("abcdefrzefze");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  FIN;

  DEBUT("MY_STRCASECMP");
  s1 = strdup("AzerTyuiOp");
  s2 = strdup("azErtyUiop");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("");
  s2 = strdup("azeRtyRiop");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("aZertYuiop");
  s2 = strdup("");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("");
  s2 = strdup("");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("abCdefizefze");
  s2 = strdup("abcDefRzefze");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("abCdefIzefze");
  s2 = strdup("abcDefRzefze");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("aBcDefIzefze");
  s2 = strdup("abCDefrzefze");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));

  s1 = strdup("ABCDEFIzefze");
  s2 = strdup("abcdefrzefze");
  if (strcasecmp(s1, s2) < 0)
    printf("[%s] < [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) > 0)
    printf("[%s] > [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  else if (strcasecmp(s1, s2) == 0)
    printf("[%s] == [%s] = [%d]\n", s1, s2, strcasecmp(s1, s2));
  FIN;

  DEBUT("STRSTR");
  s1 = strdup("azertyuiop");
  s2 = strdup("azertyuiop");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("");
  s2 = strdup("azertyuiop");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("azertyuiop");
  s2 = strdup("");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("");
  s2 = strdup("");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));
  FIN;

  DEBUT("MY_STRSTR");
  s1 = strdup("azertyuiop");
  s2 = strdup("azertyuiop");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("");
  s2 = strdup("azertyuiop");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("azertyuiop");
  s2 = strdup("");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("");
  s2 = strdup("");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));

  s1 = strdup("abcdefizefze");
  s2 = strdup("abcdefrzefze");
  printf("[%s] | [%s] = [%s]\n", s1, s2, strstr(s1, s2));
  FIN;

  DEBUT("strbprkkb");
  printf("%s => ut\n", strpbrk("slaut", "ut"));
  printf("%p => %p\n", strpbrk("slaut", "zb"), strpbrk("slaut", "zb"));
  FIN;

  DEBUT("strcspn");
  printf("%ld = 0\n", strcspn("aaaaaaaaaaa", "za"));
  printf("%ld = 11\n", strcspn("aaaaaaaaaaa", "z"));
  printf("%ld = 0\n", strcspn("zdezdezde", "zd"));
  FIN;
  return (0);
}
