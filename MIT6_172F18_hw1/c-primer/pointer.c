// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// char * argv[] is an array of char pointer
int main(int argc, char * argv[]) {  // What is the type of argv?
  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.172";
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc;
  printf("char d = %c\n", d);  // What does this print?   "char d = 6\n"

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid?  
               // ... char * argv[] is an array of pointer, thus argv, as a pointer to argv[0], is a pointer to a pointer

  const char * pcc = c;  // pcc is a pointer to char constant
  char const * pcc2 = c; // ... a pointer to a const char, the same as above

  // For each of the following, why is the assignment:
  *pcc = '7';  // invalid?      ... (invalid) as a pointer to char const, its content can't be modified
  pcc = *pcp;  // valid?        ... (valid) but what it points to can be _re-assigned_
  pcc = argv[0];  // valid?     ... (valid) argv[0] itself is a pointer

  char * const cp = c;  // cp is a const pointer to char
  // For each of the following, why is the assignment:
  cp = *pcp;  // invalid?       ... const pointer cannot be _re-assigned_
  cp = *argv;  // invalid?      ... same as above
  *cp = '!';  // valid?         ... const pointer to a char, thus its content could be modified

  const char * const cpc = c;  // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
  // ... const char * const cpc;
  //     compound types from right to left: const pointer to a char const
  //     thus both what it points to (const pointer) and what the content is (char const) cannot be reassigned/modified.
  cpc = *pcp;  // invalid?
  cpc = argv[0];  // invalid?
  *cpc = '@';  // invalid?

  return 0;
}
