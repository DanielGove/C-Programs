#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char ** argv){
    int exitStatus;

    // at least, there should be 3 arguments
    // 2 for the first command, and the rest for the second command
    if (argc < 4){
        fprintf(stderr, "Usage: %s cmd1 cmd1_arg cmd2 [cmd2_args ..]\n", argv[0]);
        return 1;
    }

    //TODO
    pid_t f = fork();
    if (f == -1) {
        perror("fork()"); 
        return 1;
    } else if (f == 0) {
        execlp(argv[1], argv[1], argv[2], NULL);
        perror("execlp()");  
        return 1;
    }
    waitpid(f, &exitStatus, 0);
    printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));

    pid_t f2 = fork();
    if (f2 == -1)  {
        perror("fork()"); 
        return 1;
    }
    else if (f2 == 0) {
        execvp(argv[3], &argv[3]); 
        perror("execvp()"); 
        return 1;
    }

    waitpid(f2, &exitStatus, 0);
    printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
    return 0;
}