#include <linux/module.h>
#include <linux/init.h>
#include <linux/random.h>
#include "checker.h"
MODULE_LICENSE("GPL");
extern int array_sum(short *arr, size_t n);
extern ssize_t generate_output(int sum, short *arr, size_t size, char *buf);

int init_module(void)
{
	CHECKER_MACRO;
	int sum, i, calls;
	calls = 13;
	char buf[255];

size_t size;
short arr_value;
	for(i=0; i<calls; i++)
	{
		unsigned int t;
		get_random_bytes(&t, sizeof(int)-1);
		t %= 10;
		size = t+1;

		short arr[size];

		int j, k, proof_sum;
		proof_sum = 0;
		for(j=0; j<size; j++)
		{
			get_random_bytes(&arr_value, sizeof(int)-1);
			arr_value %= 25;
			arr[j] = arr_value;
		//	printk(KERN_INFO "%d", arr[j]);
		}

		sum = array_sum(arr, size);
		for (k=0; k<size; k++)
		{
			proof_sum += arr[k];
		}
		generate_output(sum, arr, size, buf);

		if (sum == proof_sum)
			pr_info("[kernel_mooc]: %s", buf);
		else
			pr_err("[kernel_mooc]: %s", buf);
	}

	return 0;
}

void exit_module(void)
{
	CHECKER_MACRO;
	printk(KERN_INFO "Solution close!\n");
}
module_exit(exit_module);
