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


MODULE_INFO(depends, "xone_gip");

MODULE_ALIAS("usb:v045Ep*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v0738p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v0E6Fp*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v0F0Dp*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v1532p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v24C6p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v20D6p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v044Fp*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v10F5p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v2E24p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v3285p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v2DC8p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v2E95p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v3537p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v11C1p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v294Bp*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v2C16p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v0B05p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v413Dp*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v046Dp*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v0079p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v1038p*d*dc*dsc*dp*icFFisc47ipD0in00*");
MODULE_ALIAS("usb:v1B1Cp*d*dc*dsc*dp*icFFisc47ipD0in00*");

MODULE_INFO(srcversion, "20B467702F0317C15410EED");
