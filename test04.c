 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 
 int main(){
     char *filename = "b.txt";
 
     if(access(filename, F_OK) == -1 ){
         fprintf(stderr,"User cannot find file %s\n",filename);
         exit(1);
     }
     printf("%s findable procseding\n",filename);
 
 }

