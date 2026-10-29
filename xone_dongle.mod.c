#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};


MODULE_INFO(depends, "xone_gip,cfg80211");

MODULE_ALIAS("usb:v045Ep02E6d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v045Ep02FEd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v045Ep02F9d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v045Ep091Ed*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "C54B9D62068C44269FBE055");
