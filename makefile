# Define the toolchain
TGT = i686-elf
CC = $(TGT)-gcc
AS = $(TGT)-as

# Directories
ROOTDIR = $(HOME)/projects/bfos
BOOTSRC = $(ROOTDIR)/src/boot
KERNSRC = $(ROOTDIR)/src/kernel
LIBDIR  = $(ROOTDIR)/src/lib/libc
OUTDIR  = $(ROOTDIR)/output
BINDIR  = $(OUTDIR)/bin

# Variables
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I$(LIBDIR)
LFLAGS = -ffreestanding -O2 -nostdlib -lgcc

# Files
LINKERSCRIPT = $(ROOTDIR)/src/lib/libk/linker.ld

BOOTFILES = $(wildcard $(BOOTSRC)/*.s)
BOOTOUTFILES = $(patsubst %.s,%.o,$(BOOTFILES))

KERNFILES = $(wildcard $(KERNSRC)/*.c)
KERNOUTFILES = $(patsubst %.c,%.o,$(KERNFILES))

OUTFILES = $(wildcard $(OUTDIR)/*.o)
COPYPATH = /mnt/hgfs/bfos
GRUBFILE = $(BOOTSRC)/grub.cfg

all:
	@clear
	make clean
	make boot
	make kernel
	make link
	@ if [ -d $(COPYPATH) ]; then make bootable; fi;

boot: $(BOOTFILES)
	@ clear
	@ echo "Assembling boot files..."
	$(AS) $(BOOTFILES) -o $(BOOTOUTFILES)
	@ if [ ! -d $(OUTDIR) ]; then mkdir $(OUTDIR); fi;
	mv $(BOOTSRC)/*.o $(OUTDIR)/

kernel: $(KERNFILES)
	@ clear
	@ echo "Building kernel..."
	$(CC) -c $(KERNFILES) $(CFLAGS)
	@ if [ ! -d $(OUTDIR) ]; then mkdir $(OUTDIR); fi;
	mv *.o $(OUTDIR)/

link:
	@ clear
	@ echo "Linking objects..."
	@ if [ ! -d $(BINDIR) ]; then mkdir $(BINDIR); fi;
	$(CC) -T $(LINKERSCRIPT) -o $(BINDIR)/bfos.bin $(LFLAGS) $(OUTFILES)
	

bootable:
	@ clear
	@ echo "Building bootable image..."
	mkdir -p $(COPYPATH)/boot/grub
	cp $(BINDIR)/*.bin $(COPYPATH)/boot/
	cp $(GRUBFILE) $(COPYPATH)/boot/grub/

	rm $(COPYPATH)/bfos.iso
	grub-mkrescue -o $(COPYPATH)/bfos.iso $(COPYPATH)
	rm -rf $(COPYPATH)/boot/

clean:
	rm -rf $(OUTDIR)