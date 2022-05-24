#include<linux/fs.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

int major;
int device_open (struct inode *pinode, struct file *pfile){
printk(KERN_ALERT "Hello world %s\n", __func__);
return 0;
}

ssize_t device_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset){
printk(KERN_ALERT "Hello world %s\n", __func__);
return 10;
}

ssize_t device_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){
printk(KERN_ALERT "Hello world %s\n", __func__);
return 10;
}

int device_release (struct inode *pnode, struct file *pfile){
printk(KERN_ALERT "Hello world %s\n", __func__);
return 0;
}

struct file_operations fops={
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};



static int hello_init(void){
printk(KERN_ALERT "Hello world %s\n", __func__);
major=register_chrdev(0,"Example_Device", &fops);
printk("Major No: %d \n",major);
return 0;
}

static void hello_exit(void){
printk(KERN_ALERT "Good bye world from %s\n", __func__);
unregister_chrdev(major,"Example_Device");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Durga");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Example program.");


