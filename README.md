# c_macro_tricks
macro tricks for C/C++

## function substitution 

Sometimes you have a function you cannot edit and you cannot edit the caller either. Such as non-user code in a generated file (e.g. STM32CubeMX generated driver files).
You can substitute a function without touching changing it.
Three ways are used:
- func_sub0.c: original fuction, then substitute function, then a macro
- func_sub1.c: original fuction, then a few macros, and a function prototype. You can still explicitly call the original function and even move the substutute function
- func_sub2.c: original fuction, static constant that can be overridden locally, and a macro. You can switch which function you call by setting a local variable.
- 
## general macros

DEFINE_IS_EMPTY(x) a macro to check if a numerical define is empty. So you can use make a disctinction between 0, 1, and empty defines for conditional compilation. Example:
```
#if defined(USE_FEATURE) && ((USE_FEATURE+0) || DEFINE_IS_EMPTY(USE_FEATURE))
``` 
