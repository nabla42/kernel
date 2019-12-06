//#include <linux/module.h>
//#include <linux/init.h>

//MODULE_LICENSE("GPL");

//int GLOBAL_VAR = 10;
//EXPORT_SYMBOL(GLOBAL_VAR);

void call_me(const char* mes)
{
//	printk(KERN_INFO, mes);
	printk(mes);
}
//extern void call_me(const char*);
