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

void makePrompt(void)
{
	user = getenv("USER");
	char *wd = getWd();
	//printf("%s\n", wd);
	printf("<" "\033[1;37;41m" "%s" "\033[m""\033[1;33m" "@UBUNTU:~/%s>""\033[m", user,wd);
	free(wd);
}