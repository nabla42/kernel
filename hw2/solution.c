#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
extern void call_me(const char*);

int init_module(void)
{
	call_me("Hello from my module!");

	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Solution close!\n");
}
