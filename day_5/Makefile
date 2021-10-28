CC	= gcc
LEX	 = flex
YACC	= bison
YFLAGS	= --yacc -dv 
SYNTAX	= token.y
LEX_SRC	= lex.yy.c
YACC_SRC	= y.tab.c
YACC_INC	= y.tab.h
SRC	= $(LEX_SRC) $(YACC_SRC) token.c
LEX_RULE	= token.l
OBJS	= $(SRC:.c=.o)
TARGET	= syntax
RM	= rm -f

all	: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(LEX_SRC): $(YACC_SRC)
	$(LEX) $(LEX_RULE)

$(YACC_SRC):
	$(YACC) $(YFLAGS) $(SYNTAX)

.c.o: $(LEX_SRC) $(YACC_SRC)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(LEX_SRC)
	$(RM) $(YACC_SRC)
	$(RM) $(YACC_INC)

fclean: clean
	$(RM) $(TARGET)

re:	fclean all
