/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Amazon Kindle Fire HD 8.9 (LTE) codename Jem
 *
 * Copyright (C) 2019 Nickolas Dolhyi <0xb000@gmail.com>
 */

#ifndef _JEM_H_
#define _JEM_H_

#include <asm/arch/mux_omap4.h>

#define JEM_GPIO_USB_ID		52

const struct pad_conf_entry core_padconf_array[] = {
	/* GPMC */
	{ GPMC_AD0,		(IEN  | PTU | M1) }, /* sdmmc2_dat0 */
	{ GPMC_AD1,		(IEN  | PTU | M1) }, /* sdmmc2_dat1 */
	{ GPMC_AD2,		(IEN  | PTU | M1) }, /* sdmmc2_dat2 */
	{ GPMC_AD3,		(IEN  | PTU | M1) }, /* sdmmc2_dat3 */
	{ GPMC_AD4,		(IEN  | PTU | M1) }, /* sdmmc2_dat4 */
	{ GPMC_AD5,		(IEN  | PTU | M1) }, /* sdmmc2_dat5 */
	{ GPMC_AD6,		(IEN  | PTU | M1) }, /* sdmmc2_dat6 */
	{ GPMC_AD7,		(IEN  | PTU | M1) }, /* sdmmc2_dat7 */
	{ GPMC_NOE,		(IEN  | PTU | M1) }, /* sdmmc2_clk */
	{ GPMC_NWE,		(IEN  | PTU | M1) }, /* sdmmc2_cmd */
	/* HDQ */
	{ HDQ_SIO,		(IDIS | DIS | M7) }, /* safe_mode */
	/* I2C1 */
	{ I2C1_SCL,		(IEN  | PTU | M0) }, /* i2c1_scl */
	{ I2C1_SDA,		(IEN  | PTU | M0) }, /* i2c1_sda */
	/* I2C2 */
	{ I2C2_SCL,		(IEN  | PTU | M0) }, /* i2c2_scl */
	{ I2C2_SDA,		(IEN  | PTU | M0) }, /* i2c2_sda */
	/* I2C3 */
	{ I2C3_SCL,		(IEN  | PTU | M0) }, /* i2c3_scl */
	{ I2C3_SDA,		(IEN  | PTU | M0) }, /* i2c3_sda */
	/* I2C4 */
	{ I2C4_SCL,		(IEN  | PTU | M0) }, /* i2c4_scl */
	{ I2C4_SDA,		(IEN  | PTU | M0) }, /* i2c4_sda */
	/* UART3 */
	{ UART3_CTS_RCTX,	(IDIS | DIS | M7) }, /* safe_mode */
	{ UART3_RTS_SD,		(IDIS | DIS | M7) }, /* safe_mode */
	{ UART3_RX_IRRX,	(IEN  | DIS | M0) }, /* uart3_rx_irrx */
	{ UART3_TX_IRTX,	(IDIS | DIS | M0) }, /* uart3_tx_irtx */
	/* USBA0_OTG */
	{ USBA0_OTG_CE,		(IDIS | PTD | M0) }, /* usba0_otg_ce */
	{ USBA0_OTG_DP,		(IEN  | DIS | M0) }, /* usba0_otg_dp */
	{ USBA0_OTG_DM,		(IEN  | DIS | M0) }, /* usba0_otg_dm */
};

#endif
