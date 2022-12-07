TC_PATH = $(PWD)/../../../gcc-arm-none-eabi
TOOLCHAIN = $(TC_PATH)/bin/arm-none-eabi
CC = $(TOOLCHAIN)-gcc
CHIP = cortex-m0plus
OPTLVL = -O3 

FLAGS = -Wall $(OPTLVL) -march=armv6s-m -mcpu=$(CHIP) -mthumb -msoft-float --specs=nosys.specs -nostartfiles -ffreestanding -std=c99 -fomit-frame-pointer -fno-optimize-sibling-calls -Wa,-adhln=output.lst 
LIBS = -lnosys -lc -lm

OBJS = timer.o wami_gmm.o wami_morpho.o wami_kernel3_driver.o wami_utils.o

OBJS := vectors.o putget.o supportFuncs.o LED.o $(OBJS)
LINKDIR= -L$(TC_PATH)/$(TOOLCHAIN)/lib
INCLIB = -I$(TC_PATH)/$(TOOLCHAIN)/include -I$(PWD)../lib

all: main.elf 

%.o: %.s
	$(CC) $(FLAGS) $(INCLIB) -c -o $@ $<

%.o: ../%.s
	$(CC) $(FLAGS) $(INCLIB) -c -o $@ $<

%.o: %.c
	$(CC) ${FLAGS} $(INCLIB) -c -o $@ $< 

%.o: ../%.c
	$(CC) ${FLAGS} $(INCLIB) -c -o $@ $< 

%.o: ../lib/%.c
	$(CC) ${FLAGS} $(INCLIB) -c -o $@ $< 

%.o: ../../lib/%.c
	$(CC) ${FLAGS} $(INCLIB) -c -o $@ $< 




main.elf: $(OBJS) vectors.s putget.s supportFuncs.c LED.s
	$(CC) $(FLAGS) -u _printf_float -Wl,-Map,output.map -T ../../memmap $(LINKDIR) $(OBJS) -o main.elf $(LIBS)
	$(TOOLCHAIN)-objdump -d main.elf > main.lst
	$(TOOLCHAIN)-objcopy main.elf main.bin -O binary

clean:
	rm -rf *.o *.elf output* *.lst *.bin *~
