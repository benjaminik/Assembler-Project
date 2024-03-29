#ifndef PASSES_H
#define PASSES_H

#define LINE_LEN 82

static char *two_oprands[] = {
  "mov",
  "cmp",
  "add",
  "sub",
  "lea"
};
static const int two_oprands_len = 5;

static char *one_oprand[] = {
  "clr",
  "not",
  "inc",
  "dec",
  "jmp",
  "bne",
  "jsr",
  "red",
  "prn"
};
static const int one_oprand_len = 9;

static char *no_oprand[] = {
  "rts",
  "stop"
};
static const int no_oprand_len = 2;

static char *registers[] = {
  "r0",
  "r1",
  "r2",
  "r3",
  "r4",
  "r5",
  "r6",
  "r7"
};
static const int registers_len = 8;

#endif
