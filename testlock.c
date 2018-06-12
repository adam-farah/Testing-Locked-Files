#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


/* Checks for a lock on a file */
int main (int argc, char* argv[])
{
  char* file = argv[1];
  int fd;
  struct flock lock;

  /* Open a file descriptor to the file */
  fd = open (file, O_WRONLY);

  if(fd == -1){
	  printf("*** No such file or directory\n");
	  close (fd);
	  return 0;
  }

  /* Initialize the flock structure */
  memset (&lock, 0, sizeof(lock));
  lock.l_type = F_WRLCK;

  /* use F_GETLK on the file */
  fcntl (fd, F_GETLK, &lock);


  if(lock.l_type == 1){printf("File is locked by %d\n", lock.l_pid);}
  else{printf("File is not locked\n");} //Reading Lock type to determine if file is locked

  close (fd);
  return 0;
}
