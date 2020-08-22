#ifndef ASSEMBLER_H
#define ASSEMBLER_H

enum symbl_loc { DATA, CODE };
enum symbl_type { ENTRY, EXTERN };
enum bool { FALSE, TRUE };

char *two_oprands[] = {
  "mov",
  "cmp",
  "add",
  "sub",
  "lea"
};
const int two_oprands_len = 5;

char *one_oprand[] = {
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
const int one_oprand_len = 9;

char *no_oprand[] = {
  "rts",
  "stop"
};
const int no_oprand_len = 2;

char *registers[] = {
  "r0",
  "r1",
  "r2",
  "r3",
  "r4",
  "r5",
  "r6",
  "r7"
};
const int registers_len = 8;

struct nlist
{
  struct nlist *next;
  char *name;
  int value;
  unsigned int loc : 1; /* Location: Code (1) or data (0) */
  unsigned int has_type : 1; /* Is there a type? */
  unsigned int type : 1; /* Entry (0) or External (1) */
};

#define HASHSIZE 4

static struct nlist *symbol_table[HASHSIZE];

struct nlist *lookup(char *name);
struct nlist *install(char *name, int value, int loc, int has_type, int type);

struct int24
{
  struct int24 *next;
  unsigned int data : 24;
};

struct int24 *add_word(unsigned char msb, unsigned char mb, unsigned char lsb, int cd);
void change_word(struct int24 *p, unsigned char msb, unsigned char mb, unsigned char lsb, int cd);
struct int24 *find_word_at(unsigned int ic, int cd);

void openfile(FILE *file, char *fname);
int get_line(char *line, int max, FILE *file);
int count_line_words(char *line, int line_limit);
int get_line_words(char *line, int line_limit, char *buffer[]);

int inarray(char *word, char *array[], int array_length);
int instring(char c, char *word, int word_length);
int strsplit(char word[], int len, char splitter, char word1[], char word2[]);
int *stoi(char s[]);

int add_error(int line, char *e);

struct extern_symbols
{
  struct extern_symbols *next;
  char *name;
  int value;
};

struct extern_symbols *add_external(char *name, int value);

struct entpair /* entpair is probably temp, I still don't know how looping
through the symb table would exactly turn out, and if this is useful or not */
{
  int val;
  char *name;
};
typedef struct entpair entpair;



void create_output(char fname[], int anyEntries, int anyExterns);

void create_ent(char fname[], int len);

void create_ext(char fname[], int len);

void create_ob(char fname[], int len);

void checkfile(char f[]);

unsigned char *get_opcode_funct(char *cmd);

#endif
