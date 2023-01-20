#include <stdio.h>

//can't change this code:
void print_test()
{
    printf ("print_test_original\n");
}

//custom code:
//a macro before the function body is more complex
const bool skip = false;
#define print_test() do{if(skip){print_test();}else{print_test_substitute();}}while(0)

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
    const bool skip = true;
    print_test();
    printf ("post original\n");
}
