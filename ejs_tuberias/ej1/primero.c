#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
main(){ 
     int id, fd[2]; 
     id = fork(); 
     pipe(fd);     
     switch(id)     {     
          case     0:     
               close(0);     
               dup(fd[0]);     
               close(fd[0]);     
               close(fd[1]);     
               execl("segundo","segundo",0);     
               exit(1);     
          case     -1:     
               exit(1);     
          default:     
               close(1);     
               dup(fd[1]);     
               close(fd[0]);     
               close(fd[1]);     
               execl("segundo","segundo",0);     
               exit(1);     
     };     
     exit(0);     
} 