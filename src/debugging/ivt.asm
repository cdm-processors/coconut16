asect 0x0000
panic_handler: ext
debug_loader: ext

# Bootloader interrupt vector table
dc debug_loader,    0x2000  # 00. Startup/Reset vector
dc panic_handler,   0x2000  # 01. Unaligned SP
dc panic_handler,   0x2000  # 02. Unaligned PC
dc panic_handler,   0x2000  # 03. Invalid instruction
dc panic_handler,   0x2000  # 04. Double fault
dc panic_handler,   0x2000  # 05. Privelege violation
dc panic_handler,   0x2000  # 06. Reserved
dc panic_handler,   0x2000  # 07. Syscall
dc panic_handler,   0x2000  # 08. Write protect
dc panic_handler,   0x2000  # 09. Length
dc panic_handler,   0x2000  # 0A. Presence
dc panic_handler,   0x2000  # 0B. Bus protection
dc panic_handler,   0x2000  # 0C. Reserved
dc panic_handler,   0x2000  # 0D. Reserved
dc panic_handler,   0x2000  # 0E. Reserved
dc panic_handler,   0x2000  # 0F. Reserved

dc panic_handler,   0x2000  # 10. DMA interrupt
dc panic_handler,   0x2000  # 11. Timer interrupt
dc panic_handler,   0x2000  # 12. Reserved
dc panic_handler,   0x2000  # 13. Reserved
dc panic_handler,   0x2000  # 14. UART 0 data interrupt
dc panic_handler,   0x2000  # 15. Reserved
dc panic_handler,   0x2000  # 16. Reserved
dc panic_handler,   0x2000  # 17. Reserved
dc panic_handler,   0x2000  # 18. Reserved
dc panic_handler,   0x2000  # 19. Reserved
dc panic_handler,   0x2000  # 1A. Reserved
dc panic_handler,   0x2000  # 1B. Reserved
dc panic_handler,   0x2000  # 1C. Reserved
dc panic_handler,   0x2000  # 1D. Reserved
dc panic_handler,   0x2000  # 1E. Reserved
dc panic_handler,   0x2000  # 1F. Reserved

dc panic_handler,   0x2000  # 20. Reserved
dc panic_handler,   0x2000  # 21. Reserved
dc panic_handler,   0x2000  # 22. Reserved
dc panic_handler,   0x2000  # 23. Reserved
dc panic_handler,   0x2000  # 24. Reserved
dc panic_handler,   0x2000  # 25. Reserved
dc panic_handler,   0x2000  # 26. Reserved
dc panic_handler,   0x2000  # 27. Reserved
dc panic_handler,   0x2000  # 28. Reserved
dc panic_handler,   0x2000  # 29. Reserved
dc panic_handler,   0x2000  # 2A. Reserved
dc panic_handler,   0x2000  # 2B. Reserved
dc panic_handler,   0x2000  # 2C. Reserved
dc panic_handler,   0x2000  # 2D. Reserved
dc panic_handler,   0x2000  # 2E. Reserved
dc panic_handler,   0x2000  # 2F. Reserved

dc panic_handler,   0x2000  # 30. Reserved
dc panic_handler,   0x2000  # 31. Reserved
dc panic_handler,   0x2000  # 32. Reserved
dc panic_handler,   0x2000  # 33. Reserved
dc panic_handler,   0x2000  # 34. Reserved
dc panic_handler,   0x2000  # 35. Reserved
dc panic_handler,   0x2000  # 36. Reserved
dc panic_handler,   0x2000  # 37. Reserved
dc panic_handler,   0x2000  # 38. Reserved
dc panic_handler,   0x2000  # 39. Reserved
dc panic_handler,   0x2000  # 3A. Reserved
dc panic_handler,   0x2000  # 3B. Reserved
dc panic_handler,   0x2000  # 3C. Reserved
dc panic_handler,   0x2000  # 3D. Reserved
dc panic_handler,   0x2000  # 3E. Reserved
dc panic_handler,   0x2000  # 3F. Reserved

align 0x100


rsect debug_loader
debug_loader>
    ldi r6, 0x666
    STATUS_DISP: ext
    ldi r0, STATUS_DISP
    ldi r1, 0x1337
    stw r0, r1
    halt

end.