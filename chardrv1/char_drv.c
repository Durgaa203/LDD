#include<linux/fs.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>
#include<linux/slab.h>

int major;
#define DEVICE_NAME "example_driver"
unsigned char *ptr;

int device_open(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Hello world %s\n", __func__);
	return 0;
}

ssize_t device_read(struct file *pfile, char __user *buff, size_t length, loff_t *offset){
	printk(KERN_ALERT "Hello world %s\n", __func__);
	if(copy_to_user(buff,ptr,length)!=0){
		printk("copying failed \n ");
		return -1;
	}
	else{
		printk("copying from user is success with %s\n",buff);
	}
	kfree(ptr);
	return 0;
}

ssize_t device_write(struct file *pfile, const char __user *buff, size_t length, loff_t *offset){
	printk(KERN_ALERT "Hello world %s\n", __func__);
	ptr=kzalloc(length,GFP_KERNEL);
	if(ptr == NULL){
		printk("memory allocation failed \n");
	}
	else{
		printk("memory allocation sucessfull \n");
		if(copy_from_user(ptr,buff,length) !=0){
			printk("copying failed \n");
			return -1;
		}
		else{
			printk("copying to user is success with %s\n",buff);
		}
	}
	return length;
}

int device_release(struct inode *pnode, struct file *pfile){
	printk(KERN_ALERT "Hello world %s\n", __func__);
	return 0;
}

struct file_operations fops={
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};



static int hi_init(void){
	printk(KERN_ALERT "Hello world %s\n", __func__);
	major=register_chrdev(0,"Example_Device", &fops);
	printk("Major No: %d \n",major);
	return 0;
}

static void hi_exit(void){
	printk(KERN_ALERT "Good bye world from %s\n", __func__);
	unregister_chrdev(major,"Example_Device");
}

module_init(hi_init);
module_exit(hi_exit);

MODULE_AUTHOR("Durga");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Example program.");


