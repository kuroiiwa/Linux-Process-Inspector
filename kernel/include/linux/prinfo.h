#ifndef _LINUX_PRINFO_H
#define _LINUX_PRINFO_H

struct printfo {
	pid_t parent_pid;
	pid_t pid;
	pid_t first_child_pid;
	pid_t next_sibling_pid;
	long state;
	uid_t iod;
	char comm[64];
};

#endif
