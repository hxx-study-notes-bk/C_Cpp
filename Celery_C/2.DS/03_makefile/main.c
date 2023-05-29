#include <stdio.h>
#include "tool1.h"
#include "tool2.h"

void tool1_printf(void);
void tool2_printf(void);

int main()
{
    tool1_printf();
    tool2_printf();

    return 0;
}