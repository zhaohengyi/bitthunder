/**
 *	BitThunder Linker Script generation.
 **/

#include "btlinker_config.h"

	.init : {
		KEEP(*(.init))
		KEEP(*(.init.*))
    } > BT_LINKER_INIT_SECTION

	.bt.arch.init : {
	    __bt_arch_init_start = .;
		KEEP(*(.bt.arch.init))
		KEEP(*(.bt.arch.init.*))
		__bt_arch_init_end = .;
	} > BT_LINKER_INIT_SECTION

	.bt.arch.devices : {
	    __bt_arch_devices_start = .;
		KEEP(*(.bt.arch.devices))
		KEEP(*(.bt.arch.devices.*))
		__bt_arch_devices_end = .;
	} > BT_LINKER_INIT_SECTION

	.bt.arch.drivers : {
	    __bt_arch_drivers_start = .;
		KEEP(*(.bt.arch.drivers))
		KEEP(*(.bt.arch.drivers.*))
		__bt_arch_drivers_end = .;
	} > BT_LINKER_INIT_SECTION

	.bt.module.init : {
	    __bt_module_init_start = .;
		KEEP(*(.bt.module.init.*))
		KEEP(*(.bt.module.init))
		__bt_module_init_end = .;
	} > BT_LINKER_INIT_SECTION

	.bt.devfs.entries : {
	    __bt_devfs_entries_start = .;
		KEEP(*(.bt.devfs.entries))
		KEEP(*(.bt.devfs.entries.*))
		__bt_devfs_entries_end = .;
	} > BT_LINKER_INIT_SECTION

	.text : {
	    *(.vectors)
		*(.boot)
		*(.text)
		*(.text.*)
		*(.gnu.linkonce.t.*)
		*(.plt)
		*(.gnu_warning)
   		*(.gcc_execpt_table)
   		*(.glue_7)
   		*(.glue_7t)
   		*(.vfp11_veneer)
   		*(.ARM.extab)
   		*(.gnu.linkonce.armextab.*)
	} > BT_LINKER_INIT_SECTION

	.fini : {
	   KEEP (*(.fini))
	} > BT_LINKER_INIT_SECTION

	.rodata : {
	    __rodata_start = .;
      	*(.rodata)
		*(.rodata.*)
		*(.gnu.linkonce.r.*)
		__rodata_end = .;
    } > BT_LINKER_INIT_SECTION

	.rodata1 : {
   	    __rodata1_start = .;
		*(.rodata1)
		*(.rodata1.*)
		__rodata1_end = .;
	} > BT_LINKER_INIT_SECTION

	.sdata2 : {
		__sdata2_start = .;
		*(.sdata2)
		*(.sdata2.*)
		*(.gnu.linkonce.s2.*)
		__sdata2_end = .;
	} > BT_LINKER_INIT_SECTION

	.sbss2 : {
   	    __sbss2_start = .;
		*(.sbss2)
		*(.sbss2.*)
		*(.gnu.linkonce.sb2.*)
		__sbss2_end = .;
	} > BT_LINKER_INIT_SECTION

.data : {
   __data_start = .;
   *(.data)
   *(.data.*)
   *(.gnu.linkonce.d.*)
   *(.jcr)
   *(.got)
   *(.got.plt)
   __data_end = .;
} > BT_LINKER_INIT_SECTION

.data1 : {
   __data1_start = .;
   *(.data1)
   *(.data1.*)
   __data1_end = .;
} > BT_LINKER_INIT_SECTION

.got : {
   *(.got)
} > BT_LINKER_INIT_SECTION

.ctors : {
   __CTOR_LIST__ = .;
   ___CTORS_LIST___ = .;
   KEEP (*crtbegin.o(.ctors))
   KEEP (*(EXCLUDE_FILE(*crtend.o) .ctors))
   KEEP (*(SORT(.ctors.*)))
   KEEP (*(.ctors))
   __CTOR_END__ = .;
   ___CTORS_END___ = .;
} > BT_LINKER_INIT_SECTION

.dtors : {
   __DTOR_LIST__ = .;
   ___DTORS_LIST___ = .;
   KEEP (*crtbegin.o(.dtors))
   KEEP (*(EXCLUDE_FILE(*crtend.o) .dtors))
   KEEP (*(SORT(.dtors.*)))
   KEEP (*(.dtors))
   __DTOR_END__ = .;
   ___DTORS_END___ = .;
} > BT_LINKER_INIT_SECTION

.fixup : {
   __fixup_start = .;
   *(.fixup)
   __fixup_end = .;
} > BT_LINKER_INIT_SECTION

.eh_frame : {
   *(.eh_frame)
} > BT_LINKER_INIT_SECTION

.eh_framehdr : {
   __eh_framehdr_start = .;
   *(.eh_framehdr)
   __eh_framehdr_end = .;
} > BT_LINKER_INIT_SECTION

.gcc_except_table : {
   *(.gcc_except_table)
} > BT_LINKER_INIT_SECTION

.sdata : {
   __sdata_start = .;
   *(.sdata)
   *(.sdata.*)
   *(.gnu.linkonce.s.*)
   __sdata_end = .;
} > BT_LINKER_INIT_SECTION

.sbss (NOLOAD) : {
   __sbss_start = .;
   *(.sbss)
   *(.sbss.*)
   *(.gnu.linkonce.sb.*)
   __sbss_end = .;
} > BT_LINKER_INIT_SECTION

.tdata : {
   __tdata_start = .;
   *(.tdata)
   *(.tdata.*)
   *(.gnu.linkonce.td.*)
   __tdata_end = .;
} > BT_LINKER_INIT_SECTION

.tbss : {
   __tbss_start = .;
   *(.tbss)
   *(.tbss.*)
   *(.gnu.linkonce.tb.*)
   __tbss_end = .;
} > BT_LINKER_INIT_SECTION

.mmu_tbl : {
   . = ALIGN(0x4000);
  __mmu_tbl_start = .;
   *(.mmu_tbl)
   __mmu_tbl_end = .;
} > BT_LINKER_INIT_SECTION

.bss (NOLOAD) : {
   __bss_start = .;
   *(.bss)
   *(.bss.*)
   *(.gnu.linkonce.b.*)
   *(COMMON)
   __bss_end = .;
} > BT_LINKER_INIT_SECTION

.ARM.exidx : {
   __exidx_start = .;
   *(.ARM.exidx*)
   *(.gnu.linkonce.armexidix.*.*)
   __exidx_end = .;
} > BT_LINKER_INIT_SECTION

.preinit_array : {
   __preinit_array_start = .;
   KEEP (*(SORT(.preinit_array.*)))
   KEEP (*(.preinit_array))
   __preinit_array_end = .;
} > BT_LINKER_INIT_SECTION

.init_array : {
   __init_array_start = .;
   KEEP (*(SORT(.init_array.*)))
   KEEP (*(.init_array))
   __init_array_end = .;
} > BT_LINKER_INIT_SECTION

.fini_array : {
   __fini_array_start = .;
   KEEP (*(SORT(.fini_array.*)))
   KEEP (*(.fini_array))
   __fini_array_end = .;
} > BT_LINKER_INIT_SECTION

.ARM.attributes : {
   __ARM.attributes_start = .;
   *(.ARM.attributes)
   __ARM.attributes_end = .;
} > BT_LINKER_INIT_SECTION

_SDA_BASE_ = __sdata_start + ((__sbss_end - __sdata_start) / 2 );

_SDA2_BASE_ = __sdata2_start + ((__sbss2_end - __sdata2_start) / 2 );

/* Generate Stack and Heap definitions */

.heap (NOLOAD) : {
   . = ALIGN(16);
   _heap = .;
   HeapBase = .;
   _heap_start = .;
   . += _HEAP_SIZE;
   _heap_end = .;
   HeapLimit = .;
} > BT_LINKER_INIT_SECTION

.stack (NOLOAD) : {
   . = ALIGN(16);
   _stack_end = .;
   . += _STACK_SIZE;
   _stack = .;
   __stack = _stack;
   . = ALIGN(16);
   _irq_stack_end = .;
   . += _STACK_SIZE;
   __irq_stack = .;
   _supervisor_stack_end = .;
   . += _SUPERVISOR_STACK_SIZE;
   . = ALIGN(16);
   __supervisor_stack = .;
   _abort_stack_end = .;
   . += _ABORT_STACK_SIZE;
   . = ALIGN(16);
   __abort_stack = .;
} > BT_LINKER_INIT_SECTION
