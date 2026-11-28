# Reverse Engineering Write-ups

My personal collection of reverse engineering and crackme write-ups. Here I document my thought process, the tools I use, and the techniques I learn along the way. 

## Repository Structure

*   `base_libs/` - Shared dynamically linked libraries (DLLs) required to run some of the binaries.
*   `write_ups/` - The main folder for all challenge documentation.
    *   `x86-64/` - Architectures.
        *   `Windows/` - Target operating systems.
*   `template_generator.py` - A small script I use to quickly generate the base Markdown structure for new write-ups.
*   `.gitignore` - Git ignore rules.

## Solved Challenges

Here is a list of the challenges I have documented so far. All of them were solved in a local, offline environment.

**[Crack ID & Password](https://crackmes.one/crackme/6afe53bfc0ad374eab0819a2)** (x86-64, Windows, Difficulty: 3.0)

**[DemoMyLib](https://crackmes.one/crackme/6afccd9b5fa39ab0d4ac24e0)** (x86-64, Windows, Difficulty: 3.0)

**[lantern01's_yuri](https://crackmes.one/crackme/6b05de424b6d53e8802ed86e)** (x86-64, Windows, Difficulty: 3.0)
## Tools Used

I try to stick to the standard, industry-used toolset:
*   **Ghidra** - For static analysis and decompilation.
*   **x64dbg** - For dynamic analysis and memory inspection.
*   **Python & PowerShell** - For writing calculation scripts and generating hashes.