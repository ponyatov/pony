# .mk files
MK += Makefile $(wildcard mk/*.mk)
MK += $(wildcard   hw/*/*.mk)
MK += $(wildcard  cpu/*/*.mk)
MK += $(wildcard arch/*/*.mk)
MK += $(wildcard   os/*/*.mk)

# cmake files
CM += CMake*   $(wildcard cmake/*.cmake)
CM += $(wildcard   hw/*/*.cmake)
CM += $(wildcard  cpu/*/*.cmake)
CM += $(wildcard arch/*/*.cmake)
CM += $(wildcard   os/*/*.cmake)

# C/C++
C  += $(wildcard src/*.c*)
H  += $(wildcard inc/*.h*)

# Rust
R += Cargo.toml $(wildcard src/*.rs)

# ini
S  += $(wildcard lib/*.ini) $(wildcard lib/*.f)
