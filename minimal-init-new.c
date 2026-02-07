#include <unistd.h>
#include <signal.h>
#include <spawn.h>
#include <sys/wait.h>

int main()
{
if(getpid() !=1) return(1);

sigset_t sigset;
sigfillset(&sigset);
sigprocmask(SIG_BLOCK, &sigset, 0);

pid_t pid;
posix_spawn_file_actions_t file_actions;
posix_spawnattr_t attrp;
char *argv[]={"rcS", 0}; char *envp[]={0};

posix_spawn(&pid, "/etc/init.d/rcS", &file_actions, &attrp, argv, envp);
while(wait(0) !=-1);
}
