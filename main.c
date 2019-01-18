#include <stdio.h>

#include "fileio.h"

int main () {
    FILE *fp;
    char filename[80];
    int choice = 0;
    char *subString;

    while(choice != 6) {
        printf("Choose option:\n");
 		printf("1 - Print file.\n");
 		printf("2 - Add line to file.\n");
		printf("3 - Search and print lines.\n");
		printf("4 - Overwrite file by deleting choosen line .\n");
		printf("5 - Overwrite file by inserting line.\n");
		printf("6 - Quit.\n");
        scanf("%d", &choice);

   
    switch(choice) {

        case 1:
            printf("Enter the file name: ");
            scanf("%s", filename);
    
            printAll(fp, filename);

            break;

        case 2:
            printf("Enter the file name: ");
            scanf("%s", filename);
    
            addLine(fp, filename);
            break;
        case 3:
            printf("Enter the file name: ");
            scanf("%s", &filename);

            // printf("Enter the line: ");
            // scanf("%s", subString);
    
            searchString(fp, filename);
            break;

        case 6:
            printf("Shutting down\n");
            break;
		default:
			printf("Invalid option. Try again.\n\n");
			break;

    }

    }



}