#include "drivers/serial_port/serial_port.h"
#include "memory/segmentation/segments.h"
#include "drivers/interrupts/interrupts.h"
#include "multiboot.h"
#include "utils/log.h"
#include "memory/paging/paging.h"
#include "drivers/interrupts/hardware_interrupt_enabler.h"
#include "memory/heap/kheap.h"
#include "user_mode.h"

/* Function to initialize */
void init(u32int kernelPhysicalEnd) {
  /* Initialize segment descriptor tables */
  init_gdt();

  /* Configure serial port */
  serial_configure(SERIAL_COM1_BASE, Baud_115200);
  
  /* Initialize paging */
  init_paging(kernelPhysicalEnd);
  
  /* Initialize idt */
  interrupts_install_idt();
  
}

/* Kernel Main */
int kmain(u32int kernelPhysicalEnd){
	
    	// Initialize all modules
  	init(kernelPhysicalEnd);
  	
  	disable_hardware_interrupts();
  	
  	// Switch to User mode
   	switch_to_user_mode();
   	
	 
  	return 0;
}

}

/* Kernel Main */
 s32int kmain(u32int kernelPhysicalStart, u32int kernelPhysicalEnd) {
	
    	// Initialize all modules
   	init(kernelPhysicalStart, kernelPhysicalEnd);

   return 0;
}

