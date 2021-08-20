    #include "drivers/frame_buffer.h"
    #include "drivers/serial_port.h"
    #include "drivers/io.h"
    #include "segmentation/segments.h"
    #include "interrupts/interrupts.h"
    #include "interrupts/keyboard.h"
    #include "interrupts/pic.h"
    

    void kmain()
    {

       char arr[] = "Welcome to VGN_OS";
       fb_move_cursor(6*80);
       fb_write(arr, 18);
       serial_write(arr, 18);
       segments_install_gdt();
       interrupts_install_idt();

    }

