/***************************************************************************
 *   Copyright (C) 2008 by Spencer Oliver                                  *
 *   spen@spen-soft.co.uk                                                  *
 *                                                                         *
 *   Copyright (C) 2008 by David T.L. Wong                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef MIPS32_PRACC_H
#define MIPS32_PRACC_H

#include "mips_ejtag.h"

#define MIPS32_PRACC_TEXT			0xFF200200
//#define MIPS32_PRACC_STACK			0xFF2FFFFC
#define MIPS32_PRACC_STACK			0xFF204000
#define MIPS32_PRACC_PARAM_IN		0xFF201000
#define MIPS32_PRACC_PARAM_IN_SIZE	0x1000
#define MIPS32_PRACC_PARAM_OUT		(MIPS32_PRACC_PARAM_IN + MIPS32_PRACC_PARAM_IN_SIZE)
#define MIPS32_PRACC_PARAM_OUT_SIZE	0x1000

#define UPPER16(uint32_t) (uint32_t >> 16)
#define LOWER16(uint32_t) (uint32_t & 0xFFFF)
#define NEG16(v) (((~(v)) + 1) & 0xFFFF)
/*#define NEG18(v) (((~(v)) + 1) & 0x3FFFF)*/

extern int mips32_pracc_read_mem(mips_ejtag_t *ejtag_info, uint32_t addr, int size, int count, void *buf);
extern int mips32_pracc_write_mem(mips_ejtag_t *ejtag_info, uint32_t addr, int size, int count, void *buf);

extern int mips32_pracc_read_mem8(mips_ejtag_t *ejtag_info, uint32_t addr, int count, uint8_t *buf);
extern int mips32_pracc_read_mem16(mips_ejtag_t *ejtag_info, uint32_t addr, int count, uint16_t *buf);
extern int mips32_pracc_read_mem32(mips_ejtag_t *ejtag_info, uint32_t addr, int count, uint32_t *buf);
extern int mips32_pracc_read_u32(mips_ejtag_t *ejtag_info, uint32_t addr, uint32_t *buf);

extern int mips32_pracc_write_mem8(mips_ejtag_t *ejtag_info, uint32_t addr, int count, uint8_t *buf);
extern int mips32_pracc_write_mem16(mips_ejtag_t *ejtag_info, uint32_t addr, int count, uint16_t *buf);
extern int mips32_pracc_write_mem32(mips_ejtag_t *ejtag_info, uint32_t addr, int count, uint32_t *buf);
extern int mips32_pracc_write_u32(mips_ejtag_t *ejtag_info, uint32_t addr, uint32_t *buf);

extern int mips32_pracc_read_regs(mips_ejtag_t *ejtag_info, uint32_t *regs);
extern int mips32_pracc_write_regs(mips_ejtag_t *ejtag_info, uint32_t *regs);

extern int mips32_pracc_exec(mips_ejtag_t *ejtag_info, int code_len, uint32_t *code, int num_param_in, uint32_t *param_in, int num_param_out, uint32_t *param_out, int cycle);

#endif
