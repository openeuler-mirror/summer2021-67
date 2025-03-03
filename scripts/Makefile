# SPDX-License-Identifier: GPL-2.0
###
# scripts contains sources for various helper programs used throughout
# the kernel for the build process.
# ---------------------------------------------------------------------------
# kallsyms:      Find all symbols in vmlinux
# pnmttologo:    Convert pnm files to logo files
# conmakehash:   Create chartable
# conmakehash:	 Create arrays for initializing the kernel console tables

HOST_EXTRACFLAGS += -I$(srctree)/tools/include

CRYPTO_LIBS = $(shell pkg-config --libs libcrypto 2> /dev/null || echo -lcrypto)
CRYPTO_CFLAGS = $(shell pkg-config --cflags libcrypto 2> /dev/null)

hostprogs-$(CONFIG_BUILD_BIN2C)  += bin2c
hostprogs-$(CONFIG_KALLSYMS)     += kallsyms
hostprogs-$(CONFIG_LOGO)         += pnmtologo
hostprogs-$(CONFIG_VT)           += conmakehash
hostprogs-$(BUILD_C_RECORDMCOUNT) += recordmcount
hostprogs-$(CONFIG_BUILDTIME_TABLE_SORT) += sorttable
hostprogs-$(CONFIG_ASN1)	 += asn1_compiler
hostprogs-$(CONFIG_MODULE_SIG)	 += sign-file
hostprogs-$(CONFIG_SYSTEM_TRUSTED_KEYRING) += extract-cert
hostprogs-$(CONFIG_SYSTEM_EXTRA_CERTIFICATE) += insert-sys-cert

HOSTCFLAGS_sorttable.o = -I$(srctree)/tools/include
HOSTCFLAGS_asn1_compiler.o = -I$(srctree)/include
HOSTCFLAGS_sign-file.o = $(CRYPTO_CFLAGS)
HOSTLDLIBS_sign-file = $(CRYPTO_LIBS)
HOSTCFLAGS_extract-cert.o = $(CRYPTO_CFLAGS)
HOSTLDLIBS_extract-cert = $(CRYPTO_LIBS)

ifdef CONFIG_UNWINDER_ORC
ifeq ($(ARCH),x86_64)
ARCH := x86
endif
HOSTCFLAGS_sorttable.o += -I$(srctree)/tools/objtool/arch/$(SRCARCH)/include
HOSTCFLAGS_sorttable.o += -DUNWINDER_ORC_ENABLED
HOSTLDLIBS_sorttable = -lpthread
endif

always		:= $(hostprogs-y) $(hostprogs-m)

# The following hostprogs-y programs are only build on demand
hostprogs-y += unifdef

# These targets are used internally to avoid "is up to date" messages
PHONY += build_unifdef
build_unifdef: $(obj)/unifdef
	@:

subdir-$(CONFIG_MODVERSIONS) += genksyms
subdir-y                     += mod
subdir-$(CONFIG_SECURITY_SELINUX) += selinux
subdir-$(CONFIG_DTC)         += dtc
subdir-$(CONFIG_GDB_SCRIPTS) += gdb

# Let clean descend into subdirs
subdir-	+= basic kconfig package gcc-plugins
