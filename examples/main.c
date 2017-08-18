//
// Created by king Yang on 2017/8/18.
//

#include <stdio.h>
#include "../ini.h"

int main() {
    hashtable *t = ini_parser("/Users/kingyang/CLionProjects/cini/examples/kone.ini");
    hashtable_set(t, "network", "demo");
    printf("\n%s\n", (char *) hashtable_get(t, "network"));
    printf("t size is %d\n", t->size);
    hashtable_remove(t, "network");

    hashtable_destroy(t);
    return 0;
}
