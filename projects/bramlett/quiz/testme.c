#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function

	char char_array[] = " {}[]()abcdefghijklmnopqrstuvwxyz";
    char random_char = char_array[rand() % (33 + 0 - 0) + 0];

    return random_char;
}

char *inputString()
{
    // TODO: rewrite this function

	static char rand_str[6];

	char char_array[] = "abcdefghijklmnopqrstuvwxyz";

	int i;
	for (i = 0; i < 5; i++)
	{
		rand_str[i] = char_array[rand() % (26 + 0 - 0) + 0];
	}
	//printf("i: %d\n", i);
	rand_str[i+1] = '\0';

    return rand_str;
}


void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;

    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
