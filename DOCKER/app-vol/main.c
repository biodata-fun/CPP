#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <htslib/sam.h>

int main(int argc, char *argv[]){
  samFile *fp_in = hts_open(argv[1],"r"); //open bam file
  printf("Hello, world!\n");
  return 0;
}
