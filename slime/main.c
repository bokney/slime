
//  main.c
//  slime
//  test
//  [04/11/2016]

#include <stdio.h>
#include "slime.h"
#include "test_view.h"

int main (int argc, char **argv) {
    slimeCreate(640, 480, 1, "test project");
    slimeAddView(test_view_init, test_view_loop, test_view_exit);
    for (;;) slimeRun();
}
