#!/bin/sh

export LEDEROOT=/home/balaji/Desktop/qbc_lede

export PATH=$PATH:${LEDEROOT}/staging_dir/toolchain-arm_cortex-a15+neon-vfpv4_gcc-5.5.0_musl_eabi/bin/
export STAGING_DIR=${LEDEROOT}/staging_dir/toolchain-arm_cortex-a15+neon-vfpv4_gcc-5.5.0_musl_eabi
export CFLAGS=-I${LEDEROOT}/staging_dir/target-arm_cortex-a15+neon-vfpv4_musl_eabi/usr/include/
export LDFLAGS=-L${LEDEROOT}/staging_dir/target-arm_cortex-a15+neon-vfpv4_musl_eabi/usr/lib

export PKG_CONFIG_DIR=
export PKG_CONFIG_SYSROOT_DIR=${LEDEROOT}/staging_dir/target-arm_cortex-a15+neon-vfpv4_musl_eabi
export PKG_CONFIG_LIBDIR=${PKG_CONFIG_SYSROOT_DIR}/usr/lib/pkgconfig:${PKG_CONFIG_SYSROOT_DIR}/usr/share/pkgconfig
