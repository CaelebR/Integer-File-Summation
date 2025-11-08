
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/* Since the largest number is 4294967295, we need 11 characters (including the 
   null character) to read a number from the file */
#define MAX_NUM_LENGTH 12


/* This function checks the number of input parameters to the program to make 
   sure it is correct. If the number of input parameters is incorrect, it 
   prints out a message on how to properly use the program.
   input parameters:
       int    argc
       char** argv 
    return parameters:
       none
 */
void usage(int argc, char** argv)
{
    if(argc < 4) {
        fprintf(stderr,
                "usage: %s <input file 1> <input file 2> <output file>\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }
}


/* This function takes in the two input file names (stored in argv) and
   determines the number of integers in each file.
   If the two files both have N integers, return N, otherwise return -1.
   If one or both of the files do not exist, it should exit with EXIT_FAILURE.
   input parameters:
       char** argv
   return parameters:
       -1 if the two input files have different number of integers 
       N  if the two input files both have N integers
 */
int get_num_ints(char** argv)
{
  int file1nums = 0;
  int file2nums = 0;
  int num;

  FILE *file1 = fopen(argv[1],"r");

  FILE *file2 = fopen(argv[2],"r");

  if (file1 == NULL || file2 == NULL){
      if (file1 == NULL){
          fprintf(stderr, "failed to open file1");
      }
      if (file2 == NULL){
          fprintf(stderr, "failed to open file2");
      }
      exit(EXIT_FAILURE);
  }

  while (fscanf(file1, "%d", &num) == 1){
      file1nums++;
  }

  while (fscanf(file2, "%d", &num) == 1){
      file2nums++;
  }

"main.c" 252L, 7245B                                                                                  1,1           Top
