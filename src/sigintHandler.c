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

void sigintHandler(int sig_num) {
	signal(SIGINT,sigintHandler);
	fflush(stdout);
}

// void sigquitHandler(int sig_num){
// 	signal(SIGQUIT,sigquitHandler);
// 	fflush(stdout);
// }