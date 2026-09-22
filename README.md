# capstone - Multi-architecture disassembler C library

This is a `build2` package repository for [`capstone`](https://github.com/capstone-engine/capstone),
a lightweight, multi-architecture disassembly framework.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libcapstone` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libcapstone/PACKAGE-README.md) file.

The development setup for `capstone` uses the standard `bdep`-based workflow.
For example:

```
git clone .../capstone.git
cd capstone

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
