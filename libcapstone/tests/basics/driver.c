#include <capstone/capstone.h>

#undef NDEBUG
#include <assert.h>

int main ()
{
  csh h;
  cs_insn *insn;
  size_t n;

  /* `mov eax, 0x1; ret` in 32-bit x86 machine code.
   */
  {
    const unsigned char code[] = {0xb8, 0x01, 0x00, 0x00, 0x00, 0xc3};

    assert (cs_open (CS_ARCH_X86, CS_MODE_32, &h) == CS_ERR_OK);

    n = cs_disasm (h, code, sizeof (code), 0x1000, 0, &insn);
    assert (n == 2);

    assert (insn[0].id == X86_INS_MOV);
    assert (insn[1].id == X86_INS_RET);

    cs_free (insn, n);
    assert (cs_close (&h) == CS_ERR_OK);
  }

  /* `ret` in little-endian AArch64 machine code.
   */
  {
    const unsigned char code[] = {0xc0, 0x03, 0x5f, 0xd6};

    assert (cs_open (CS_ARCH_AARCH64, CS_MODE_ARM, &h) == CS_ERR_OK);

    n = cs_disasm (h, code, sizeof (code), 0x1000, 0, &insn);
    assert (n == 1);

    assert (insn[0].id == AARCH64_INS_RET);

    cs_free (insn, n);
    assert (cs_close (&h) == CS_ERR_OK);
  }

  return 0;
}
