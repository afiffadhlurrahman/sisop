#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <time.h>

int main() {
 	pid_t child_id;
	int status;
	time_t rawtime;
	struct tm *info;
   	char buffer[80];
	char b[]="/home/afif/sisop/";

   	time( &rawtime );
	info = localtime( &rawtime );

	strftime(buffer,80,"%d-%m-%Y_%I:%M:%S", info);
	strcat(b,buffer);  	
  
	child_id = fork();
  
	if (child_id < 0) {
		exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  	}

	if (child_id == 0) {
    	// this is child
    
    	char *argv[] = {"cp", "-r", "/home/afif/Music",b, NULL};
    	execv("/bin/cp", argv);
  	} else {
    	// this is parent
    	while ((wait(&status)) > 0);
	
    	char *argv[] = {"mkdir", b, NULL};
    	execv("/usr/bin/mkdir", argv);
  	}
}
