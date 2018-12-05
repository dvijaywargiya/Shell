shell: \
			Myshell.o \
			handlePipes.o \
			handlePipesandRedirection.o \
			checkBackground.o \
			checkRedirect.o \
			checkPiping.o \
			clok.o \
			redirect.o \
			redirect2.o \
			command_overkill.o \
			command_quit.o \
			command_bg.o \
			command_fg.o \
			command_kjob.o \
			command_jobs.o \
			command_setenv.o \
			command_unsetenv.o \
			command_cd.o \
			command_clear.o \
			command_echo.o \
			command_ls.o \
			command_pinfo.o \
			command_pwd.o \
			details.o \
			exec.o \
			getCommand.o \
			getWd.o \
			makePrompt.o \
			readCommand.o \
			remind.o \
			seprateSemi.o 
	$(CC) -g -o shell $^

clean:
	@rm -f *.o shell

Myshell.o: Header.h Myshell.c
	$(CC) -g -c Myshell.c

handlePipes.o: Header.h src/handlePipes.c
	$(CC) -g -c src/handlePipes.c

handlePipesandRedirection.o: Header.h src/handlePipesandRedirection.c
	$(CC) -g -c src/handlePipesandRedirection.c

checkPiping.o: Header.h src/checkPiping.c
	$(CC) -g -c src/checkPiping.c

checkRedirect.o: Header.h src/checkRedirect.c
	$(CC) -g -c src/checkRedirect.c	

redirect.o: Header.h src/redirect.c 
	$(CC) -g -c src/redirect.c

redirect2.o: Header.h src/redirect2.c 
	$(CC) -g -c src/redirect2.c

checkBackground.o: Header.h src/checkBackground.c
	$(CC) -g -c src/checkBackground.c

clok.o: Header.h src/clok.c
	$(CC) -g -c src/clok.c

command_overkill.o: Header.h src/command_overkill.c
	$(CC) -g -c src/command_overkill.c

command_quit.o: Header.h src/command_quit.c
	$(CC) -g -c src/command_quit.c

command_bg.o: Header.h src/command_bg.c
	$(CC) -g -c src/command_bg.c

command_fg.o: Header.h src/command_fg.c
	$(CC) -g -c src/command_fg.c

command_kjob.o: Header.h src/command_kjob.c
	$(CC) -g -c src/command_kjob.c


command_jobs.o: Header.h src/command_jobs.c
	$(CC) -g -c src/command_jobs.c

command_setenv.o: Header.h src/command_setenv.c
	$(CC) -g -c src/command_setenv.c

command_unsetenv.o: Header.h src/command_unsetenv.c
	$(CC) -g -c src/command_unsetenv.c

command_cd.o: Header.h src/command_cd.c
	$(CC) -g -c src/command_cd.c

command_clear.o: Header.h src/command_clear.c
	$(CC) -g -c src/command_clear.c

command_echo.o: Header.h src/command_echo.c
	$(CC) -g -c src/command_echo.c

command_ls.o: Header.h src/command_ls.c
	$(CC) -g -c src/command_ls.c

command_pinfo.o: Header.h src/command_pinfo.c
	$(CC) -g -c src/command_pinfo.c

command_pwd.o: Header.h src/command_pwd.c
	$(CC) -g -c src/command_pwd.c

details.o: Header.h src/details.c
	$(CC) -g -c src/details.c

exec.o: Header.h src/exec.c
	$(CC) -g -c src/exec.c

getCommand.o: Header.h src/getCommand.c
	$(CC) -g -c src/getCommand.c

getWd.o: Header.h src/getWd.c
	$(CC) -g -c src/getWd.c

makePrompt.o: Header.h src/makePrompt.c
	$(CC) -g -c src/makePrompt.c

readCommand.o: Header.h src/readCommand.c
	$(CC) -g -c src/readCommand.c

remind.o: Header.h src/remind.c
	$(CC) -g -c src/remind.c

seprateSemi.o: Header.h src/seprateSemi.c
	$(CC) -g -c src/seprateSemi.c
