CC	= gcc
SRCS	= exer3.c
OBJS	= $(SRCS:.c=.o)
TARGET	= exer3
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
