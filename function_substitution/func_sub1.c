#include <stdio.h>

//can't change this code:
void print_test()
{
    printf ("print_test_original\n");
}

//custom code:
#define EMPTY() // force multiple passes for macro expansion(http://jhnet.co.uk/articles/cpp_magic)
#define print_test() print_test_substitute()
#define print_test_original() print_test EMPTY() ()

void print_test_substitute();

//can't change this code:
int main()
{
   print_test();
   return 0;
}

//custom code:
void print_test_substitute()
{
    printf ("pre original\n");
    print_test_original();
    printf ("post original\n");
}
