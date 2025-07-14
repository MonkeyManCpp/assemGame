.macro PPU_SETADDR addr 

    bit PPU_STATUS          ;; read from PPU_STATUS to reset my address latch
    ;; loading hi-byte
    lda #>addr              ;; fetch high byte of the addr (16 bit)
    sta PPU_ADDR            ;; store the hi-byte into PPU_ADDR $2006
    ;; load lo-byte
    lda #<addr              ;; fetch low byte of the addr (16 bit)
    sta PPU_ADDR            ;; store the lo-byte into PPU_ADDR $2006


.endmacro

.macro PPU_SETDATA val
    lda val 
    sta PPU_DATA            ;; sending value to PPU register $2007
.endmacro