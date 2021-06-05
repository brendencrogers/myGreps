typedef struct NODE node;
typedef struct SAME same;

struct NODE {
    char line_contents[101];
    int line_num;
    int word_num;
    node * next;
    node * start;
};