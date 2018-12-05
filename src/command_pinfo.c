#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "../Header.h"

void command_pinfo (char ** arg)
{
    int p = 1;
    if(arg[1] != NULL && strcmp(arg[1],"&")==0)
    {
        p=2;
        arg[1] = NULL;
    }
    char *array1=(char*)malloc(sizeof(char)*1000);
    strcpy(array1, "/proc/");
    char *array2=(char*)malloc(sizeof(char)*1000);
    FILE *stat;
    FILE *meme;
    if(arg[p] == NULL) 
        strcat(array1, "self");
    else 
        strcat(array1, arg[p]);
    strcpy(array2, array1);
    strcat(array2, "/stat");
    stat = fopen(array2, "r");
    if(stat == NULL)
    {
        perror("ERROR");
        return;
    }
    int pid;
    char status;
    char name[20];
    fscanf(stat, "%d", &pid);
    fscanf(stat, "%s", name);
    fscanf(stat, " %c", &status);
    printf("pid: %d\n", pid);
    printf("Process Status: %c\n", status);
    //printf("%s\n", name);
    fclose(stat);

    free(array1);
    free(array2);
    array1=(char*)malloc(sizeof(char)*1000);
    strcpy(array1,"/proc/");
    if(arg[p] == NULL) 
        strcat(array1, "self");
    else 
        strcat(array1, arg[p]);
    array2=(char*)malloc(sizeof(char)*1000);
    
    strcpy(array2, array1);
    strcat(array2, "/statm");
    meme = fopen(array2, "r");
    if(meme == NULL)
    {
        perror("ERROR");
        return;
    }
    int memory;
    fscanf(meme, "%d", &memory);
    printf("Memory: %d\n", memory);
    fclose(meme);

    free(array1);
    free(array2);
    array1=(char*)malloc(sizeof(char)*1000);
    strcpy(array1,"/proc/");
    if(arg[p] == NULL) 
        strcat(array1, "self");
    else 
        strcat(array1, arg[p]);
    array2=(char*)malloc(sizeof(char)*1000);

    char actual_path[1000];
    char required_path[1000];
    int i;
    for(i=0;i<100;i++)
        actual_path[i] = ' ';
    strcpy(array2, array1);
    strcat(array2, "/exe");
    readlink(array2, actual_path, sizeof(actual_path));
    int j = 0;
    int len = strlen(original_path);
    while(1)
    {
        if(original_path[j] != actual_path[j])
            break;
        j++;
    }
    if(j == len)
    {
        required_path[0] = '~';
        required_path[1] = '\0';
        strcat(required_path, (const char *)&actual_path[j]);
    }
    else
    {
        strcpy(required_path, actual_path);
        required_path[strlen(actual_path)] = '\0';
    }
    i = 0;
    printf("Executable Path: %s\n", required_path);
}