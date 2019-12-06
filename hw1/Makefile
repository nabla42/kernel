obj-m += solution.o

KERNEL_VERSION :=$(shell uname -r)
KDIR ?=/lib/modules/$(KERNEL_VERSION)/build
all:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules
clean:
	$(MAKE) -C $(KDIR) M=$(shell pwd) clean
load:
	sudo insmod solution.ko
	sudo dmesg -C
unload:
	sudo rmmod solution.ko
	sudo dmesg -C
