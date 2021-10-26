CC	= gcc
LEX	 = flex
LEX_SRC	= lex.yy.c
SRC	= token.c $(LEX_SRC)
LEX_RULE	= token.l
OBJS	= $(SRC:.c=.o)
TARGET	= lex
RM	= rm -f

all	: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(LEX_SRC):
	$(LEX) $(LEX_RULE)

.c.o: $(LEX_SRC)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(LEX_SRC)

fclean: clean
	$(RM) $(TARGET)

re:	fclean all
