
typedef struct Item{
    char data;
    struct Item *next;
} Item;

typedef struct  List{
    Item *head;
    Item *tail;
}List;

List *new_list();

void print_list(const List *list);

void free_list(List *list);

void list_append(List *list, char data);

void list_remove_from(List *list, Item *curr, char data);
