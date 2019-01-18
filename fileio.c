#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fileio.h"

void printAll (FILE *fp, char *filename) {
    //system("clear");
    static char buff[100000];
    int lineNum = 0;

    printf("Printing file: %s\n", filename);

    fp = fopen (filename, "r");
    if (fp != NULL) {
        while (fgets (buff, sizeof (buff), fp) != NULL) {
            printf ("%d: %s", ++lineNum, buff);
        }
        fclose (fp);
    }
    printf("\n");
}

void addLine (FILE *fp, char *filename) {
    // char newLine[256];
    //get_string(buf,3);
    // printf("Enter the line: ");
    // scanf("%s", newLine);

    // fp = fopen (filename, "a");
    if ((fp = fopen(filename, "a")) == NULL) {
        printf("Couldn't open file %s .\n", filename);
    } else {
            char buf[100000];
            char newLine[10000];
            printf("Enter the newLine: ");
            //sscanf(buf, "%s", newLine);
            scanf("%s", newLine);
            get_string(newLine, 100000);
            
            //fprintf(fp, "\n");
            //fprintf(fp, "%s", newLine);
            fputs(newLine, fp);
            

}
fclose (fp);
}


void searchString (FILE *fp, char *filename){

    char searchString[256];
    int lineNum = 1;
    int findResult = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Couldn't open file %s .\n", filename);
    } else {
            char subString[256];
            printf("Enter the substring: ");
            scanf("%s", subString);


    while (fgets(searchString, sizeof(searchString), fp) != NULL) {
        if((strstr(searchString, subString)) != NULL){
            strUpper(searchString);
            printf("%d %s\n", lineNum, searchString);
            findResult++;
        }
        lineNum++;
    }
    fclose(fp);

    }


}

void strUpper(char *str)
{
	unsigned char *p = (unsigned char *)str;

	while (*p) {
		*p = toupper((unsigned char)*p);
		p++;
	}

	return;
}

void get_string(char* buff, size_t size)
{
	fflush(stdin);
    fgets(buff, size, stdin);

	char *pos;
	if ((pos = strchr(buff, '\n')) != NULL)
		*pos = '\0';
}