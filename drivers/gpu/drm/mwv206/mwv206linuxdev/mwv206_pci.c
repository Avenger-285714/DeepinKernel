/*
 * JM7200 GPU driver
 *
 * Copyright (c) 2018 ChangSha JingJiaMicro Electronics Co., Ltd.
 *
 * Author:
 *      rfshen <jjwgpu@jingjiamicro.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/pci.h>
#include <linux/mod_devicetable.h>
#include <linux/fs.h>
#include <linux/idr.h>
#include <linux/syscalls.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/backlight.h>
#include <linux/version.h>
#include <asm/uaccess.h>
#include "../include/glj.h"
#include "mwv206.h"
#include "../include/mwv206_internal.h"
#include "../include/mwv206config.h"
#include "../include/mwv206reg.h"
#include "mwv206hal/mwv206dev.h"
#include "mwv206hal/mwv206dec.h"
#include <linux/delay.h>

#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/jiffies.h>
#include <linux/pci.h>

#define MAC206LXDEV023

struct device *audio_dev;
#define MAC206LXDEV001 10

static int FUNC206LXDEV060(struct inode *inode, struct file *filp);
static int FUNC206LXDEV078(struct inode *inode, struct file *filp);
static long FUNC206LXDEV055(struct file *filp, unsigned int cmd, unsigned long arg);
static ssize_t FUNC206LXDEV077(struct file *filp, char __user *buff, size_t count, loff_t *offp);
static ssize_t FUNC206LXDEV083(struct file *filp, const char __user *buff, size_t count, loff_t *offp);


static int FUNC206LXDEV093;
static int FUNC206LXDEV056;
static struct class *mwv206_class;
static void *FUNC206LXDEV050[256] = {0};
static DEFINE_SPINLOCK(idr_lock);
static struct pci_device_id mwv206_idlist[] = {
	{0x0731, 0x7200, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};


static const struct vm_operations_struct mmap_ops;

static int FUNC206LXDEV057(struct file *filp, struct vm_area_struct *vma)
{
	V206DEV025 *dev;
	size_t size = vma->vm_end - vma->vm_start;
	unsigned long base_3d;

	dev = filp->private_data;
	base_3d = (unsigned long)MWV206_GET_PCI_BAR_STARTADDR(dev->V206DEV103, dev->V206DEV044[1]);

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	vma->vm_ops = &mmap_ops;
	if (remap_pfn_range(vma, vma->vm_start, base_3d >> PAGE_SHIFT, size, vma->vm_page_prot)) {
		return -EAGAIN;
	}
	return 0;
}

static unsigned int FUNC206LXDEV075(struct file *filp, struct poll_table_struct *wait)
{
	return POLLIN | POLLRDNORM;

}

static struct file_operations mwv206_fops = {
	.owner              = THIS_MODULE,
	.open               = FUNC206LXDEV060,
	.release            = FUNC206LXDEV078,
	.read               = FUNC206LXDEV077,
	.write              = FUNC206LXDEV083,
	.unlocked_ioctl     = FUNC206LXDEV055,
	.compat_ioctl       = FUNC206LXDEV055,
	.mmap               = FUNC206LXDEV057,
	.poll               = FUNC206LXDEV075,
};

int FUNC206LXDEV137(void)
{
	static int flag = 0x00000001;
	return (int)(*(unsigned char *)&flag);
}

static int FUNC206LXDEV045(void *dev)
{
	unsigned long flags;
	int i;
	int ret = -1;

	spin_lock_irqsave(&idr_lock, flags);
	for (i = 0; i < 256; i++) {
		if (FUNC206LXDEV050[i] == NULL) {
			FUNC206LXDEV050[i] = dev;
			ret = i;
			break;
		}
	}
	spin_unlock_irqrestore(&idr_lock, flags);

	return ret;
}

static void *FUNC206LXDEV048(int index)
{
	unsigned long flags;
	void *ret;

	spin_lock_irqsave(&idr_lock, flags);
	ret = FUNC206LXDEV050[index];
	spin_unlock_irqrestore(&idr_lock, flags);

	return ret;
}

static void FUNC206LXDEV047(int index)
{
	unsigned long flags;

	spin_lock_irqsave(&idr_lock, flags);
	FUNC206LXDEV050[index] = NULL;
	spin_unlock_irqrestore(&idr_lock, flags);
}

static struct device_type mwv206_sysfs_device_minor = {
	.name = "mwv206_minor"
};

static int FUNC206LXDEV046(struct pci_dev *V206DEV103)
{
	int id;
	int ret;
	V206DEV025 *priv;
	dev_t devno;

	priv = kzalloc(sizeof(V206DEV025), GFP_KERNEL);
	if (priv == NULL) {
		error("%s - kmalloc failed!\n", __func__);
		return -1;
	}

	ret = pci_enable_device(V206DEV103);
	if (ret) {
		error("###ERR: Can't enable  Device, ret = %d.\n", ret);
		goto err_pci_enable;
	}

	priv->V206DEV103 = V206DEV103;
	pci_set_drvdata(V206DEV103, priv);
	sema_init(&priv->V206DEV100, 1);
	priv->V206DEV101 = FUNC206HAL092();

	if (!priv->V206DEV101) {
		goto err_create_lock;
	}

	ret = FUNC206HAL148(priv);
	if (ret != 0) {
		goto err_gpu_init;
	}

	id = FUNC206LXDEV045(priv);
	priv->V206DEV099 = id;

	devno = MKDEV(FUNC206LXDEV056, id);
	if (!event_dev) {
		event_dev = device_create(mwv206_class, NULL, devno, priv, "mwv206_%d", id);
		if (IS_ERR(event_dev)) {
			goto err_gpu_init;
		}
		event_dev->type =  &mwv206_sysfs_device_minor;
	} else {
		event_dev = device_create(mwv206_class, NULL, devno, priv, "mwv206_%d", id);
		if (IS_ERR(event_dev)) {
			goto err_gpu_init;
		}
	}
	if (audio_dev == NULL) {
		devno = MKDEV(FUNC206LXDEV056, MAC206LXDEV001);
		audio_dev = device_create(mwv206_class, NULL, devno, priv, "mwv206_audio");
		if (IS_ERR(audio_dev)) {
			goto err_create_device;
		}
		priv->V206DEV142 = FUNC206LXDEV118();
		if (!priv->V206DEV142) {
			goto err_create_device;
		}
	}

	priv->V206DEV150 = FUNC206LXDEV118();
	FUNC206LXDEV052(priv);
	FUNC206LXDEV144(V206DEV103);

	mwv206fb_register(V206DEV103);
	FUNC206LXDEV158(V206DEV103);
	FUNC206LXDEV093 = 1;
	return 0;

err_create_device:
	device_destroy(mwv206_class, devno);
err_gpu_init:
	FUNC206HAL093(priv->V206DEV101);
err_create_lock:
	pci_disable_device(V206DEV103);
err_pci_enable:
	kfree(priv);
	priv = NULL;
	return ret;
}

static int FUNC206LXDEV049(struct pci_dev *V206DEV103)
{
	V206DEV025 *priv;
	dev_t devno;

	V206KDEBUG002("[INFO] mwv206_dev_remove.\n\n");


	priv = pci_get_drvdata(V206DEV103);

	FUNC206LXDEV076(V206DEV103);
	FUNC206LXDEV085(V206DEV103);
	FUNC206LXDEV053();
	if (!priv) {
		return 0;
	}

	FUNC206HAL149(priv);
	devno = MKDEV(FUNC206LXDEV056, priv->V206DEV099);
	device_destroy(mwv206_class, devno);
	devno = MKDEV(FUNC206LXDEV056, MAC206LXDEV001);
	device_destroy(mwv206_class, devno);
	FUNC206LXDEV047(priv->V206DEV099);
	FUNC206LXDEV038();
	if (priv->V206DEV142) {
		FUNC206LXDEV119(priv->V206DEV142);
	}
	if (priv->V206DEV150) {
		FUNC206LXDEV119(priv->V206DEV150);
	}
	if (priv->V206DEV101) {
		FUNC206HAL093(priv->V206DEV101);
	}
	kfree(priv);

	return 0;
}

#ifdef MAC206LXDEV023
int FUNC206LXDEV170(void)
{
	return 0;
}

void FUNC206LXDEV096(struct pci_dev *V206DEV103)
{
	typedef void (*FUNCPTR)(struct pci_dev *);
	FUNCPTR func;
	func = (void *)kallsyms_lookup_name("vga_set_default_device");
	if (func == NULL) {
		printk("Not found symbol: vga_set_default_device\n");
	} else {
		func(V206DEV103);
	}
}

static int FUNC206LXDEV064(struct pci_dev *V206DEV103, const struct pci_device_id *id)
{
	debug("Probe mwv206@%d.%d.%d\n", V206DEV103->bus->number, PCI_SLOT(V206DEV103->devfn), PCI_FUNC(V206DEV103->devfn));
	device_disable_async_suspend(&V206DEV103->dev);
	mwv206fb_init_early(V206DEV103);
	FUNC206LXDEV096(V206DEV103);
	return FUNC206LXDEV046(V206DEV103);
}

static void FUNC206LXDEV065(struct pci_dev *V206DEV103)
{
	debug("Remove mwv206@%d.%d.%d\n", V206DEV103->bus->number, PCI_SLOT(V206DEV103->devfn), PCI_FUNC(V206DEV103->devfn));
	FUNC206LXDEV049(V206DEV103);
}

struct pci_dev *FUNC206LXDEV159 (struct device *dev)
{
	struct pci_dev *V206DEV103;
	void *__mptr = (void *)(dev);

	V206DEV103 = ((struct pci_dev *)(__mptr - __builtin_offsetof(struct pci_dev, dev)));
	return V206DEV103;
}


static int FUNC206LXDEV072(struct device *dev)
{
	int ret;
	struct pci_dev *V206DEV103;
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);

	V206DEV103 = FUNC206LXDEV159(dev);
	ret = FUNC206LXDEV167(V206DEV103, true, true);
	return ret;
}

static int FUNC206LXDEV067(struct device *dev)
{
	struct pci_dev *V206DEV103;
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);

	V206DEV103 = FUNC206LXDEV159(dev);
	FUNC206LXDEV166(V206DEV103, true, true);
	return 0;
}

/*
static int FUNC206LXDEV061(struct device *dev)
{
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);
	return 0;
}
*/

static int FUNC206LXDEV074(struct device *dev)
{
	struct pci_dev *V206DEV103;
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);

	V206DEV103 = FUNC206LXDEV159(dev);
	FUNC206LXDEV166(V206DEV103, false, true);
	return 0;
}

static int FUNC206LXDEV063(struct device *dev)
{
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);
	return 0;
}

/*
static int FUNC206LXDEV066(struct device *dev)
{
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);
	return 0;
}
*/

static int FUNC206LXDEV070(struct device *dev)
{
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);
	return 0;
}

static int FUNC206LXDEV069(struct device *dev)
{
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);
	return 0;
}

static int FUNC206LXDEV062(struct device *dev)
{
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);
	return 0;
}

/*
static int FUNC206LXDEV073(struct device *dev)
{
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);
	return 0;
}

static int FUNC206LXDEV068(struct device *dev)
{
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);
	return 0;
}

static void FUNC206LXDEV071(struct pci_dev *dev)
{
	V206DEV025 *pDev;
	V206DEV005("\n\n\n[%s]\n\n", __FUNCTION__);

	pDev = pci_get_drvdata(dev);
	if (NULL == pDev) {
		return ;
	}
	FUNC206LXDEV164(pDev);
	FUNC206HAL006(pDev);

	return ;
}
*/

static const struct dev_pm_ops mwv206_pm_ops = {
	.suspend = FUNC206LXDEV072,
	.resume = FUNC206LXDEV067,
	.freeze = FUNC206LXDEV072,
	.thaw = FUNC206LXDEV074,
	.poweroff = FUNC206LXDEV063,
	.restore = FUNC206LXDEV067,
	.runtime_suspend = FUNC206LXDEV070,
	.runtime_resume = FUNC206LXDEV069,
	.runtime_idle = FUNC206LXDEV062,
};

static struct pci_driver mwv206_pci_driver = {
	.name = MWV206_NAME,
	.id_table = mwv206_idlist,
	.probe = FUNC206LXDEV064,
	.remove = FUNC206LXDEV065,
	.driver.pm = &mwv206_pm_ops,



};
#endif

static int FUNC206LXDEV060(struct inode *inode, struct file *filp)
{
	V206DEV025 *priv;
	int ret = -ENODEV;
	int id;
	id = iminor(inode);
	priv = FUNC206LXDEV048(id);

	filp->private_data = priv;
	if (priv) {
		ret = 0;
		debug("mwv206_open - filp: 0x%p, 0x%p\n", filp, priv);
	} else {
		ret = -ENODEV;
		error("mwv206_open failure: dev is not found.\n");
	}
	while (!FUNC206LXDEV093) {
		FUNC206LXDEV128(FUNC206LXDEV098() / 2);
	}
	return ret;
}

static int FUNC206LXDEV078(struct inode *inode, struct file *filp)
{
	V206DEV025 *pDev;

	if (filp == NULL) {
		return 0;
	}

	pDev = filp->private_data;
	debug("mwv206_close - filp: 0x%p, 0x%p\n", filp, pDev);


	mwv206dec_release(inode, filp, pDev->V206DEV138, pDev);

	FUNC206HAL369(pDev, 1);
	FUNC206HAL263(pDev, filp);
	FUNC206HAL369(pDev, 0);


	FUNC206HAL418.FUNC206HAL202(pDev->V206DEV068[0], filp);
	FUNC206HAL418.FUNC206HAL202(pDev->V206DEV068[1], filp);
	FUNC206HAL418.FUNC206HAL202(pDev->V206DEV068[2], filp);

#ifndef NDEBUG
	debug("memory control 0:\n");
	FUNC206HAL418.FUNC206HAL212(pDev->V206DEV068[0]);
	debug("memory control 1:\n");
	FUNC206HAL418.FUNC206HAL212(pDev->V206DEV068[1]);
	debug("memory control 2:\n");
	FUNC206HAL418.FUNC206HAL212(pDev->V206DEV068[2]);
#endif



	return 0;
}

#define MAC206LXDEV012  1000
static long FUNC206LXDEV055(struct file *filp, unsigned int cmd, unsigned long arg)
{
	V206DEV025 *dev;
	int ret = -ENOTTY;
	int size;
	unsigned char param[MAC206LXDEV012];
	int err = 0;
	dev = filp->private_data;

	if ((_IOC_TYPE(cmd) != MWV206_IOC_MAGIC) && (_IOC_TYPE(cmd) != V206DEV008)) {
		return -ENOTTY;
	}

	if (_IOC_NR(cmd) > V206IOCTL108) {
		return -ENOTTY;
	}

	size = _IOC_SIZE(cmd);

	if (size > MAC206LXDEV012) {
		error("size(%d) should be smaller than %d.\n\n\n", size, MAC206LXDEV012);
		return -EFAULT;
	}

	if (_IOC_DIR(cmd) & _IOC_READ) {
		err = !access_ok((void __user *)arg, size);
	}
	if (_IOC_DIR(cmd) & _IOC_WRITE) {
		err |= !access_ok((void __user *)arg, size);
	}

	if (err) {
		return -EFAULT;
	}


	if (_IOC_TYPE(cmd) == MWV206_IOC_MAGIC) {
		if (size > 0) {
			ret = copy_from_user(param, (char __user *)arg, size);
			if (ret != 0) {
				error("###ERR[cmd = 0x%x]: copy_from_user error [%d].\n", cmd, ret);
				goto ERROR;
			}
		}
		if (size > 0) {
			ret = FUNC206HAL222(dev, cmd, (unsigned long)&param[0], filp);
		} else {
			ret = FUNC206HAL222(dev, cmd, arg, filp);
		}
		if (ret == 0) {
			if ((size > 0) && (_IOC_DIR(cmd) & _IOC_READ)) {
				ret = copy_to_user((char __user *)arg, &param[0], size);
				if (ret != 0) {
					error("###ERR[cmd = 0x%x]: copy_to_user error [%d].\n", cmd, ret);
					goto ERROR;
				}
			}
		}
	}  else {
		V206DEV005("!!!!mwv206 decoder ioctl.\n");
		ret = mwv206dec_ioctl(filp, cmd, arg, dev->V206DEV138, dev);
	}
ERROR:
	return ret;

}

static ssize_t FUNC206LXDEV077(struct file *filp, char __user *buff, size_t count, loff_t *offp)
{
	return 0;
}

static ssize_t FUNC206LXDEV083(struct file *filp, const char __user *buff, size_t count, loff_t *offp)
{
	V206DEV025 *dev;
	int ret = 0;
	int islocked = 0;

	dev = filp->private_data;
	ret = down_interruptible(&dev->V206DEV100);
	if (ret != 0) {
		error("###ERR: down_interruptible error[%d].\n", ret);
		goto ERROR;
	}

	islocked = 1;

	if (count > 0x40000 * 4) {
		count = 0x40000 * 4;
	}

	ret = copy_from_user(dev->V206DEV089, (void __user *)buff, (unsigned long)count);
	if (ret != 0) {
		error("###ERRERR: copy_from_user error[%d].\n", ret);
		goto ERROR;
	}
	ret = FUNC206HAL242(dev, (char *)dev->V206DEV089, count);

ERROR:
	if (islocked) {
		up(&dev->V206DEV100);
	}

	return ret;
}

static int __init FUNC206LXDEV054(void)
{
#ifndef MAC206LXDEV023
	struct pci_dev *V206DEV103 = NULL;
	const struct pci_device_id *pid;
	int i;
#endif

	mwv206_class = class_create("mwv206_0");
	FUNC206LXDEV056 = register_chrdev(0, MWV206_NAME, &mwv206_fops);
	if (FUNC206LXDEV056 < 0) {
		error("%s - register_chrdev failed!\n", __func__);
		return -1;
	}
	debug("mwv206 major = %d\n", FUNC206LXDEV056);

#ifdef MAC206LXDEV023
	if (pci_register_driver(&mwv206_pci_driver)) {
		error("%s - pci_register_driver failed!\n", __func__);
		unregister_chrdev(FUNC206LXDEV056, MWV206_NAME);
		return -1;
	}
#else
	for (i = 0; i < sizeof(mwv206_idlist) / sizeof(mwv206_idlist[0]); i++) {
		pid = &mwv206_idlist[i];
		V206DEV103 = NULL;
		if (pid->vendor != 0) {
			V206DEV103 = pci_get_subsys(
					pid->vendor, pid->device,
					pid->subvendor, pid->subdevice, V206DEV103);
			if (V206DEV103 != NULL) {
				FUNC206LXDEV046(V206DEV103);
				debug("Found mwv206@%d.%d.%d\n", V206DEV103->bus->number, PCI_SLOT(V206DEV103->devfn), PCI_FUNC(V206DEV103->devfn));
			}
		}
	}
#endif

	debug("jiffies = %lu.\n\n\n", jiffies);
	debug("HZ = %u.\n\n\n", HZ);
	debug("mwv206 init finished.\n");
	return 0;
}

static void __exit FUNC206LXDEV153(void)
{
	int i;
	FUNC206LXDEV024();
#ifdef MAC206LXDEV023
	pci_unregister_driver(&mwv206_pci_driver);
#endif
	for (i = 0; i < FUNC206HAL065; i++) {
		if (FUNC206HAL068[i] != 0) {
			iounmap((void *)FUNC206HAL068[i]);
		}
		if (FUNC206HAL067[i][1] != 0) {
			iounmap((void *)FUNC206HAL067[i][1]);
		}
	}
	unregister_chrdev(FUNC206LXDEV056, MWV206_NAME);
	class_destroy(mwv206_class);
	FUNC206HAL361();
	debug("mwv206 exit.\n");
}

int FUNC206LXDEV155(int bus, int dev, int func)
{
	V206DEV025 *priv;
	int i;
	int b, d, f;

	V206DEV005("mwv206_index_get - %d, %d, %d\n", bus, dev, func);
	for (i = 0; i < 256; i++) {
		priv = FUNC206LXDEV048(i);
		if (priv) {
			b = priv->V206DEV103->bus->number;
			d = PCI_SLOT(priv->V206DEV103->devfn);
			f = PCI_FUNC(priv->V206DEV103->devfn);
			if (bus == b && dev == d && func == f) {
				V206DEV005("mwv206_index_get return %d\n", i);
				return i;
			}
		}
	}

	return -1;
}

module_init(FUNC206LXDEV054);
module_exit(FUNC206LXDEV153);
MODULE_DEVICE_TABLE(pci, mwv206_idlist);
MODULE_AUTHOR("rfshen <jjwgpu@jingjiamicro.com>");
MODULE_DESCRIPTION("JM7200 GPU driver");
MODULE_LICENSE("GPL v2");