// check if a numerical define is empty
#define DEFINE_IS_EMPTY(x) ((2*x+1)==2)

// bit mask of 1-64 1's
#define N_ONES(n) (((1ULL << ((n) - 1)) - 1) | 1ULL << ((n) - 1))
