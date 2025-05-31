#set build host & target & pciebar
#HOST=linux-x86
#HOST=linux-x8664
#HOST=ft1500a
#TARGET=xinluxa
#TARGET=xinluxb
TARGET=truechip
#PCIEBAR=
# PCIEBAR=64
#from kernel build
ifneq ($(KERNELRELEASE),)
    ifeq ($(TARGET),xinluxa)
        KCFLAGS=-D__CHIP_SELECT__=__FPGA_XINLUX_A__
    else ifeq ($(TARGET),xinluxb)
        KCFLAGS=-D__CHIP_SELECT__=__FPGA_XINLUX_B__
    else ifeq ($(TARGET),truechip)
        KCFLAGS=-D__CHIP_SELECT__=__TRUE_CHIP__
    else
      #$(error "Please set TARGET <xinluxa, xinluxb, truechip>")
    endif
    
    ifeq ($(CPU),aarch64)
		KCFLAGS+=-D_MWV206_CPU_=_MWV206_AARCH64_
	else ifeq ($(CPU),mips64)
		KCFLAGS+=-D_MWV206_CPU_=_MWV206_LOONGSON_
		KCFLAGS+=-D__PCIE_CONFIGSPACE_MAXREG__=256 #default is 0x1000
	else ifeq ($(CPU),x86_64)
		KCFLAGS+=-D_MWV206_CPU_
	else ifeq ($(CPU),x86)
		KCFLAGS+=-D_MWV206_CPU_
	else ifeq ($(CPU),x8664)
		KCFLAGS+=-D_MWV206_CPU_
	else
		$(error "Please set CPU ")
	endif
    
    ifeq ($(OS),linux)
		ifeq ($(CPU),x86)
         	KCFLAGS+=-D_MWV206_CPU_
         	KCFLAGS+=-D_MWV206_OS_
		else ifeq ($(CPU),x8664)
         	KCFLAGS+=-D_MWV206_CPU_
         	KCFLAGS+=-D_MWV206_OS_
         endif
    else ifeq ($(OS),neokylin)
        KCFLAGS+=-D_MWV206_OS_=_MWV206_NEOKYLIN_
    else ifeq ($(OS),jari)
	KCFLAGS+=-D_MWV206_OS_=_MWV206_JARI_
    else ifeq ($(OS),kylin)
        KCFLAGS+=-D_MWV206_OS_=_MWV206_KYLIN_
    else ifeq ($(OS),deepin)
        KCFLAGS+=-D_MWV206_OS_=_MWV206_DEEPIN_
        KCFLAGS+=-Wno-implicit-fallthrough
    else ifeq ($(OS),ky10)
        KCFLAGS+=-D_MWV206_OS_=_MWV206_KYLIN_
        KCFLAGS+=-Wno-implicit-fallthrough
    else
        $(error "Please set OS ") 
    endif
    
    HOST=$(OS)-$(CPU)
    $(warning "Auto platform = $(HOST)")
    
    platform=$(HOST)-$(TARGET)
    
    ifeq ($(PCIEBAR), 64)
        KCFLAGS+=-D__PCIE_64BIT_BAR__
    endif
    
    #$(warning "Building for $(platform)")
    
    PRJ_DIR=$(obj)/../
    #KCFLAGS+= -O0 -g
    KCFLAGS+= -O2
    KCFLAGS+=-save-temps
    KCFLAGS+= -fstack-protector-strong -Wl,-z,relro -z,now -Wl,-z,-Wstramplines,noexecstack -fPIC -D_FORTIFY_SOURCE=2
    #KCFLAGS+=-D_MWV206_SLEEP_TEMP_
    KCFLAGS+=-Wno-builtin-macro-redefined -U__FILE__ -D__FILE__='"$(subst $(dir $<), , $<)"'
   	
    KCFLAGS+= -Wextra -Wall -Werror -Wno-unused-parameter -Wno-sign-compare -Wno-unused-function #-Wno-undef -Wno-unused-parameter -Wno-unused-variable -Wno-unused-label -Wno-unused-function -Wno-unused-value -Wno-sign-compare -Wno-missing-field-initializers -Werror
    
    KCFLAGS+= -I/lib/modules/$(shell uname -r)/build/include -I$(PRJ_DIR) -I$(PRJ_DIR)/include -I$(PRJ_DIR)../include -I$(PRJ_DIR)/mwv206hal -I$(PRJ_DIR)/mwv206linuxdev/
    KCFLAGS+= -DLINUX=1 -DJROSVER=1
    #KCFLAGS+= -D__MWV206_DEBUG_VERSION__
    CC += $(KCFLAGS)
    
    obj-m		:= mwv206.o
    mwv206-objs := gljos.o \
                   mwv206_pci.o mwv206_proc.o mwv206_pm.o \
                   mwv206_fb.o fill.o copy.o \
                   mwv206_hdmiaudio.o \
                   mwv206_edid.o \
                   mwv206_backlight.o \
                   ../mwv206hal/gljos_kernel.o \
                   ../mwv206hal/jmirq.o \
                   ../mwv206hal/oshal_linux_kernel.o \
                   ../mwv206hal/jmiic.o \
                   ../mwv206hal/jmspi.o \
                   ../mwv206hal/jmspi_flash.o \
                   ../mwv206hal/jmpwm.o \
                   ../mwv206hal/jmgpio.o \
                   ../mwv206hal/mwv206ddr_chip.o \
                   ../mwv206hal/jmgraphoutput.o \
                   ../mwv206hal/mwv206memmgr.o \
                   ../mwv206hal/mwv206kdma.o \
                   ../mwv206hal/mwv206dev.o \
                   ../mwv206hal/mwv206ioctl.o \
                   ../mwv206hal/mwv206ioctl_mem.o \
                   ../mwv206hal/mwv206ioctl_cmd.o \
                   ../mwv206hal/mwv206ioctl_intr.o \
                   ../mwv206hal/mwv206ioctl_display.o \
                   ../mwv206hal/mwv206ioctl_dev.o \
                   ../mwv206hal/mwv206reg.o \
                   ../mwv206hal/mwv206sdm.o \
                   ../mwv206hal/mwv206kg3d.o \
                   ../mwv206hal/mwv206kg2d.o \
                   ../mwv206hal/mwv206ver_kernel.o \
                   ../mwv206hal/mwv206devconfigparser.o \
                   ../mwv206hal/mwv206devconfigreader.o \
                   ../mwv206hal/mwv206ioctl_config.o \
                   
     ifeq ($(CPU),aarch64)
		mwv206-objs += ../mwv206hal/mwv206dec_aarch64.o 
     else ifeq ($(CPU),mips64)
		mwv206-objs += ../mwv206hal/mwv206dec_mips64.o 
     else ifeq ($(CPU),amd64)
		mwv206-objs += ../mwv206hal/mwv206dec_amd64.o 
     endif	
	
#from shell build
else
    KERNELDIR	:= /lib/modules/$(shell uname -r)/build
    PWD			:= $(shell pwd)
default:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.[iso] *.ko ../mwv206hal/*.[iso] 
	rm -rf *.o.cmd ../mwv206hal/.*.o.cmd
	make -C $(KERNELDIR) M=$(PWD) clean
depend:
	make -C $(KERNELDIR) M=$(PWD) depend 
endif

