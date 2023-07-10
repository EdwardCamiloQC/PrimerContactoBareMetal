ENTRY(ResetHandler)

_estack = ORIGIN(ram) + LENGTH(ram);

MEMORY{
    ram(xrw)    :ORIGIN = 0x1FFFF000, LENGTH = 16k
    flash(xr)   :ORIGIN = 0x00000000, LENGTH = 128k
}

SECTIONS{
    .isrVector : {
        . = ALIGN(4);
        KEEP(*(.isrVector))
        . = ALIGN(4);
    } > flash

    .text : {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
        _etext = .;
    } > flash

    .rodata : {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } > flash

    _sidata = LOADADDR(.data);

    .data : {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > ram AT > flash

    . = ALIGN(4);

    .bss : {
        _sbss = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;
    } > ram
}