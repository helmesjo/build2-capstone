# libcapstone - A C library

This is a `build2` package for the [`capstone`](https://github.com/capstone-engine/capstone)
C library. It provides a lightweight, multi-architecture disassembly
framework supporting ARM, AArch64, Alpha, ARC, BPF, Ethereum VM, HPPA,
LoongArch, M68K, M680X, MIPS, MOS65XX, PowerPC, RISC-V, SH, Sparc, SystemZ,
TMS320C64x, TriCore, WebAssembly, XCore, x86 (16/32/64-bit), and Xtensa, all
built in and enabled by default.


## Usage

To start using `libcapstone` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libcapstone ^6.0.0
```

Then import the library in your `buildfile`:

```
import libs = libcapstone%lib{capstone}
```


## Importable targets

This package provides the following importable targets:

```
lib{capstone}
```

The `lib{capstone}` target is the disassembly engine itself. All
architecture backends are compiled in unconditionally, so no separate
per-architecture targets are provided.


## Configuration variables

This package provides no configuration variables.
