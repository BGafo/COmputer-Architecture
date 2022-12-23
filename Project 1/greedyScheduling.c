#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Selection sort based approach to sorting jobs

int main(int argc, char* argv[]) {

    // First peek at how many jobs and timeslots there are
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    char buf[256];

    // Read the number of jobs to be scheduled
    if (!fscanf(fp, "%s\n", buf)) {
        perror("reading the number of jobs failed");
        exit(EXIT_FAILURE);
    }
    int jobcount = atoi(buf);

    // Next read the maximum number of timeslots
    if (!fscanf(fp, "%s\n", buf)) {
        perror("reading the number of timeslots failed");
        exit(EXIT_FAILURE);
    }
    int timeslots = atoi(buf);

    // We've read the number of timeslots so close the file and start over
    fclose(fp);
    
  
    for (unsigned int slot=0; slot<timeslots; slot++) {

        FILE* fp = fopen(argv[1], "r");
        if (!fp) {
            perror("fopen failed");
            exit(EXIT_FAILURE);
        }

        char buf[256];

        // First read the number of jobs to be scheduled
        if (!fscanf(fp, "%s\n", buf)) {
            perror("reading the number of jobs failed");
            exit(EXIT_FAILURE);
        }

        // Next read the maximum number of timeslots
        if (!fscanf(fp, "%s\n", buf)) {
            perror("reading the number of timeslots failed");
            exit(EXIT_FAILURE);
        }

        char job;
        unsigned int start;
        unsigned int end;
        unsigned int prev;
        char temp_job;
        unsigned int temp_start;
        // Now read the rest of the file
        for ( int line=0; line<jobcount; line++ ) {

            if (!fgets(buf, 256, fp)) {
                perror("reading a line for a job failed");
                exit(EXIT_FAILURE);
            }

            if (!sscanf(buf, "%c %d %d", &job, &start, &end)) {
                perror("parsing a line for a job failed");
                exit(EXIT_FAILURE);
            }

            if( start==0 && end==slot && line!=jobcount-1){
                    continue;
            }
            if( line==jobcount-1 && slot==prev && slot!=0 && start==0 && end==slot){
                    printf("%c\n", temp_job);
                    continue;
            } 
            

            if ( end==slot && start > prev ) {
                temp_job = job;
                temp_start = start;
                prev = end;
            }

            if(end==slot && start==temp_start && prev==end){
                temp_job = job;
                temp_start = start;
                prev = end;
            }
            
            if(prev==end && start < temp_start && end==slot && start!=prev && start!=0){
                temp_job = job;
                temp_start = start;
                prev = end;
            }
            
            if( line==jobcount-1 && slot==prev && slot!=0){
                    printf("%c\n", temp_job);
                }  
        }
        fclose(fp);
    }
    
    exit(EXIT_SUCCESS);
}
