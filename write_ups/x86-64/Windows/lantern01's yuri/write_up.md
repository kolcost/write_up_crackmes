When I tried to launch the program, it crashed with an error about missing (libstdc++-6.dll, libcrypto-3-x64). Judging by the error and the file size, it became clear that the program uses dynamic linking. I added the missing dlls to the program folder in order for it to work.

When I started the program, it displayed the following text:
text
```
enter name:
```
If I left the input empty, the program printed "You cant let it empty". Entering a random string for both name and serial resulted in the following message:
text
```
You are not smart enough
```
To understand the validation logic, I started static analysis in the Ghidra decompiler.

In the main function, I noticed a call to IsDebuggerPresent. If the program detects a debugger, it prints "Debugger detected!" and exits. I didn't need to patch it because I solved the challenge purely statically.

I also saw two loops that decrypt strings using XOR operations. The first loop decrypted the prompt "enter name:" using the key 0x42, and the second loop decrypted "emter the serial:" using the key 0x55. Then the program reads the user input for both fields.

The main logic happens in the hash function. It takes the name string, calculates its SHA-256 hash using an OpenSSL function, and compares it with the serial string the user entered.

This means the serial is simply the SHA-256 hash of the name. I chose root as the name. To get the correct serial on Windows, I generated the SHA-256 hash of *root* using a simple PowerShell command. The result was *4813494d137e1631bba301d5acab6e7bb7aa74ce1185d456565ef51d737677b2*.

I ran the original program and entered root as the name and pasted the hash as the serial. The program accepted it and displayed:
text

```
Somehow u cracked it !!
```

This was a nice challenge. Understanding that the serial was just a standard cryptographic hash made it easy to solve without patching or bypassing the anti-debugging. I learned how to spot standard OpenSSL functions in a binary and how to generate the required hash on Windows.