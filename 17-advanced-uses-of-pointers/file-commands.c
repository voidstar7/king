#include <stdio.h>
#include <string.h>

#define NUM_CMDS 9

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);
void execute(char *cmd); 

struct {
	char *cmd_name;
	void (*cmd_pointer)(void);
} file_cmd[] = {
	{ "new", new_cmd },
	{ "open", open_cmd },
	{ "close", close_cmd },
	{ "close all", close_all_cmd },
	{ "save", save_cmd },
	{ "save as", save_as_cmd },
	{ "save all", save_all_cmd },
	{ "print", print_cmd },
	{ "exit", exit_cmd }
};

int main(void) {
	int i;
	char cmd[16];
 	

	printf("Available commands: new, open, close, close all, save, save as, save all, print, exit\n");
	for (;;) {
		printf("Enter command: ");
		fgets(cmd, 16, stdin);
		cmd[strlen(cmd) - 1] = '\0'; // gets rid of \n so strcmp works in execute()
		execute(cmd);
	}
}

void execute(char *cmd) {
	int i;

	for (i = 0; i < NUM_CMDS; i++) {
		if (strcmp(cmd, file_cmd[i].cmd_name) == 0) {
			file_cmd[i].cmd_pointer();
			return;
		}
	}
	printf("Command not found\n");
}

void new_cmd(void) {
    printf("Executing command: new\n");
}

void open_cmd(void) {
    printf("Executing command: open\n");
}

void close_cmd(void) {
    printf("Executing command: close\n");
}

void close_all_cmd(void) {
    printf("Executing command: close all\n");
}

void save_cmd(void) {
    printf("Executing command: save\n");
}

void save_as_cmd(void) {
    printf("Executing command: save as\n");
}

void save_all_cmd(void) {
    printf("Executing command: save all\n");
}

void print_cmd(void) {
    printf("Executing command: print\n");
}

void exit_cmd(void) {
    printf("Executing command: exit\n");
}
