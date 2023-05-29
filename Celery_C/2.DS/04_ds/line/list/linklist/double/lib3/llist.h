#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD	1
#define LLIST_BACKWARD	2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *, const void *);

struct llist_node_st
{
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[1];
};

typedef struct llist_head
{
    int size;
    struct llist_node_st head;
    int (*insert)(struct llist_head *, const void *, int);  //为什么要把第一个参数改成struct llist_head *而不是LLIST *呢
    void *(*find)(struct llist_head *, const void *, llist_cmp *);//是因为改名在后面，结构体里看不到
    int (*delete)(struct llist_head *, const void *, llist_cmp *);
    int (*fetch)(struct llist_head *, const void *, llist_cmp *, void *);
    void (*travel)(struct llist_head *, llist_op *);
}LLIST;                                                   

LLIST *llist_create(int initsize);//这个没法放进去，因为在.c当中create是用来赋值的，如果你把create放进去
                                  //那你就在调这个函数之前首先给new里面的create赋值，赋值成create
void llist_destroy(LLIST *);      //这样就变成了，你要想调create得先赋值，要想赋值得先调create
                                  //就绕入了一个鸡生蛋，蛋生鸡的问题
#endif