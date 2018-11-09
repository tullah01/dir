#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>


int main(int argc, char *argv[] ){
  DIR *directory=NULL;
  struct dirent *enter;
  int size = 0;
  struct stat buffer;
  if (argc > 1){
    directory = opendir(argv[1]);
  }
  while (!directory)  {
      printf("Null Directory \n");
      printf("Enter a directory name: \n");
      scanf("%s", enter);
      directory = opendir(enter);

  }

  printf("Information for directory: \n");
  if (directory){
    while ((enter = readdir(directory))){
      stat(enter->d_name, &buffer);
	if(S_ISREG(buffer.st_mode)){
	  printf("File: %s\n", enter->d_name);
	  size += buffer.st_size;
	}
	 if(S_ISDIR(buffer.st_mode)){
	  printf("DIRECTORY: %s \n", enter->d_name);
	}
    }
    closedir(directory);
  }
  printf("Total Directory Size:%i Bytes \n", size);
  return 0;
}
