#include "drivers/serial_port/serial_port.h"
#include "memory/segmentation/segments.h"
#include "drivers/interrupts/interrupts.h"
#include "multiboot.h"
#include "utils/log.h"
#include "memory/paging/paging.h"


/*void init(){
   segments_install_gdt();
   interrupts_install_idt();
   init_paging();
}

int kmain(unsigned int ebx){
   
   init();

   multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
   multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr; 
   unsigned int address_of_module = modules->mod_start;

   if((mbinfo->mods_count) == 1){
      char str[] = "Your module loaded successfully!!!\n";
      serial_write(str,sizeof(str));
      
      typedef void (*call_module_t)(void);
         call_module_t start_program = (call_module_t) address_of_module;
         start_program();

   }
   else{
      char str[] = "Multiple modules loaded successfully!!!\n";
      serial_write(str,sizeof(str));
   }*/
   
   //new 
   
   /* Function to initialize */
 void init(u32int kernelPhysicalStart, u32int kernelPhysicalEnd) {
  /* Initialize segment descriptor tables */
  init_gdt();

  /* Configure serial port */
  serial_configure(SERIAL_COM1_BASE, Baud_115200);
  
  /* Initialize paging */
  init_paging(kernelPhysicalStart, kernelPhysicalEnd);
  
  /* Initialize idt */
  interrupts_install_idt();
  
}

/* Kernel Main */
 s32int kmain(u32int kernelPhysicalStart, u32int kernelPhysicalEnd) {
	
    	// Initialize all modules
   	init(kernelPhysicalStart, kernelPhysicalEnd);

   return 0;
}

