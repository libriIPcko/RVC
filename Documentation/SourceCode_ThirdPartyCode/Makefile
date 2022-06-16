LDFLAGS=-lftdi
OBJS=main.o debug.o driver.o

TARGET=can_mon

CC=gcc
CFLAGS=-D__GNU__ -O2 -Wall -g

all: $(TARGET)


%.asm.o:  %.s $(AINCLUDES)
	$(AS) $(ASFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@



%.o: %.S
	$(CC) $(CFLAGS) -c  $< -o $@

clean:
	rm -f *.o $(TARGET)
