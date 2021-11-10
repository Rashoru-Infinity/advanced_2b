CC	= gcc
SRCS	= $(KEY) tokenizer.c main.c
KEY	= keyword.c
KEY_SRC	= keyword.key
OBJS	= $(SRCS:.c=.o)
TARGET	= tokenizer
RM	= rm -f

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(KEY):
	gperf -tT $(KEY_SRC) > $(KEY)

.c.o: $(KEY)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(KEY)

fclean: clean
	$(RM) $(TARGET)

re: clean all
