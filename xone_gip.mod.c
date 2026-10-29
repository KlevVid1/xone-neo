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

KSYMTAB_FUNC(gip_create_adapter, "");
SYMBOL_FLAGS(gip_create_adapter, 0x01);
KSYMTAB_FUNC(gip_power_off_adapter, "");
SYMBOL_FLAGS(gip_power_off_adapter, 0x01);
KSYMTAB_FUNC(gip_destroy_adapter, "");
SYMBOL_FLAGS(gip_destroy_adapter, 0x01);
KSYMTAB_FUNC(__gip_register_driver, "");
SYMBOL_FLAGS(__gip_register_driver, 0x01);
KSYMTAB_FUNC(gip_unregister_driver, "");
SYMBOL_FLAGS(gip_unregister_driver, 0x01);
KSYMTAB_FUNC(gip_set_power_mode, "");
SYMBOL_FLAGS(gip_set_power_mode, 0x01);
KSYMTAB_FUNC(gip_suggest_audio_format, "");
SYMBOL_FLAGS(gip_suggest_audio_format, 0x01);
KSYMTAB_FUNC(gip_set_audio_volume, "");
SYMBOL_FLAGS(gip_set_audio_volume, 0x01);
KSYMTAB_FUNC(gip_send_rumble, "");
SYMBOL_FLAGS(gip_send_rumble, 0x01);
KSYMTAB_FUNC(gip_set_led_mode, "");
SYMBOL_FLAGS(gip_set_led_mode, 0x01);
KSYMTAB_FUNC(gip_send_get_serial_number, "");
SYMBOL_FLAGS(gip_send_get_serial_number, 0x01);
KSYMTAB_FUNC(gip_send_audio_samples, "");
SYMBOL_FLAGS(gip_send_audio_samples, 0x01);
KSYMTAB_FUNC(gip_has_interface, "");
SYMBOL_FLAGS(gip_has_interface, 0x01);
KSYMTAB_FUNC(gip_enable_audio, "");
SYMBOL_FLAGS(gip_enable_audio, 0x01);
KSYMTAB_FUNC(gip_init_audio_in, "");
SYMBOL_FLAGS(gip_init_audio_in, 0x01);
KSYMTAB_FUNC(gip_init_audio_out, "");
SYMBOL_FLAGS(gip_init_audio_out, 0x01);
KSYMTAB_FUNC(gip_init_extra_data, "");
SYMBOL_FLAGS(gip_init_extra_data, 0x01);
KSYMTAB_FUNC(gip_disable_audio, "");
SYMBOL_FLAGS(gip_disable_audio, 0x01);
KSYMTAB_FUNC(gip_process_buffer, "");
SYMBOL_FLAGS(gip_process_buffer, 0x01);
KSYMTAB_FUNC(gip_auth_send_complete, "");
SYMBOL_FLAGS(gip_auth_send_complete, 0x01);
KSYMTAB_FUNC(gip_auth_process_pkt, "");
SYMBOL_FLAGS(gip_auth_process_pkt, 0x01);
KSYMTAB_FUNC(gip_auth_start_handshake, "");
SYMBOL_FLAGS(gip_auth_start_handshake, 0x01);
KSYMTAB_FUNC(gip_init_battery, "");
SYMBOL_FLAGS(gip_init_battery, 0x01);
KSYMTAB_FUNC(gip_report_battery, "");
SYMBOL_FLAGS(gip_report_battery, 0x01);
KSYMTAB_FUNC(gip_init_led, "");
SYMBOL_FLAGS(gip_init_led, 0x01);
KSYMTAB_FUNC(gip_init_input, "");
SYMBOL_FLAGS(gip_init_input, 0x01);

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "82751613726F32F613C4719");
