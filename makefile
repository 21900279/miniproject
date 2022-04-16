CC = gcc
CFLAGS = -W -Wall
TARGET = main
DTARGET = main_debug
OBJECTS = main.c manager.o product.o
COBJECTS = main.c manager.c product.c
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(COBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o main
clean_debug:
	rm main_debug
