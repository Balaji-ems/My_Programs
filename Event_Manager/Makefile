OBJECTS = all_module.o event_manager.o main.o

CC = gcc

CFLAGS = -I.

DEPS = event.h events.h global.h module.h

%.o : %.c %(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Event_Manager : $(OBJECTS)
	$(CC) -o $A $^ $(CFLAGS);
clean:
	rm Event_Manager *.o
