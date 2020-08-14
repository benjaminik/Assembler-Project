#ifndef ASSEMBLER_H
#define ASSEMBLER_H

/*
  External variables
*/
enum symbl_loc { DATA, CODE };
enum symbl_type { ENTRY, EXTERNAL };
enum bool { FALSE, TRUE };

struct nlist
{
  struct nlist *next;
  char *name;
  int value;
  unsigned int loc : 1;
  unsigned int type : 1;
};

struct nlist *lookup(char *s);
struct nlist *install(char *name, int value, int loc, int type);

int add_error(int line, char *e);

int first_pass();

#endif