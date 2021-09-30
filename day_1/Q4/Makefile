CC	= gcc
SRCS	= list.c
OBJS	= $(SRCS:.c=.o)
TARGET	= list
CFLAGS	= -g -O
RM	= rm -f

all	:	$(TARGET)

.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET)	:	$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

clean	:
	$(RM) $(OBJS)

clean_target	:
	$(RM) $(TARGET)

clean_all	:
	$(RM) $(OBJS) $(TARGET)

run	:	$(TARGET)
	./$(TARGET)
