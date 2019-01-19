#ifndef FILEIO_H
#define FILEIO_H

void printAll (FILE *fp, char *filename);

void addLine (FILE *fp, char *filename);

void searchString (FILE *fp, char *filename);

void deleteLine(FILE *fp, char *filename);

void insertLine(FILE *fp, char *filename);

void strUpper(char *str);

#endif