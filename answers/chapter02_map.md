1. Since im using Go, im going to poke around this [Go implementation](https://github.com/nanmu42/bluelox) of jlox.
Theyre handwritten.

2. These are the considerable things before using JIT.
- Complexity
- Portability, JIT compilers generate code to a specific architecture.
- Security Concerns, Generating and executing machine code in runtime may lead to code injection attack, some system avoid JIT to minimize such risk.

3. So, i found out that most Lisps support macros (code that executed at compile time), so the implementation needs to handle the macro itself while compiling.
