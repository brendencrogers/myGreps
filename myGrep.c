#include "myGrep.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char * argv[]){

    char line[101];
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
    const char s[] = " ,?.\n";
    char *token;
    int numchars = 0;
    int charbyline = 0;
    int max = 0;
    char longest[101];
    int wordcount = 0;
    typedef struct NODE node;
    char current_line[101];

    struct NODE {
        char line_contents[101];
        int line_num;
        int word_num;
        node * next;
    };

    node * temp = NULL;
    node * head = NULL;
    node * tail = NULL;
    head = (node *)malloc(sizeof(node));
    if (head == NULL) {
        printf("Error in allocating the data array");
        return 1;
    }

    temp = head;
    tail = head;


    while (fgets(line, 101, f1) != NULL) {

        /*printf("%s", line);*/

        charbyline = strlen(line);
        strcpy(current_line, line);

        if (charbyline > max) {
            max = charbyline;
            strcpy(longest, current_line);
        }

        token = strtok(line, s);

        while (token != NULL) {

            if (strcmp(token, argv[2]) == 0) {
                if (occurances == 0) {
                    strcpy(temp->line_contents, current_line);
                    temp->line_num = numlines + 1;
                    temp->word_num = wordcount;
                    temp->next = NULL;
                }
                else {
                    temp = (node *)malloc(sizeof(node));
                    strcpy(temp->line_contents, current_line);
                    temp->line_num = numlines + 1;
                    temp->word_num = wordcount;
                    temp->next = NULL;
                    tail->next = temp;
                    tail = temp;
                }

                occurances++;
            }

            token = strtok(NULL, s);
            wordcount++;
        }

        wordcount = 0;
        numlines++;
    }

    printf("longest line: %s", longest);

    if (strlen(longest) < 100) {
        printf("num chars: %lu\n", strlen(longest) - 1);
    }
    else {
        printf("\nnum chars: %lu\n", strlen(longest));
    }

    printf("num lines: %d\n", numlines);
    printf("total occurances of the word: %d\n", occurances);
    
    node * current = head;

    /*
    if (occurances == 1) {
        printf("line %d; word %d; %s\n", current->line_num, current->word_num, current->line_contents);
        return 0;
    }
    */

    while (current != NULL) {
        if (strlen(current->line_contents) < 100) {
            printf("line %d; word %d; %s", current->line_num, current->word_num, current->line_contents);
            if (current->line_num == numlines) {
                printf("\n");
            }
        }
        else {
            printf("line %d; word %d; %s\n", current->line_num, current->word_num, current->line_contents);
        }
        
        current = current->next;
    }
    
}