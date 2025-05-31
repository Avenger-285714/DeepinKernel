TARGET=truechip

ifeq ($(TARGET),xinluxa)
KCFLAGS=-D__CHIP_SELECT__=__FPGA_XINLUX_A__
else ifeq ($(TARGET),xinluxb)
KCFLAGS=-D__CHIP_SELECT__=__FPGA_XINLUX_B__
else ifeq ($(TARGET),truechip)
KCFLAGS=-D__CHIP_SELECT__=__TRUE_CHIP__
else
TARGET=truechip
KCFLAGS=-D__CHIP_SELECT__=__TRUE_CHIP__
#$(error "Please set TARGET <xinluxa, xinluxb, truechip>")
endif

ifeq ($(CPU),aarch64)
	KCFLAGS+=-D_MWV206_CPU_=_MWV206_AARCH64_
else ifeq ($(CPU),mips64)
	KCFLAGS+=-D_MWV206_CPU_=_MWV206_LOONGSON_
else ifeq ($(CPU),x86_64)
	KCFLAGS+=-D_MWV206_CPU_=_MWV206_X86_64_
else ifeq ($(CPU),x86)
	KCFLAGS+=-D_MWV206_CPU_=_MWV206_X86_
else ifeq ($(CPU),x8664)
	KCFLAGS+=-D_MWV206_CPU_=_MWV206_X86_64_
endif

ifeq ($(PCIEBAR), 64)
KCFLAGS+=-D__PCIE_64BIT_BAR__
endif

KCFLAGS+=-D_MWV206_OS_=_MWV206_DEEPIN_
KCFLAGS+= -Wno-cast-function-type -Wno-implicit-fallthrough -Wno-missing-field-initializers

platform=$(HOST)-$(TARGET)

ifeq ($(PCIEBAR), 64)
KCFLAGS+=-D__PCIE_64BIT_BAR__
endif

# set compiler
CC= $(CROSS_COMPILER)gcc
KCFLAGS+=-O2
#CFLAGS+=-O0 -g
KCFLAGS+=-v -save-temps 
#CFLAGS+=-D__MWV206_SYSLIBPATH__="\"$(SYSTEMLIBPATH)\""
KCFLAGS+=-fno-strict-aliasing -Wall -W -Wextra -Wno-unused-label -Wno-unused-function -Wno-pointer-sign -Wno-unused-parameter -Wno-missing-braces -Wno-deprecated-declarations -Werror 
KCFLAGS+= -fstack-protector-strong -Wl,-z,relro -z,now -Wl,-z,-Wstramplines,noexecstack -fPIC -D_FORTIFY_SOURCE=2
#KCFLAGS+=-D_MWV206_SLEEP_TEMP_
KCFLAGS+=-Wno-builtin-macro-redefined -U__FILE__ -D__FILE__='"$(subst $(dir $<), , $<)"'
   	
KCFLAGS+= -Wextra -Wall -Werror -Wno-unused-parameter -Wno-sign-compare -Wno-unused-function #-Wno-undef -Wno-unused-parameter -Wno-unused-variable -Wno-unused-label -Wno-unused-function -Wno-unused-value -Wno-sign-compare -Wno-missing-field-initializers -Werror
KCFLAGS+= -DLINUX=1 -DJROSVER=1
CC += $(KCFLAGS)
#hhl:cc1: error: unrecognized command line option "-Wno-sizeof-pointer-memaccess" [-Werror]
CFLAGS+=-Wno-sizeof-pointer-memaccess
CFLAGS+=-Wno-builtin-macro-redefined -U__FILE__ -D__FILE__='"$(subst $(dir $<), , $<)"'
#CFLAGS+= -fdiagnostics-color=auto
CFLAGS+=-I$(GLJ206SRCPATH)/include -I$(GLJ206INCLUDEPATH)
#CFLAGS+=-D__MWV206_DEBUG_VERSION__

LD = ${CROSS_COMPILE}ld
LDFLAGS += -shared -nostdlib
LDFLAGS += -z relro -z now
LDFLAGS += -L$(GLJ206INPUTLIBPATH)
LDFLAGS += -L$(GLJ206OUTPUTLIBPATH)
LDFLAGS += -L$(SYSTEMLIBPATH)

AR = ${CROSS_COMPILE}ar
ARFLAGS = -cr

obj-$(CONFIG_DRM_MWV206)		:= mwv206.o
mwv206-objs := mwv206linuxdev/gljos.o \
               mwv206linuxdev/mwv206_pci.o mwv206linuxdev/mwv206_proc.o mwv206linuxdev/mwv206_pm.o \
               mwv206linuxdev/mwv206_fb.o mwv206linuxdev/fill.o mwv206linuxdev/copy.o \
               mwv206linuxdev/mwv206_hdmiaudio.o \
               mwv206linuxdev/mwv206_edid.o \
               mwv206linuxdev/mwv206_backlight.o \
               mwv206hal/gljos_kernel.o \
               mwv206hal/jmirq.o \
               mwv206hal/oshal_linux_kernel.o \
               mwv206hal/jmiic.o \
               mwv206hal/jmspi.o \
               mwv206hal/jmspi_flash.o \
               mwv206hal/jmpwm.o \
               mwv206hal/jmgpio.o \
               mwv206hal/mwv206ddr_chip.o \
               mwv206hal/jmgraphoutput.o \
               mwv206hal/mwv206memmgr.o \
               mwv206hal/mwv206kdma.o \
               mwv206hal/mwv206dev.o \
               mwv206hal/mwv206ioctl.o \
               mwv206hal/mwv206ioctl_mem.o \
               mwv206hal/mwv206ioctl_cmd.o \
               mwv206hal/mwv206ioctl_intr.o \
               mwv206hal/mwv206ioctl_display.o \
               mwv206hal/mwv206ioctl_dev.o \
               mwv206hal/mwv206reg.o \
               mwv206hal/mwv206sdm.o \
               mwv206hal/mwv206kg3d.o \
               mwv206hal/mwv206kg2d.o \
               mwv206hal/mwv206ver_kernel.o \
               mwv206hal/mwv206devconfigparser.o \
               mwv206hal/mwv206devconfigreader.o \
               mwv206hal/mwv206ioctl_config.o \

ifeq ($(CPU),aarch64)
	mwv206-objs += mwv206hal/mwv206dec_aarch64.o 
else ifeq ($(CPU),mips64)
	mwv206-objs += mwv206hal/mwv206dec_mips64.o 
else ifeq ($(CPU),amd64)
	mwv206-objs += mwv206hal/mwv206dec_amd64.o 
endif	

#mwv206-y := mwv206hal/*.o \
	mwv206linuxdev/*.o \

#obj-$(CONFIG_DRM_MWV206) := mwv206.o

ccflags-y := -I$(src)
