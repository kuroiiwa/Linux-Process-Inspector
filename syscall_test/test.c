#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_ptree 326
#define BUF_SIZE 300

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
	
	buf = (struct prinfo *)malloc(sizeof(struct prinfo) * BUF_SIZE);
	nr = (int *)malloc(sizeof(int));
	*nr = BUF_SIZE;
	long res = syscall(SYS_ptree, buf, nr);
	for (int i = 0; i < *nr; i++)
		printf("%s,%d,%ld,%d,%d,%d,%u\n", buf[i].comm, buf[i].pid, buf[i].state, buf[i].parent_pid, buf[i].first_child_pid, buf[i].next_sibling_pid, buf[i].uid);
	return res;
}
