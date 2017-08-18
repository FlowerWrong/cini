#include "ini.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum _ini_line_state_ {
    LINE_UNPROCESSED,
    LINE_ERROR, // err
    LINE_EMPTY, // empty line
    LINE_COMMENT, // comment with # or ;
    LINE_SECTION, // section
    LINE_VALUE // value
} ini_line_state;

ini_line_state ini_parser_line(const char *line,
                               char *section,
                               char *key,
                               char *value);

hashtable *ini_parser(const char *file) {
    FILE *stream;
    hashtable *t = hashtable_create();
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if ((stream = fopen(file, "r")) == NULL) {
        perror("fopen");
        return NULL;
    }

    while ((nread = getline(&line, &len, stream)) != -1) {
        printf("Retrieved line of length %zu:\n", nread);
        fwrite(line, (size_t) nread, 1, stdout);
    }

    free(line);

    fclose(stream);
    return t;
}
