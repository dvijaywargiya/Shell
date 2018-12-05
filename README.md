1) Building and running

	Run "make"
	-> Makefile will be executed and an executable with name "shell" will be created.

	Execute "./shell"

2) Features

- All basic features
- Bonus 1 and 2
- Semi-colon separated commands accepted.
- If you add "Spaces" or "tabs" while writing commands, they will be ignored.
- One header file (Header.h)
- Modularizaton: Each function is defined in a different file in the "src" 	   folder.

3) Bonus 1 has been implemented using sleep() function.
4) Bonus 2 has been implemented with "-t" and "-n" flags.
	 "-t" -> Determines the number of seconds between retrieval.
	 "-n" -> Determines the number of seconds the command is going to run.

Including Shell-2

1) All requirements done.
2) Redirecting and piping handled with edge cases.
3) Implemented Jobs command which shows all background processes of current shell, their state in sorted order.
4) Kjob command to send a signal to a particular jobid.
5) Unset and Set environment variables.
6) fg and bg commands.
7) Overkill command to kill all background processes.
8) Signal handling done using signal function.