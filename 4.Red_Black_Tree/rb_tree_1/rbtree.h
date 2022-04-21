struct rb_node
{
	struct rb_node * rb_parent;
	int rb_color;
#define RB_RED          0
#define RB_BLACK        1
	struct rb_node * rb_right;
	struct rb_node * rb_left;
};

struct rb_root
{
	struct rb_node * rb_node;
};

#define rb_entry(ptr, type, member)                                     \
	((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

void rb_insert_color(struct rb_node *, struct rb_root *);
void rb_erase(struct rb_node *, struct rb_root *);
void rb_link_node(struct rb_node * node, struct rb_node * parent, struct rb_node ** rb_link);

