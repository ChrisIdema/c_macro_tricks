#include <stdio.h>

//can't change this code:
void print_test()
{
    printf ("print_test_original\n");
}

//custom code:

void print_test_substitute()
{
    printf ("pre original\n");
    print_test();
    printf ("post original\n");
}

//a macro after the function body is simpler
#define print_test() print_test_substitute()

//can't change this code:
int main()
{
   print_test();
   return 0;
}
