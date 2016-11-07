
//  main.c
//  slime
//  test
//  [04/11/2016]

#include <stdio.h>
#include "slime.h"
#include "test_view.h"

int main (int argc, char **argv) {
    slimeCreate(320, 240, 1, "buttcrack");
    slimeAddView(test_view_init, test_view_loop, test_view_exit);
    for (;;) slimeRun();
}
