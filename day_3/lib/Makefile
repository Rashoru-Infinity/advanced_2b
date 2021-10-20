CC	= gcc
SRCS	= read_line.c
OBJS	= $(SRCS:.c=.o)
INC	= -I./
TARGET	= libinput.a
CFLAGS	= -Wall -Werror -Wextra -g
RM	= rm -f
AR	= ar
AFLAGS	= -crs

all	:	$(TARGET)

.c.o	:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TARGET)	:	$(OBJS)
	$(AR) $(AFLAGS) $(TARGET) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(TARGET)

re	: fclean all
