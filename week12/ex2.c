//
// Created by Pavel on 07/11/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int append_mode = 0;

void parse_args(int argc, char *argv[]) {
    char c;
    while ((c = getopt(argc, argv, "a")) != -1) {
        if (c == 'a'){
            append_mode = 1
        }
    }
}

int main(int argc, char *argv[]) {
    parse_args(argc, argv);
    char buf[100];
    size_t len;
    char *file_mode;
    int i;
    FILE *files[20];
    int num_files;

    file_mode = (append_mode ? "a" : "w");

    num_files = argc - optind;
    if (num_files > 0) {
        for (i = optind; i < argc; i++) {
            FILE *pFile = fopen(argv[i], file_mode);
            files[i - optind] = pFile;
        }
    }

    FILE *stdin = fopen("dev/stdin", "r");
    while ((len = fread(&buf[0], 1, sizeof(buf), stdin)) > 0) {
        fwrite(&buf[0], 1, len, stdout);
        for (i = 0; i < num_files; i++) {
            fwrite(&buf[0], 1, len, files[i]);
        }
    }


    if (num_files > 0) {
        for (i = 0; i < num_files; i++) {
            fclose(files[i]);
        }
    }

    return 0;
}
