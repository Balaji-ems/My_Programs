/*
enum Event {
    EVENT_1 = 0,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7
};

char* event[] = {"Event_1","Event_2","Event_3","Event_4","Event_5","Event_6","Event_7"};
*/
#define check_bit(value,posistion) ((value) & 1 << (posistion))
#define set_bit(value,posistion)  (value = value | (1 << posistion))
#define clear_bit(value,posistion) (value = value & (~(1 << posistion)))

