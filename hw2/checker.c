#include <linux/module.h>
#include <linux/init.h>
#include "checker.h"
MODULE_LICENSE("GPL");

//int GLOBAL_VAR = 10;
//EXPORT_SYMBOL(GLOBAL_VAR);

//extern void call_me(const char* mes);
void call_me(const char* mes);
//{
//	printk(KERN_INFO "~ ~ ~ My string is: %s\n", mes);
//	printk(KERN_INFO "~ ~ ~ My string is: %d\n", mes);
//}
EXPORT_SYMBOL(call_me);

int init_module(void)
{
	printk(KERN_INFO "Hello from checker!\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Module 1 is close!\n");
}
