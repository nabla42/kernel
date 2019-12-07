obj-m += solution.o
#obj-m += checker.o

KERNEL_VERSION :=$(shell uname -r)
export KDIR =/lib/modules/$(KERNEL_VERSION)/build

all:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules
modules_install:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules_install	
clean:
	$(MAKE) -C $(KDIR) M=$(shell pwd) clean
load:
	sudo insmod checker.ko
	sudo insmod solution.ko
	sudo rmmod solution
	sudo rmmod checker
	sudo dmesg -c
