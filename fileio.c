#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fileio.h"

void printAll (FILE *fp, char *filename) {
    system("clear");
    static char buff[100000];
    int lineNum = 0;

    printf("Printing file: %s\n", filename);

    fp = fopen (filename, "r");
    if (fp != NULL) {
        fflush(stdin);
        while (fgets (buff, sizeof (buff), fp) != NULL) {
            printf ("%d: %s", ++lineNum, buff);
        }
        fclose (fp);
    }
    printf("\n");
}

void addLine (FILE *fp, char *filename) {
    if ((fp = fopen(filename, "a")) == NULL) {
        printf("Couldn't open file %s .\n", filename);
    } else {
            
            char newLine[256];
            printf("Enter the newLine: ");
            fgets(newLine, sizeof(newLine),stdin);
            fprintf(fp, "%s", newLine);
}
    fclose (fp);
}


void searchString (FILE *fp, char *filename){

    char searchString[256];
    int lineNum = 1;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Couldn't open file %s .\n", filename);
    } else {
            char subString[256];
            printf("Enter the substring: ");
            fgets(subString, sizeof(subString),stdin);
            
    while (fgets(searchString, sizeof(searchString), fp) != NULL) {
        if((strstr(searchString, subString)) != NULL){
            strUpper(searchString);
            printf("%d %s\n", lineNum, searchString);
        }
        lineNum++;
    }
    

    }
    fclose(fp);

}

void deleteLine(FILE *fp, char *filename) {

    FILE *tempFile;
    int lineNum = 1;
    int line = 0;
    char str[256];

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Couldn't open file %s .\n", filename);
    } else {
    
        tempFile = fopen("temp.txt", "w");
        printf("Enter the line number to delete: ");
        scanf("%d", &line);
        line++;

        while(!feof(fp)) {

            strcpy(str, "\0");
            fgets(str, sizeof(str), fp);
            if (!feof(fp)) {
                lineNum++;

                if (lineNum != line){
                    fprintf(tempFile, "%s", str);
                }
            }
        }

        fclose(fp);
        fclose(tempFile);
        remove(filename);
        rename("temp.txt", filename);

    }
}

void insertLine(FILE *fp, char *filename) {

    FILE *tempFile;
    int lineNum = 1;
    int line = 0;
    char str[256];
    char insertedLine[256];

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Couldn't open file %s .\n", filename);
    } else {
    
        tempFile = fopen("temp.txt", "w");
        printf("Input new line: ");
        fgets(insertedLine, sizeof(insertedLine), stdin);
        printf("Enter the line number before which you want to insert line : ");
        scanf("%d", &line);
        fgetc(stdin);
        line++;

        while(!feof(fp)) {

            strcpy(str, "\0");
            fgets(str, sizeof(str), fp);
            if (!feof(fp)) {
                lineNum++;

                if (lineNum != line-1){
                    fprintf(tempFile, "%s", str);
                } else {
                    fprintf(tempFile, "%s", insertedLine);
                    lineNum++;
                }
            }
        }

        fclose(fp);
        fclose(tempFile);
        remove(filename);
        rename("temp.txt", filename);

    }
}

void strUpper(char *str)
{
	unsigned char *c = (unsigned char *)str;

	while (*c) {
		*c = toupper((unsigned char)*c);
		c++;
	}

	return;
}