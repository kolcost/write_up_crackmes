The program started without any issues. When I started the program, it displayed the following text:
text

```
Simple Login
Library: obfuscpp
Enter license key:
```

Entering an invalid license key resulted in the following message, after which the program terminated:
text
```
[-] Invalid license key.
```
To understand the validation logic, I started static analysis in the Ghidra decompiler.

Once I loaded the binary into Ghidra, I found the main function (which was FUN_140001280). The code looked heavily obfuscated. There were lots of weird variable types like undefined *********** and complex C++ string manipulations. It made sense because the program literally says it uses obfuscpp.

Right at the beginning of main, I noticed multiple calls to FUN_140005980. Looking at the logic, it was an anti-debugging check. If it returned a non-zero value, the program would go into a weird loop or print a fake key and exit.

Instead of trying to bypass every single check in the debugger, I decided to patch the check function itself in Ghidra so it always returns 0. To do this, I went to FUN_140005980, opened the Listing view, right-clicked the first instruction and chose Patch Instruction. I replaced the first two instructions with XOR EAX, EAX and RET. This forces the function to instantly return 0. Then I went to File -> Export Program and saved the patched binary as DemoMyLib(patched).exe. The anti-debugging was completely gone forever.

Even with the anti-debugging disabled, the validation logic was a nightmare of custom cryptography. I saw that the program decrypts the correct license key using a function called FUN_1400039d0 and stores it in a local variable. I decided to just grab this key from memory while the program runs.

I opened DemoMyLib(patched).exe in x64dbg. Since Windows uses ASLR, the absolute addresses from Ghidra won't work directly. I found the base address of the module in the Memory Map and added the offset of the decryption function (39d0). I went to Base + 39d0 and set a breakpoint with F2.

Then I ran the program, entered a random key. As soon as I hit Enter, the program hit my breakpoint. I stepped over the function with F8. Now the correct key was decrypted. I looked at the RDX register, and it pointed directly to the decrypted string. I went to this address in the Dump window and saw the plaintext license key right in the ASCII column.

I copied the key, restarted the program, and pasted it. The program accepted it and displayed:
text

```
[+] License OK. Welcome!
  key hash: 0xAB59E8046FDF64D3
  mixed: 0x17DB86E3F3B36A8C
  ```

This was a good challenge. The obfuscpp library made static analysis of the validation logic a pain, so patching the anti-debugging function in Ghidra and dumping the decrypted string from memory in x64dbg was the fastest way to solve it. I learned how to properly bypass anti-debugging forever by modifying the binary, and how strings look in memory during runtime.