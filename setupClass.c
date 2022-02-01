/* 
Student Name: Connor Sparkman
Student NetID:cps260
Compiler Used: Linux GCC
Program Description: Takes root name or uses default root name to create a root directory and directories inside of this root.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#define MAX 100

void subsubdirectory(char subdir[],int j){ // create subdirectories of subdirectories
char subsubdir[MAX]; // initialize char
int i = 0; // initialize i
chdir(subdir);// change directory to subdirectory
for(i; i < j; i++){ // create subdirectories j number of times
sprintf(subsubdir, "%s%d", subdir, i + 1);
mkdir(subsubdir, S_IRWXU);
}
chdir(".."); // change directory scope to subdirectories of root
}

void subdirectory(char root[]){ // create subdirectories of root
char subdir[MAX]; // initialize char
chdir(root); // change to root directory

strcpy(subdir, "test");// create test variable
mkdir(subdir, S_IRWXU);// create test subdirectory in root
int j = 3; // set number of subdirectories in test directory
subsubdirectory(subdir,j); // create subdirectories of test directory

// repeat for program and exercise
strcpy(subdir, "program");
mkdir(subdir, S_IRWXU);
j = 5;
subsubdirectory(subdir,j);

strcpy(subdir, "exercise");
mkdir(subdir, S_IRWXU);
j = 10;
subsubdirectory(subdir,j);
}

int main(int argc, char *argv[])
{
char root[30]; // initialize char

// If root directory isn't given
if(argc == 1){
strcpy(root, "sysProg"); // root gets default name
}

// If root directory is given
if(argc == 2){
strcpy(root, argv[1]); // root gets user-given name
}

// create root
mkdir(root,S_IRWXU);

// create subdirectories in root
subdirectory(root);

return 0;
}
