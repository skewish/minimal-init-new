#include <unistd.h>
#include <signal.h>
#include <spawn.h>
#include <sys/wait.h>

int main()
{
if(getpid() !=1) return(1);

sigset_t set;
sigfillset(&set);
sigprocmask(SIG_BLOCK, &set, 0);

pid_t pid;
posix_spawn_file_actions_t acts;
posix_spawnattr_t attr;
char *argv[]={"rcS", 0}; char *envp[]={0};

posix_spawn(&pid, "/etc/init.d/rcS", &acts, &attr, argv, envp);
while(wait(0) !=-1);
}
