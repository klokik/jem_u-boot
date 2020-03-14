/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Amazon Kindle Fire HD 8.9 (LTE) codename Jem
 *
 * Copyright (C) 2019 Nickolas Dolhyi <0xb000@gmail.com>
 */

#ifndef __CONFIG_JEM_H
#define __CONFIG_JEM_H

#define CONFIG_MAX_RAM_BANK_SIZE	(1024 << 21)	/* 2GB */

#include <asm/arch/cpu.h>
#include <asm/arch/omap.h>

/*
 * Build
 */

/*
 * CPU
 */

#define CONFIG_SYS_L2_PL310		1
#define CONFIG_SYS_PL310_BASE		0x48242000

/*
 * Board
 */

/*
 * Clocks
 */

#define CONFIG_SYS_TIMERBASE	GPT2_BASE
#define CONFIG_SYS_PTV		2

/*
 * DRAM
 */

/*
 * Memory
 */

#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_INIT_SP_ADDR		(NON_SECURE_SRAM_END - \
					 GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_MALLOC_LEN		(1024 * 1024 + CONFIG_ENV_SIZE)

/*
 * I2C
 */

#define CONFIG_SYS_I2C
#define CONFIG_I2C_MULTI_BUS

/*
 * Power
 */

#define CONFIG_TWL6030_POWER

/*
 * Input
 */

#define CONFIG_TWL6030_INPUT

/*
 * SPL
 */

#define CONFIG_SPL_MAX_SIZE		(SRAM_SCRATCH_SPACE_ADDR - \
					 CONFIG_SPL_TEXT_BASE)
#define CONFIG_SPL_BSS_START_ADDR	0x80000000
#define CONFIG_SPL_BSS_MAX_SIZE		(512 * 1024)
#define CONFIG_SYS_SPL_MALLOC_START	0x80208000
#define CONFIG_SYS_SPL_MALLOC_SIZE	(1024 * 1024)

/*
 * Console
 */

#define CONFIG_SYS_CBSIZE	512

/*
 * Serial
 */

#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		48000000
#define CONFIG_SYS_NS16550_COM3		UART3_BASE

#define CONFIG_SYS_BAUDRATE_TABLE	{ 4800, 9600, 19200, 38400, 57600, \
					  115200 }

/*
 * USB gadget
 */
// #define CONFIG_USB_DEVICE		1
// #define CONFIG_USB_TTY			1

/*
 * Environment
 */

#define CONFIG_ENV_OVERWRITE

#define CONFIG_EXTRA_ENV_SETTINGS \
  "stdin=serial,vga\0" \
	"stdout=serial,vga\0" \
	"stderr=serial,vga\0" \
	"kernel_addr_r=0x81000000\0" \
	"loadaddr=0x83000000\0" \
	"fdt_addr_r=0x88000000\0" \
	"fdtaddr=0x88000000\0" \
	"ramdisk_addr_r=0x88080000\0" \
	"pxefile_addr_r=0x80100000\0" \
	"scriptaddr=0x80000000\0" \
	"bootm_size=0x10000000\0" \
	"usbtty=cdc_acm\0" \
	"vram=8M\0" \
	"boot_mmc_dev=0\0" \
	"stock_boot_mmc_part=6\0" \
	"recovery_mmc_part=9\0" \
	"console=ttyS2,115200n8\0" \
	"bootargs=console=ttyO2,115200n8\0" \
	"bootpart=0:7\0" \
	"bootdir=boot\0" \
	"fdtfile=omap4-jem.dtb\0" \
	"bootfile=zImage\0" \
	"rdfile=initramfs.uImage\0" \
	"loadfdt=fatload mmc ${bootpart} ${fdtaddr} ${bootdir}/${fdtfile}\0" \
	"loadimage=fatload mmc ${bootpart} ${loadaddr} ${bootdir}/${bootfile}\0" \
	"loadrd=fatload mmc ${bootpart} ${ramdisk_addr_r} ${bootdir}/${rdfile}\0" \
	"optargs=mem=1G fbcon=rotate:0 loglevel=8 no_console_suspend\0" \
	"nfsopts=nolock,nfsvers=3\0" \
	"rootpath=/srv/nfs4/arch_jem\0" \
	"netargs=setenv bootargs console=${console} " \
		"${optargs} " \
		"root=/dev/nfs " \
		"nfsroot=${serverip}:${rootpath},${nfsopts} rw " \
		"brcmfmac.blacklist=yes "\
		"ip=${ipaddr}\0" \
	"netboot=echo Booting from network ...; " \
		"run loadimage; " \
		"run loadfdt; " \
		"run netargs; " \
		"bootz ${loadaddr} - ${fdtaddr}\0" \
	"stockboot=echo Booting uImage from dkernel ...; " \
		"setenv boot_mmc_part ${stock_boot_mmc_part}; " \
		"part start mmc ${boot_mmc_dev} ${boot_mmc_part} boot_mmc_start; " \
		"part size mmc ${boot_mmc_dev} ${boot_mmc_part} boot_mmc_size; " \
		"mmc dev ${boot_mmc_dev}; " \
		"mmc read ${kernel_addr_r} ${boot_mmc_start} ${boot_mmc_size}; " \
		"bootm ${kernel_addr_r};\0" \
	"localboot=echo Booting from eMMC ...; " \
		"run loadimage; " \
		"run loadfdt; " \
		"env set bootargs console=${console} console=tty0 fbcon=rotate:0 loglevel=8 mem=1G no_console_suspend root=179:14 rootfstype=ext4 rootwait rw; " \
		"bootz ${loadaddr} - ${fdtaddr}\0" \
	"localboot_rd=echo Booting from eMMC ...; " \
		"run loadimage; " \
		"run loadfdt; " \
		"run loadrd; " \
		"env set bootargs console=${console} console=tty0 fbcon=rotate:0 root=/dev/mmcblk0p13 rootpath=/media/LinuxRootArch rootwait rw; " \
		"bootz ${loadaddr} ${ramdisk_addr_r} ${fdtaddr}\0" \
	"ipaddr=10.1.10.9\0"\
	"serverip=10.1.10.2\0"\

/*
 * ATAGs
 */

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG
#define CONFIG_SERIAL_TAG

/*
 * BootCONFIG_PRE_CON_BUF_SZ
 */

#define CONFIG_SYS_LOAD_ADDR	0x83000000

#define CONFIG_BOOTCOMMAND \
		"if test ${boot_btn} = 3; then if test ${vbus_on_boot} = 1; then fastboot 0; fi; run stockboot; fi; " \
		"if test ${boot_btn} = 3; then run stockboot; fi; " \
		"if test ${boot_btn} = 2; then run localboot_rd; fi; " \
		"if test ${boot_btn} = 1; then echo Skip to 3rd u-boot, todo..., now fastboot; fastboot 0; fi;"

/*#define CONFIG_BOOTCOMMAND \
	"setenv boot_mmc_part ${kernel_mmc_part}; " \
	"if test reboot-${reboot-mode} = reboot-r; then " \
	"echo recovery; setenv boot_mmc_part ${recovery_mmc_part}; fi; " \
	"if test reboot-${reboot-mode} = reboot-b; then " \
	"echo fastboot; fastboot 0; fi; " \
	"part start mmc ${boot_mmc_dev} ${boot_mmc_part} boot_mmc_start; " \
	"part size mmc ${boot_mmc_dev} ${boot_mmc_part} boot_mmc_size; " \
	"mmc dev ${boot_mmc_dev}; " \
	"mmc read ${kernel_addr_r} ${boot_mmc_start} ${boot_mmc_size} && " \
	"bootm ${kernel_addr_r};"*/

/*
 * Defaults
 */

#include <config_defaults.h>

// #define CONFIG_MENU
#define CONFIG_CMD_BOOTMENU

// #define CONFIG_VIDEO
// #define VIDEO_FB_LITTLE_ENDIAN
#define VIDEO_FB_16BPP_WORD_SWAP
// #define CONFIG_VIDEO_FONT_4X6

#endif
