# c_macro_tricks
Macro tricks for C/C++.

## function substitution 

Sometimes you have a function you cannot edit and you cannot edit the caller either. Such as non-user code in a generated file (e.g. STM32CubeMX generated driver files).
You can substitute a function without touching changing it.
Three ways are used:
- func_sub0.c: original function, then substitute function, then a macro
- func_sub1.c: original function, then a few macros, and a function prototype. You can still explicitly call the original function and even move the substitute function to a different file
- func_sub2.c: original function, static constant that can be overridden locally, and a macro. You can switch which function you call by setting a local variable.

## general macros

`DEFINE_IS_EMPTY(x)` a macro to check if a numerical define is empty. So you can use make a distinction between 0, 1, and empty defines for conditional compilation. Example:
```
#if defined(USE_FEATURE) && ((USE_FEATURE+0) || DEFINE_IS_EMPTY(USE_FEATURE))
``` 

`N_ONES(n)` is a bitmask of n 1's.

## date time macros
- `DATE_TO_YEAR(__DATE__)`  -> int year
- `DATE_TO_MONTH(__DATE__)` -> int month (1-12, plus 13 for month "???")
- `DATE_TO_DAY(__DATE__)`   -> int day of month (1-31)
- `TIME_TO_HOUR(__TIME__)`  -> int hour (0-23)
- `TIME_TO_MIN(__TIME__)`   -> int min (0-59)
- `TIME_TO_SEC(__TIME__)`   -> int sec (0-59)
