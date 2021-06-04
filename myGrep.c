#include "myGrep.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char * argv[]){

    char line[100];
    FILE *f1;

    f1 = fopen(argv[1], "r");

    if (argc == 3){

        if (!f1) {
            printf("Unable to open file: %s\n", argv[1]);
            return 1;
        }

        else {
            printf("%s %s %s\n", argv[0], argv[1], argv[2]);
        }
    }
    
    else {      /* How can I tell what the prblem is? File or arguments? */
        printf("myGrep: improper number of arguments\n");
        printf("Usage: ./a.out <filename> <word>\n");
    }

    int numlines = 0;
    int occurances = 0;
    const char s[] = " ,\n";
    char *token;
    int numchars = 0;
    int charbyline = 0;
    int max = 0;
    char longest[100];
    int wordcount = 0;
    typedef struct NODE node;

    struct NODE {
        char line_contents[100];
        int line_num;
        int word_num;
        node *next;
    };

    typedef struct LINKEDLIST linkedlist;

    struct LINKEDLIST {
        node head;
    };


    while (fgets(line, 100, f1) != NULL) {

            /*printf("%s", line);*/
            charbyline = strlen(line);

            if (charbyline > max) {
                max = charbyline;
                strcpy(longest, line);
            }

            token = strtok(line, s);

            while (token != NULL) {

                node new;

                if (strcmp(token, argv[2]) == 0) {
                    occurances++;
                    new.line_contents = line;
                    new.line_num = numlines + 1;
                    new.word_num = wordcount;
                    temp = (node *)malloc(sizeof(node));
                }

                token = strtok(NULL, s);
                wordcount++;
            }

            wordcount = 0;
            numlines++;
    }

    printf("longest line: %s", longest);
    printf("num chars: %lu\n", strlen(longest));
    printf("num lines: %d\n", numlines);
    printf("total occurances of the word: %d\n", occurances);

    
}