difference between const int *ptr =&a, int const *ptr = &a, int *const ptr = &a, const int * const ptr = &a

Each of these pointer declarations in C++ has a different meaning in terms of what is constant—the pointer itself or the value it points to. Let’s break it down:

1. const int *ptr = &a;
Meaning: The value that ptr points to is constant, but the pointer itself can change.
Readable as: "ptr is a pointer to a constant integer"
You CANNOT change *ptr (the value), but you CAN change ptr (the address).

int a = 10, b = 20;
const int *ptr = &a; // Allowed
*ptr = 30;  // ❌ ERROR: Cannot modify the value
ptr = &b;   // ✅ Allowed: Pointer can point to another address


