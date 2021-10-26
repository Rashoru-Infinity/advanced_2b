CC	= gcc
SRCS	= tokenizer.c parser.c expression.c
OBJS	= $(SRCS:.c=.o)
INC	= -I./ -I./lib
LIBPATH	= ./lib
LINK	= -linput
ARCHIVE	= $(LIBPATH)/libinput.a
TARGET	= expression
CFLAGS	= -Wall -Werror -Wextra -g
RM	= rm -f
VALGRIND	= valgrind
VFLAGS	= --leak-check=full
GDB	= gdb

all	:	$(TARGET)

.c.o	:
#	$(CC) $(CFLAGS)  $(INC) -c $< -o $@
	$(CC) $(CFLAGS) -D CALC -D TOKENIZER_TEST $(DEFINE) $(INC) -c $< -o $@

$(ARCHIVE)	:
	$(MAKE) -C $(LIBPATH) all

$(TARGET)	:	$(ARCHIVE) $(OBJS)
	$(CC) $(OBJS) -L$(LIBPATH) $(LINK) -o $(TARGET)

run	:	$(TARGET)
	./$(TARGET)

leak	:	$(TARGET)
	$(VALGRIND) $(VFLAGS) ./$(TARGET)

debug	:	$(TARGET)
	$(GDB) ./$(TARGET)

clean	:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBPATH) clean

fclean	: clean
	$(RM) $(TARGET)
	$(MAKE) -C $(LIBPATH) fclean

re	: fclean all
