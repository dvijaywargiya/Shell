#ifndef SHELL
#define SHELL

void command_pinfo (char ** arg);
void details (char *arg);
void command_ls (char ** arg);
void command_echo (char ** arg);
void command_clear (char ** arg);
void command_cd (char ** arg);
void command_pwd (char ** arg);
int checkBackground(char ** arg);
void exec(char ** arg);
char * getWd();
void makePrompt(void);
char * readCommand(void);
char ** seprateSemi(char *inp);
char ** getCommand(char *inp);
void remind(char ** arg);
void clok(char ** arg);
void command_setenv (char **arg);
void command_unsetenv (char **arg);
void redirect(char ** arg);
void redirect2(char ** arg);
int checkRedirect(char ** arg);
int checkPiping(char ** arg);
void handlePipes(char ** arg);
void command_jobs(char ** arg, int flag);
void command_kjob(char ** arg);
void command_fg(char ** arg);
void command_bg(char ** arg);
void command_quit(char ** arg);
void command_overkill(char ** arg);
void handlePipesandRedirection(char** arg);

typedef struct jobs{
	int status;
	char str[1024];
	pid_t pid;
	int time;
}output_jobs;

output_jobs oj[1024];

typedef struct pro{
	int index;
	char str[1024];
	int status;
	time_t init;
}proc_names;

proc_names process_names[40000];
char *user;
char original_path[1024];
int globalProcessFlag;
pid_t globalPid;
int flag;
char globalProcessName[1024];
#endif