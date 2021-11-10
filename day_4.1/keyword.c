/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -tT keyword.key  */
/* Computed positions: -k'1' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 1 "keyword.key"

#include "type.h"
#include <string.h>

#define TOTAL_KEYWORDS 38
#define MIN_WORD_LENGTH 1
#define MAX_WORD_LENGTH 8
#define MIN_HASH_VALUE 1
#define MAX_HASH_VALUE 62
/* maximum key range = 62, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register size_t len)
{
  static unsigned char asso_values[] =
    {
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 27, 63, 63, 63, 50, 45, 63,
      22, 17, 40, 35, 61, 30, 63, 25, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 56, 60,
      20, 55, 10, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 10,  5,
      10,  5,  0, 63, 63,  5, 63, 63, 63, 63,
      63, 63, 63, 63,  0, 63,  0, 63, 63, 15,
      63, 63, 63, 63,  0, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63, 63, 63, 63, 63,
      63, 63, 63, 63, 63, 63
    };
  return len + asso_values[(unsigned char)str[0]];
}

struct OPE *
in_word_set (register const char *str, register size_t len)
{
  static struct OPE wordlist[] =
    {
      {""},
#line 30 "keyword.key"
      {"|", OR},
#line 33 "keyword.key"
      {"||", CONDOR},
#line 17 "keyword.key"
      {"for", FOR},
#line 21 "keyword.key"
      {"true", TRUE},
#line 22 "keyword.key"
      {"false", FALSE},
#line 18 "keyword.key"
      {"return", RETURN},
#line 13 "keyword.key"
      {"if", IF},
#line 11 "keyword.key"
      {"int", INTEGER},
#line 14 "keyword.key"
      {"else", ELSE},
#line 15 "keyword.key"
      {"elsif", ELSIF},
#line 36 "keyword.key"
      {">", GREAT},
#line 38 "keyword.key"
      {">=", GREATOREQ},
#line 20 "keyword.key"
      {"continue", CONTINUE},
      {""},
#line 19 "keyword.key"
      {"break", BREAK},
#line 12 "keyword.key"
      {"double", DOUBLE},
#line 23 "keyword.key"
      {"boolean", BOOLEAN},
#line 44 "keyword.key"
      {")", RRNDBKT},
      {""},
#line 16 "keyword.key"
      {"while", WHILE},
#line 35 "keyword.key"
      {"<", LESS},
#line 37 "keyword.key"
      {"<=", LESSOREQ},
#line 45 "keyword.key"
      {"(", LRNDBKT},
      {""}, {""},
#line 27 "keyword.key"
      {"/", DIV},
#line 42 "keyword.key"
      {"/=", DIVMOV},
#line 34 "keyword.key"
      {"!", NOT},
      {""}, {""},
#line 25 "keyword.key"
      {"-", SUB},
#line 40 "keyword.key"
      {"-=", SUBMOV},
      {""}, {""}, {""},
#line 24 "keyword.key"
      {"+", ADD},
#line 39 "keyword.key"
      {"+=", ADDMOV},
      {""}, {""}, {""},
#line 26 "keyword.key"
      {"*", MUL},
#line 41 "keyword.key"
      {"*=", MULMOV},
      {""}, {""}, {""},
#line 29 "keyword.key"
      {"&", AND},
#line 32 "keyword.key"
      {"&&", CONDAND},
      {""}, {""}, {""},
#line 28 "keyword.key"
      {"%", MOD},
#line 43 "keyword.key"
      {"%=", MODMOV},
      {""}, {""}, {""},
#line 31 "keyword.key"
      {"=", MOV},
#line 48 "keyword.key"
      {":", CLN},
      {""}, {""}, {""},
#line 47 "keyword.key"
      {";", SCLN},
#line 46 "keyword.key"
      {",", COMMA}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
