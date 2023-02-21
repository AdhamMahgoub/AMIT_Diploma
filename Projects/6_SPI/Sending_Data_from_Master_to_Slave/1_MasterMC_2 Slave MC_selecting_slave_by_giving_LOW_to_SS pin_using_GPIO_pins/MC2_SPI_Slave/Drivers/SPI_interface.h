#ifndef SPI_interface_h
#define SPI_interface_h


void	SPI_initMaster(void);
void	SPI_initSlave(void);
void	SPI_sendByte(u8 data);
u8		SPI_recieveByte(void);




#endif