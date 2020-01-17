#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#define DEVICE_NAME "Char_Driver"
#define CLASS_NAME "Character"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Linux Character Device Driver");
MODULE_VERSION("1.0");

static int majorNumber;
static char message[255] = {0};
static short size_of_message;
static int numberOpens = 0;
static struct class *charClass = NULL;
static struct device *charDevice = NULL;
static int dev_open(struct inode *, struct file *);
static int dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);

static struct file_operation fops =
{
	.open = dev_open,
	.read = dev_read,
	.write =  dev_write,
	.release = dev_relaese;
};

static int __init char_init(void)
{
	printk(KERN_INFO "Character: Initializing the character Device Driver\n");
	majorNumber = register_chardev(0, DEVICE_NAME, &fops);
	
	if (majorNumber < 0) {
		printk(KERN_ALERT "Failed to register the character device driver\n");
		return majorNumber;
	}
	printk(KERN_INFO "Character Device Driver Registerd Successfully with major number %d", majorNumber);
