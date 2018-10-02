# f18-hmwk2-team18

## Files modified
/arch/x86/entry/syscalls/syscall_64.tbl <br>
/include/linux/syscalls.h <br>
/kernel/sys.c <br>
/syscall_test/test.c

## syscall ptree
A same struct prinfo is created in the kernel using the number of size user expected. While traversing the process, we extract the data from task_struct and save it in the kernel prinfo struct. Only expected or actual amount of data(depends on which one is smaller) will be saved in the struct. Finally, we use copy_to_user to copy the kernel struct to user struct and free the kernel space. When user is listing the prinfo struct, it is responsible for user to not access the address space outside the prinfo struct he has defined.(We can't get the actual size of struct that user gives to kernel)

## Part 4
### a.
pid_t fields and state can change from time to time. When processes are created or terminated in the system, new parent-child, sibling relationship can be formed. When the processes are running in the system, state also can change. However in our several tests, this kind of change is not frequent when we only run executable test file. For system processes, for the purpose of keeping system stable, their data change rarely.

### b.
They both have similar amount of processes while the processes under init(systemd for VM) are very different from each other. 

### c.
#### i.
zygote process seems to be responsible for any user level processes such as UI, phone, dialer etc. It creates the processes for user application.
After investigating zygote on Internet, it is a warm-up process for any other user applications. It will speed up the the application by not copying the core libraries which will be shared by applications. This process is similar to a VM.
#### ii.

#### iii.
As mentioned before, zygote is designed for embedded system for reducing memory allocation and any other process initialization steps. Since embedded system has limited resource and their applications also require not many resources, sharing memory address will be efficient to boost the system running speed(like creating thread). Fully using the advantage of multi-thread system is necessary for embedded system.


Reference:
1.http://coltf.blogspot.com/p/android-os-processes-and-zygote.html
