
#include <linux/module.h>
MODULE_LICENSE("GPL");

int init_module(void){
	printk( KERN_INFO "HELLO-test!\n");
	return 0;
}

void cleanup_module(void){
	printk( KERN_INFO "BYE-test!\n");
}
