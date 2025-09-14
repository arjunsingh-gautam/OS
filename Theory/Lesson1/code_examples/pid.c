/* This program demonstrate how each process has unique PID(process id) which is created by the OS when a program's process instance is created to uniquely identify the process and track it's state */
#include <stdio.h>
#include <unistd.h> // unistd header help us to use system calls like  getpid()
int main()
{
    printf("Hello from the process:%d\n", getpid()); // gitpid(): return the the unique process id of the process
    return 0;
}