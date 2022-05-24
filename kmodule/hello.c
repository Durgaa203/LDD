#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

static int hello_init(void)
{
printk(KERN_ALERT "hai team\n");
return 0;
}

static void hello_exit(void)
{
printk(KERN_ALERT "What are you doing\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("KAVYA");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world module");

