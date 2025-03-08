# difference between 
# const int *ptr =&a
# int const *ptr = &a
# int *const ptr = &a
# const int * const ptr = &a

Each of these pointer declarations in C++ has a different meaning in terms of what is constant—the pointer itself or the value it points to. Let’s break it down:

## 1. const int *ptr = &a;

- Meaning: The value that ptr points to is constant, but the pointer itself can change.
- Readable as: "ptr is a pointer to a constant integer"
- You CANNOT change *ptr (the value), but you CAN change ptr (the address).
```
int a = 10, b = 20;
const int *ptr = &a; // Allowed
*ptr = 30;  // ❌ ERROR: Cannot modify the value
ptr = &b;   // ✅ Allowed: Pointer can point to another address
```

## 2. int const *ptr = &a;
- Meaning: Same as const int *ptr = &a;, since const before * makes the value constant.
- Readable as: "ptr is a pointer to a constant integer"
- You CANNOT change *ptr (the value), but you CAN change ptr (the address).
```
int a = 10, b = 20;
int const *ptr = &a; // Allowed
*ptr = 30;  // ❌ ERROR: Cannot modify the value
ptr = &b;   // ✅ Allowed: Pointer can point to another address
```

## 4. const int *const ptr = &a;
- Meaning: Both the value and the pointer itself are constant.
- Readable as: "ptr is a constant pointer to a constant integer"
- You CANNOT change *ptr (the value), and you CANNOT change ptr (the address)
```
int a = 10, b = 20;
const int *const ptr = &a; // Allowed
*ptr = 30;  // ❌ ERROR: Cannot modify the value
ptr = &b;   // ❌ ERROR: Cannot change the pointer itself
```

### Summary Table
| Declaration	Value | (*ptr) can be changed? |	Address (ptr) can be changed? |
|-------------------|------------------------|--------------------------------|
| const int *ptr / int const *ptr |	❌ No |	✅ Yes |
| int *const ptr |	✅ Yes |	❌ No |
| const int *const ptr |	❌ No | ❌ No |

