#include <unistd.h>
#include <signal.h>
#include <spawn.h>
#include <sys/wait.h>

int main()
{
if(getpid() !=1) return(1);

sigset_t block, mask;
sigfillset(&block);
sigprocmask(SIG_BLOCK, &block, &mask);

pid_t pid;
posix_spawn_file_actions_t acts;
posix_spawnattr_t attr;
char *argv[]={"rcS", 0}; char *envp[]={0};

posix_spawnattr_init(&attr);
posix_spawnattr_setsigmask(&attr, &mask);
posix_spawn(&pid, "/etc/init.d/rcS", &acts, &attr, argv, envp);

while(wait(0) !=-1);
}

