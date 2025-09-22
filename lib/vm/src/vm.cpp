#include "vm.hpp"
#include "os.hpp"

byte M[Msz];
addr Cp = sizeof(bcHeader);
addr Ip = 0xFFFF;  // uninitialized fake value breaks if not configured
addr R[Rsz];
byte Rp = 0;
cell D[Dsz];
byte Dp = 0;

bool trace = true;

void nop() {
    if (trace) fprintf(stderr, "nop\n");
}

void halt() {
    if (trace) fprintf(stderr, "halt\n\n");
    exit(0);
}

