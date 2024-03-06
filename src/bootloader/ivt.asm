asect 0
start: ext
panic_handler: ext

# Bootloader interrupt vector table
dc start,           0xa000  # 00. Startup/Reset vector
dc panic_handler,   0       # 01. Unaligned SP
dc panic_handler,   0       # 02. Unaligned PC
dc panic_handler,   0       # 03. Invalid instruction
dc panic_handler,   0       # 04. Double fault
dc panic_handler,   0       # 05. Privelege violation
dc panic_handler,   0       # 06. Reserved
dc panic_handler,   0       # 07. Syscall
dc panic_handler,   0       # 08. Write protect
dc panic_handler,   0       # 09. Length
dc panic_handler,   0       # 0A. Presence
dc panic_handler,   0       # 0B. Bus protection
dc panic_handler,   0       # 0C. Reserved
dc panic_handler,   0       # 0D. Reserved
dc panic_handler,   0       # 0E. Reserved
dc panic_handler,   0       # 0F. Reserved

dc panic_handler,   0       # 10. DMA interrupt
dc panic_handler,   0       # 11. Timer interrupt
dc panic_handler,   0       # 12. Reserved
dc panic_handler,   0       # 13. Reserved
dc panic_handler,   0       # 14. UART 0 data interrupt
dc panic_handler,   0       # 15. Reserved
dc panic_handler,   0       # 16. Reserved
dc panic_handler,   0       # 17. Reserved
dc panic_handler,   0       # 18. Reserved
dc panic_handler,   0       # 19. Reserved
dc panic_handler,   0       # 1A. Reserved
dc panic_handler,   0       # 1B. Reserved
dc panic_handler,   0       # 1C. Reserved
dc panic_handler,   0       # 1D. Reserved
dc panic_handler,   0       # 1E. Reserved
dc panic_handler,   0       # 1F. Reserved

dc panic_handler,   0       # 20. Reserved
dc panic_handler,   0       # 21. Reserved
dc panic_handler,   0       # 22. Reserved
dc panic_handler,   0       # 23. Reserved
dc panic_handler,   0       # 24. Reserved
dc panic_handler,   0       # 25. Reserved
dc panic_handler,   0       # 26. Reserved
dc panic_handler,   0       # 27. Reserved
dc panic_handler,   0       # 28. Reserved
dc panic_handler,   0       # 29. Reserved
dc panic_handler,   0       # 2A. Reserved
dc panic_handler,   0       # 2B. Reserved
dc panic_handler,   0       # 2C. Reserved
dc panic_handler,   0       # 2D. Reserved
dc panic_handler,   0       # 2E. Reserved
dc panic_handler,   0       # 2F. Reserved

dc panic_handler,   0       # 30. Reserved
dc panic_handler,   0       # 31. Reserved
dc panic_handler,   0       # 32. Reserved
dc panic_handler,   0       # 33. Reserved
dc panic_handler,   0       # 34. Reserved
dc panic_handler,   0       # 35. Reserved
dc panic_handler,   0       # 36. Reserved
dc panic_handler,   0       # 37. Reserved
dc panic_handler,   0       # 38. Reserved
dc panic_handler,   0       # 39. Reserved
dc panic_handler,   0       # 3A. Reserved
dc panic_handler,   0       # 3B. Reserved
dc panic_handler,   0       # 3C. Reserved
dc panic_handler,   0       # 3D. Reserved
dc panic_handler,   0       # 3E. Reserved
dc panic_handler,   0       # 3F. Reserved

align 0x100

end.
