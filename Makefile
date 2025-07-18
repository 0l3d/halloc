CC=gcc 
CFLAGS= -g 
LDFLAGS=
SOURCES=test.c halloc.c 
TARGET=test 
OBJECTS=$(SOURCES:.c=.o)

all: $(TARGET) minimize

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)


%.o: %.c
	$(CC) -o $(CFLAGS) -c $< -o $@

minimize:
	strip $(TARGET)

clean:
	rm -rf $(OBJECTS) $(TARGET)
