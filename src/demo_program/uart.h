#ifndef _DEMO_PROGRAM_UART_H_
#define _DEMO_PROGRAM_UART_H_

void send_string_to_uart(char* string);
void send_bytes_to_uart(char* bytes, int count);
int read_from_uart(char* buf, int count);

#endif /* _DEMO_PROGRAM_UART_H_ */