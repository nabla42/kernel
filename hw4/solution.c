#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
//#include "checker.h"
MODULE_LICENSE("GPL");
extern size_t get_void_size(void);
extern void submit_void_ptr(void *p);
extern ssize_t get_int_array_size(void);
extern int submit_int_array_ptr(int *p);
extern void submit_struct_ptr(struct device *p);
struct device
{
	int id;
	char name[10];
};

int init_module(void)
{
size_t size_void, size_int_arr;
void *ptr1;
size_void = get_void_size();
ptr1 = kmalloc(size_void, GFP_KERNEL);
submit_void_ptr(ptr1);

int *ptr2;
size_int_arr = get_int_array_size();
ptr2 = (int*)kcalloc(size_int_arr, sizeof(int), GFP_KERNEL);
submit_int_array_ptr(ptr2);

struct device *ptr3;
ptr3 = kmalloc(sizeof(struct device), GFP_KERNEL);
submit_struct_ptr(ptr3);

checker_kfree(ptr1);
checker_kfree(ptr2);
checker_kfree(ptr3);

	return 0;
}

void exit_module(void)
{
}
module_exit(exit_module);
