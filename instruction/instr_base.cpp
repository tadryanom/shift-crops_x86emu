#include <stdint.h>
#include "instruction/base.hpp"

#define instrbase(f) ((instrfunc_t)&InstrBase::f)

InstrBase::InstrBase() {
	int i;

	set_funcflag(0x00, instrbase(add_rm8_r8), CHK_MODRM);
	set_funcflag(0x02, instrbase(add_r8_rm8), CHK_MODRM);
	set_funcflag(0x04, instrbase(add_al_imm8), CHK_IMM8);
	set_funcflag(0x08, instrbase(or_rm8_r8), CHK_MODRM);
	set_funcflag(0x0a, instrbase(or_r8_rm8), CHK_MODRM);
	set_funcflag(0x0c, instrbase(or_al_imm8), CHK_IMM8);
	set_funcflag(0x20, instrbase(and_rm8_r8), CHK_MODRM);
	set_funcflag(0x22, instrbase(and_r8_rm8), CHK_MODRM);
	set_funcflag(0x24, instrbase(and_al_imm8), CHK_IMM8);
	set_funcflag(0x28, instrbase(sub_rm8_r8), CHK_MODRM);
	set_funcflag(0x2a, instrbase(sub_r8_rm8), CHK_MODRM);
	set_funcflag(0x2c, instrbase(sub_al_imm8), CHK_IMM8);
	set_funcflag(0x30, instrbase(xor_rm8_r8), CHK_MODRM);
	set_funcflag(0x32, instrbase(xor_r8_rm8), CHK_MODRM);
	set_funcflag(0x34, instrbase(xor_al_imm8), CHK_IMM8);
	set_funcflag(0x38, instrbase(cmp_rm8_r8), CHK_MODRM);
	set_funcflag(0x3a, instrbase(cmp_r8_rm8), CHK_MODRM);
	set_funcflag(0x3c, instrbase(cmp_al_imm8), CHK_IMM8);
	set_funcflag(0x70, instrbase(jo_rel8), CHK_IMM8);
	set_funcflag(0x71, instrbase(jno_rel8), CHK_IMM8);
	set_funcflag(0x72, instrbase(jb_rel8), CHK_IMM8);
	set_funcflag(0x73, instrbase(jnb_rel8), CHK_IMM8);
	set_funcflag(0x74, instrbase(jz_rel8), CHK_IMM8);
	set_funcflag(0x75, instrbase(jnz_rel8), CHK_IMM8);
	set_funcflag(0x76, instrbase(jbe_rel8), CHK_IMM8);
	set_funcflag(0x77, instrbase(ja_rel8), CHK_IMM8);
	set_funcflag(0x78, instrbase(js_rel8), CHK_IMM8);
	set_funcflag(0x79, instrbase(jns_rel8), CHK_IMM8);
	set_funcflag(0x7a, instrbase(jp_rel8), CHK_IMM8);
	set_funcflag(0x7b, instrbase(jnp_rel8), CHK_IMM8);
	set_funcflag(0x7c, instrbase(jl_rel8), CHK_IMM8);
	set_funcflag(0x7d, instrbase(jnl_rel8), CHK_IMM8);
	set_funcflag(0x7e, instrbase(jle_rel8), CHK_IMM8);
	set_funcflag(0x7f, instrbase(jnle_rel8), CHK_IMM8);
	set_funcflag(0x84, instrbase(test_rm8_r8), CHK_MODRM);
	set_funcflag(0x86, instrbase(xchg_r8_rm8), CHK_MODRM);
	set_funcflag(0x88, instrbase(mov_rm8_r8), CHK_MODRM);
	set_funcflag(0x8a, instrbase(mov_r8_rm8), CHK_MODRM);
	set_funcflag(0x8e, instrbase(mov_sreg_rm16), CHK_MODRM);
	set_funcflag(0x90, instrbase(nop), 0);
	set_funcflag(0xa8, instrbase(test_al_imm8), CHK_IMM8);
	for (i=0; i<8; i++)	set_funcflag(0xb0+i, instrbase(mov_r8_imm8) ,CHK_IMM8);
	set_funcflag(0xc6, instrbase(mov_rm8_imm8), CHK_MODRM | CHK_IMM8);
	set_funcflag(0xcd, instrbase(int_imm8), CHK_IMM8);
	set_funcflag(0xcf, instrbase(iret), 0);
	set_funcflag(0xe4, instrbase(in_al_imm8), CHK_IMM8);
	set_funcflag(0xe6, instrbase(out_imm8_al), CHK_IMM8);
	set_funcflag(0xeb, instrbase(jmp), CHK_IMM8);
	set_funcflag(0xec, instrbase(in_al_dx), 0);
	set_funcflag(0xee, instrbase(out_dx_al), 0);
	set_funcflag(0xfa, instrbase(cli), 0);
	set_funcflag(0xfb, instrbase(sti), 0);
	set_funcflag(0xf4, instrbase(hlt), 0);

	set_funcflag(0x0f20, instrbase(mov_r32_crn), CHK_MODRM);
	set_funcflag(0x0f22, instrbase(mov_crn_r32), CHK_MODRM);
	set_funcflag(0x0f90, instrbase(seto_rm8), CHK_MODRM);
	set_funcflag(0x0f91, instrbase(setno_rm8), CHK_MODRM);
	set_funcflag(0x0f92, instrbase(setb_rm8), CHK_MODRM);
	set_funcflag(0x0f93, instrbase(setnb_rm8), CHK_MODRM);
	set_funcflag(0x0f94, instrbase(setz_rm8), CHK_MODRM);
	set_funcflag(0x0f95, instrbase(setnz_rm8), CHK_MODRM);
	set_funcflag(0x0f96, instrbase(setbe_rm8), CHK_MODRM);
	set_funcflag(0x0f97, instrbase(seta_rm8), CHK_MODRM);
	set_funcflag(0x0f98, instrbase(sets_rm8), CHK_MODRM);
	set_funcflag(0x0f99, instrbase(setns_rm8), CHK_MODRM);
	set_funcflag(0x0f9a, instrbase(setp_rm8), CHK_MODRM);
	set_funcflag(0x0f9b, instrbase(setnp_rm8), CHK_MODRM);
	set_funcflag(0x0f9c, instrbase(setl_rm8), CHK_MODRM);
	set_funcflag(0x0f9d, instrbase(setnl_rm8), CHK_MODRM);
	set_funcflag(0x0f9e, instrbase(setle_rm8), CHK_MODRM);
	set_funcflag(0x0f9f, instrbase(setnle_rm8), CHK_MODRM);


	set_funcflag(0x80, instrbase(code_80), CHK_MODRM | CHK_IMM8);
	set_funcflag(0x80, instrbase(code_82), CHK_MODRM | CHK_IMM8);
}


void InstrBase::add_rm8_r8(void){
	uint8_t rm8, r8;

	rm8 = get_rm8();
	r8 = get_r8();
	set_rm8(rm8+r8);
	EFLAGS_UPDATE_ADD(rm8, r8);
}

void InstrBase::add_r8_rm8(void){
	uint8_t r8, rm8;

	r8 = get_r8();
	rm8 = get_rm8();
	set_r8(r8+rm8);
	EFLAGS_UPDATE_ADD(r8, rm8);
}

void InstrBase::add_al_imm8(void){
	uint8_t al;

	al = GET_GPREG(AL);
	SET_GPREG(AL, al+IMM8);
	EFLAGS_UPDATE_ADD(al, IMM8);
}

void InstrBase::or_rm8_r8(void){
	uint8_t rm8, r8;

	rm8 = get_rm8();
	r8 = get_r8();
	set_rm8(rm8|r8);
	EFLAGS_UPDATE_OR(rm8, r8);
}

void InstrBase::or_al_imm8(void){
	uint8_t al;

	al = GET_GPREG(AL);
	SET_GPREG(AL, al|IMM8);
	EFLAGS_UPDATE_OR(al, IMM8);
}

void InstrBase::or_r8_rm8(void){
	uint8_t r8, rm8;

	r8 = get_r8();
	rm8 = get_rm8();
	set_r8(r8|rm8);
	EFLAGS_UPDATE_OR(r8, rm8);
}

void InstrBase::and_rm8_r8(void){
	uint8_t rm8, r8;

	rm8 = get_rm8();
	r8 = get_r8();
	set_rm8(rm8&r8);
	EFLAGS_UPDATE_AND(rm8, r8);
}

void InstrBase::and_r8_rm8(void){
	uint8_t r8, rm8;

	r8 = get_r8();
	rm8 = get_rm8();
	set_r8(r8&rm8);
	EFLAGS_UPDATE_AND(r8, rm8);
}

void InstrBase::and_al_imm8(void){
	uint8_t al;

	al = GET_GPREG(AL);
	SET_GPREG(AL, al&IMM8);
	EFLAGS_UPDATE_AND(al, IMM8);
}

void InstrBase::sub_rm8_r8(void){
	uint8_t rm8, r8;

	rm8 = get_rm8();
	r8 = get_r8();
	set_rm8(rm8-r8);
	EFLAGS_UPDATE_SUB(rm8, r8);
}

void InstrBase::sub_r8_rm8(void){
	uint8_t r8, rm8;

	r8 = get_r8();
	rm8 = get_rm8();
	set_r8(r8-rm8);
	EFLAGS_UPDATE_SUB(r8, rm8);
}

void InstrBase::sub_al_imm8(void){
	uint8_t al;

	al = GET_GPREG(AL);
	SET_GPREG(AL, al-IMM8);
	EFLAGS_UPDATE_SUB(al, IMM8);
}

void InstrBase::xor_rm8_r8(void){
	uint8_t rm8, r8;

	rm8 = get_rm8();
	r8 = get_r8();
	set_rm8(rm8^r8);
}

void InstrBase::xor_r8_rm8(void){
	uint8_t r8, rm8;

	r8 = get_r8();
	rm8 = get_rm8();
	set_r8(r8^rm8);
}

void InstrBase::xor_al_imm8(void){
	uint8_t al;

	al = GET_GPREG(AL);
	SET_GPREG(AL, al^IMM8);
}

void InstrBase::cmp_rm8_r8(void){
	uint8_t rm8, r8;

	rm8 = get_rm8();
	r8 = get_r8();
	EFLAGS_UPDATE_SUB(rm8, r8);
}

void InstrBase::cmp_r8_rm8(void){
	uint8_t r8, rm8;

	r8 = get_r8();
	rm8 = get_rm8();
	EFLAGS_UPDATE_SUB(r8, rm8);
}

void InstrBase::cmp_al_imm8(void){
	uint8_t al;

	al = GET_GPREG(AL);
	EFLAGS_UPDATE_SUB(al, IMM8);
}

#define JCC_REL8(cc, is_flag) \
void InstrBase::j ## cc ## _rel8(void){ \
	if(is_flag) \
		UPDATE_EIP(IMM8); \
}

JCC_REL8(o, EFLAGS_OF)
JCC_REL8(no, !EFLAGS_OF)
JCC_REL8(b, EFLAGS_CF)
JCC_REL8(nb, !EFLAGS_CF)
JCC_REL8(z, EFLAGS_ZF)
JCC_REL8(nz, !EFLAGS_ZF)
JCC_REL8(be, EFLAGS_CF || EFLAGS_ZF)
JCC_REL8(a, !(EFLAGS_CF || EFLAGS_ZF))
JCC_REL8(s, EFLAGS_SF)
JCC_REL8(ns, !EFLAGS_SF)
JCC_REL8(p, EFLAGS_PF)
JCC_REL8(np, !EFLAGS_PF)
JCC_REL8(l, EFLAGS_SF != EFLAGS_OF)
JCC_REL8(nl, EFLAGS_SF == EFLAGS_OF)
JCC_REL8(le, EFLAGS_ZF || (EFLAGS_SF != EFLAGS_OF))
JCC_REL8(nle, !EFLAGS_ZF && (EFLAGS_SF == EFLAGS_OF))

void InstrBase::test_rm8_r8(void){
	uint8_t rm8, r8;

	rm8 = get_rm8();
	r8 = get_r8();
	EFLAGS_UPDATE_AND(rm8, r8);
}

void InstrBase::xchg_r8_rm8(void){
	uint8_t r8, rm8;

	r8 = get_r8();
	rm8 = get_rm8();
	set_r8(rm8);
	set_rm8(r8);
}

void InstrBase::mov_rm8_r8(void){
	uint8_t r8;

	r8 = get_r8();
	set_rm8(r8);
}

void InstrBase::mov_r8_rm8(void){
	uint8_t rm8;

	rm8 = get_rm8();
	set_r8(rm8);
}

void InstrBase::mov_sreg_rm16(void){
	uint16_t rm16;

	rm16 = get_rm16();
	set_sreg(rm16);
}

void InstrBase::nop(void){} 		// xchg eax, eax

void InstrBase::test_al_imm8(void){
	uint8_t al;

	al = GET_GPREG(AL);
	EFLAGS_UPDATE_AND(al, IMM8);
}

void InstrBase::mov_r8_imm8(void){
	uint8_t reg;

	reg = OPCODE & ((1<<3)-1);
	SET_GPREG(static_cast<reg8_t>(reg), IMM8);
}

void InstrBase::mov_rm8_imm8(void){
	set_rm8(IMM8);
}

void InstrBase::int_imm8(void){
	EMU->queue_interrupt(IMM8, false);
}

void InstrBase::iret(void){
	EMU->iret();
}

void InstrBase::in_al_imm8(void){
	SET_GPREG(AL, EMU->in_io8((uint8_t)IMM8));
}

void InstrBase::out_imm8_al(void){
	uint8_t al;

	al = GET_GPREG(AL);
	EMU->out_io8((uint8_t)IMM8, al);
}

void InstrBase::jmp(void){
	UPDATE_EIP(IMM8);
}

void InstrBase::in_al_dx(void){
	uint16_t dx;

	dx = GET_GPREG(DX);
	SET_GPREG(AL, EMU->in_io8(dx));
}

void InstrBase::out_dx_al(void){
	uint16_t dx;
	uint8_t al;

	dx = GET_GPREG(DX);
	al = GET_GPREG(AL);
	EMU->out_io8(dx, al);
}

void InstrBase::cli(void){
	EMU->set_interruptable(false);
}

void InstrBase::sti(void){
	EMU->set_interruptable(true);
}

void InstrBase::hlt(void){
	EMU->do_halt(true);
	//EMU->dump_regs();
}

void InstrBase::ltr_rm16(void){
	uint16_t rm16;

	rm16 = get_rm16();
	EMU->set_tr(rm16);
}

void InstrBase::mov_r32_crn(void){
	uint32_t crn;

	crn = get_crn();
	SET_GPREG(static_cast<reg32_t>(RM), crn);	// set_r32
}

void InstrBase::mov_crn_r32(void){
	uint32_t r32;

	r32 = GET_GPREG(static_cast<reg32_t>(RM));	// get_r32
	set_crn(r32);
}

#define SETCC_RM8(cc, is_flag) \
void InstrBase::set ## cc ## _rm8(void){ \
	SET_GPREG(static_cast<reg32_t>(RM), is_flag); \
}

SETCC_RM8(o, EFLAGS_OF)
SETCC_RM8(no, !EFLAGS_OF)
SETCC_RM8(b, EFLAGS_CF)
SETCC_RM8(nb, !EFLAGS_CF)
SETCC_RM8(z, EFLAGS_ZF)
SETCC_RM8(nz, !EFLAGS_ZF)
SETCC_RM8(be, EFLAGS_CF || EFLAGS_ZF)
SETCC_RM8(a, !(EFLAGS_CF || EFLAGS_ZF))
SETCC_RM8(s, EFLAGS_SF)
SETCC_RM8(ns, !EFLAGS_SF)
SETCC_RM8(p, EFLAGS_PF)
SETCC_RM8(np, !EFLAGS_PF)
SETCC_RM8(l, EFLAGS_SF != EFLAGS_OF)
SETCC_RM8(nl, EFLAGS_SF == EFLAGS_OF)
SETCC_RM8(le, EFLAGS_ZF || (EFLAGS_SF != EFLAGS_OF))
SETCC_RM8(nle, !EFLAGS_ZF && (EFLAGS_SF == EFLAGS_OF))

/******************************************************************/

void InstrBase::code_80(void){
	switch(REG){
		case 0:	add_rm8_imm8();		break;
		case 1:	or_rm8_imm8();		break;
		case 2:	adc_rm8_imm8();		break;
		case 3:	sbb_rm8_imm8();		break;
		case 4:	and_rm8_imm8();		break;
		case 5:	sub_rm8_imm8();		break;
		case 6:	xor_rm8_imm8();		break;
		case 7:	cmp_rm8_imm8();		break;
		default:
			ERROR("not implemented: 0x80 /%d\n", REG);
	}
}

void InstrBase::code_82(void){
	code_80();
}

/******************************************************************/

void InstrBase::add_rm8_imm8(void){
	uint8_t rm8;

	rm8 = get_rm8();
	set_rm8(rm8+IMM8);
	EFLAGS_UPDATE_ADD(rm8, IMM8);
}

void InstrBase::or_rm8_imm8(void){
	uint8_t rm8;

	rm8 = get_rm8();
	set_rm8(rm8|IMM8);
	EFLAGS_UPDATE_OR(rm8, IMM8);
}

void InstrBase::adc_rm8_imm8(void){
	uint8_t rm8, cf;

	rm8 = get_rm8();
	cf = EFLAGS_CF;
	set_rm8(rm8+IMM8+cf);
	EFLAGS_UPDATE_ADD(rm8, IMM8+cf);
}

void InstrBase::sbb_rm8_imm8(void){
	uint8_t rm8, cf;

	rm8 = get_rm8();
	cf = EFLAGS_CF;
	set_rm8(rm8-IMM8-cf);
	EFLAGS_UPDATE_SUB(rm8, IMM8+cf);
}

void InstrBase::and_rm8_imm8(void){
	uint8_t rm8;

	rm8 = get_rm8();
	set_rm8(rm8&IMM8);
	EFLAGS_UPDATE_AND(rm8, IMM8);
}

void InstrBase::sub_rm8_imm8(void){
	uint8_t rm8;

	rm8 = get_rm8();
	set_rm8(rm8-IMM8);
	EFLAGS_UPDATE_SUB(rm8, IMM8);
}

void InstrBase::xor_rm8_imm8(void){
	uint8_t rm8;

	rm8 = get_rm8();
	set_rm8(rm8^IMM8);
}

void InstrBase::cmp_rm8_imm8(void){
	uint8_t rm8;

	rm8 = get_rm8();
	EFLAGS_UPDATE_SUB(rm8, IMM8);
}
