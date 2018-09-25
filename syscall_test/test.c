#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

#define SYS_ptree 326

struct prinfo {
	pid_t parent_pid;		/* process id of parent */
	pid_t pid;			/* process id */
	pid_t first_child_pid;  	/* pid of youngest child */
	pid_t next_sibling_pid;  	/* pid of older sibling */
	long state;			/* current state of process */
	uid_t uid;			/* user id of process owner */
	char comm[64];			/* name of program executed */
};

int main(int argc, char **argv)
{
	struct prinfo *buf;
	int *nr;
	
	long res = syscall(SYS_ptree, buf, nr);
	return res;
}