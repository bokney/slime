
//  main.c
//  slime
//  test
//  [04/11/2016]

#include <stdio.h>
#include "slime.h"

int main (int argc, char **argv) {
    slimeCreate(320, 240, 1, "buttcrack");
    for (;;) slimeRun();
}
