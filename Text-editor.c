#include<stdio.h>            //including header files    //stdio.h used for input or output operations
#include<string.h>                            //used for strcpy function
#include<stdlib.h>                            //used for system("clear") function
#include<termios.h>                            //used for getch function
#include<unistd.h>                            //used for getch function

#include <stdbool.h>
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
 
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 

struct dll                    //definition of the structure double linked list
{
char s[200];                            //character array
int index;
struct dll*prev,*next;            //pointers to next and previous nodes
};
typedef struct oper{
char op;
char sent[200];
struct oper *next;
struct dll *t;
}stack;


int getch()                            //getch function definition
{
struct termios oldt,
newt;
int ch;
tcgetattr( STDIN_FILENO, &oldt );
newt = oldt;
newt.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}