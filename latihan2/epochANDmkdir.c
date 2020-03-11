#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    char b[]="/home/afif/sisop/shift2/";
    char c[1000];
    struct tm t;
    time_t t_of_day;
    time_t s, val = 1;
    struct tm* current_time;
    
    s = time(NULL);
    current_time = localtime(&s);
    
    t.tm_year = current_time->tm_year;  // Year - 1900
    t.tm_mon = current_time->tm_mon;           // Month, where 0 = jan
    t.tm_mday = current_time->tm_mday;          // Day of the month
    t.tm_hour = current_time->tm_hour;
    t.tm_min = current_time->tm_min;
    t.tm_sec = current_time->tm_sec;
    t.tm_isdst = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
    t_of_day = mktime(&t);


    printf("%ld\n", (long) t_of_day);
    sprintf( c, "%ld", (long) t_of_day );
    //puts( c );
    strcat(b,c);
    char *binaryPath = "/bin/mkdir";
    char *argv[] = {binaryPath, b, NULL};
	execv(binaryPath, argv);
    
    // char *binaryPath = "/usr/bin/wget";
    // char *argv[] = {binaryPath,"-P",b, "https://picsum.photos/200", NULL};
	// execv(binaryPath, argv);
}
