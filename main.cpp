#include <stdio.h>
#include <string.h>

#define DEFAULT_LEN 8192

int main (int argc, char *argv[]) {
    FILE *file;
    
    // Either select standard input or open the given file.
    
    if (argc < 3) {
        fprintf(stderr, "ERROR: invalid arguments\n");
        return 1;
    }
    
    
    
    if (argc == 3) {
        file = stdin;
    } else {
        file = fopen (argv[argc-1], "rb");
        if (file == NULL) {
            fprintf (stderr, "cannot open file\n");
            return 1;
        }
    }
    
    // Now you're connected to stdin or the file itself, no
    //  difference in handling them (unless you do weird fseek
    //  sort of stuff).

    char temp[DEFAULT_LEN];
    while(fgets(temp, DEFAULT_LEN, file)) {
        if (strlen(temp)>3) {
            if (strcmp(temp+2,argv[1])>=0 && strcmp(temp+2,argv[2])<=0) {
                printf ("%s", temp);
            }
        }
    }
    
    
    // Only close file if you opened it yourself.
    
    if (file!=stdin)
        fclose (file);
    return 0;
}



