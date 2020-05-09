// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRINT_SIZE(name, type) (printf("size of %s : %zu bytes \n", name, sizeof(type)))
// Stingification implementation
#define PRINT_SIZE2(type) (printf("size of %s : \t%zu bytes \n", #type, sizeof(type)))

int main() {
  // Please print the sizes of the following types:
  // int, short, long, char, float, double, unsigned int, long long
  // uint8_t, uint16_t, uint32_t, and uint64_t, uint_fast8_t,
  // uint_fast16_t, uintmax_t, intmax_t, __int128, and student

  // Here's how to show the size of one type. See if you can define a macro
  // to avoid copy pasting this code.
  printf("size of %s : %zu bytes \n", "int", sizeof(int));
  // e.g. PRINT_SIZE("int", int);
  //      PRINT_SIZE("short", short);
  PRINT_SIZE2(int);
  PRINT_SIZE2(long);
  PRINT_SIZE2(long long);
  PRINT_SIZE2(intmax_t);
  PRINT_SIZE2(uintmax_t);
  PRINT_SIZE2(int *);
  PRINT_SIZE2(long *);
  PRINT_SIZE2(uintmax_t *);

  // Alternatively, you can use stringification
  // (https://gcc.gnu.org/onlinedocs/cpp/Stringification.html) so that
  // Stringification: 
  //   the single hash
  // you can write
  // e.g. PRINT_SIZE(int);
  //      PRINT_SIZE(short);

  // Composite types have sizes too.
  typedef struct {
    int id;
    int year;
    char gender;
  } student;

  student you;
  you.id = 12345;
  you.year = 4;
  PRINT_SIZE2(student);
  PRINT_SIZE2(student *);

  // Array declaration. Use your macro to print the size of this.
  int x[5];
  PRINT_SIZE2(x);         // ... sizeof(x) / sizeof(x[0]) := number_of_elements_in_x 
  PRINT_SIZE2(x[0]);      //     x is the pointer pointing to x[0], thus *x == x[0], x == &x[0]
  PRINT_SIZE2(&x[0]);     // 
  PRINT_SIZE2(*x);

  // You can just use your macro here instead: PRINT_SIZE("student", you);
  // printf("size of %s : %zu bytes \n", "student", sizeof(you));

  return 0;
}
