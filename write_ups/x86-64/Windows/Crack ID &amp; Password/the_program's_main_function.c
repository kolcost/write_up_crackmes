undefined4 FUN_140003410(void)
{
  BOOL BVar1;
  HANDLE hProcess;
  uint local_28;
  uint local_24 [3];
  
  FUN_140001887();
  BVar1 = IsDebuggerPresent();
  if (BVar1 == 0) {
    local_24[2] = 0;
    hProcess = GetCurrentProcess();
    BVar1 = CheckRemoteDebuggerPresent(hProcess,(PBOOL)(local_24 + 2));
    if ((BVar1 == 0) || (local_24[2] == 0)) {
      local_28 = 0;
      local_24[0] = 0;
      FUN_140001760((longlong *)&_ZSt4cout_exref,"Welcome!\n");
      FUN_140001760((longlong *)&_ZSt4cout_exref,"Enter Your ID (hex): ");
      *(uint *)(CheckRemoteDebuggerPresent + *(longlong *)(_ZSt3cin_exref + -0x18)) =
           *(uint *)(CheckRemoteDebuggerPresent + *(longlong *)(_ZSt3cin_exref + -0x18)) &
           0xffffffb5 | 8;
      _ZNSi10_M_extractIjEERSiRT_(&_ZSt3cin_exref,&local_28);
      local_24[1] = 0xb8fa;
      local_24[2] = 0xacdb;
      if ((local_28 >> 0x10 == 0x1337) && ((local_28 & 0xffff) == 0xbeef)) {
        FUN_140001760((longlong *)&_ZSt4cout_exref,"Enter Your Password (hex): ");
        *(uint *)(CheckRemoteDebuggerPresent + *(longlong *)(_ZSt3cin_exref + -0x18)) =
             *(uint *)(CheckRemoteDebuggerPresent + *(longlong *)(_ZSt3cin_exref + -0x18)) &
             0xffffffb5 | 8;
        _ZNSi10_M_extractIjEERSiRT_(&_ZSt3cin_exref,local_24);
        if (local_24[0] ==
            (((DAT_140004018 ^ local_28) << 5 | (DAT_140004018 ^ local_28) >> 0x1b) + _DAT_140004014
            ^ _DAT_140004010)) {
          FUN_140001760((longlong *)&_ZSt4cout_exref,
                        "Congratulations, you have completed the challenge!\n");
          return 0;
        }
      }
      FUN_140001760((longlong *)&_ZSt4cout_exref,"Oops, Bad Entry!\nTry Again.\n");
      return 1;
    }
  }
  FUN_140001760((longlong *)&_ZSt4cout_exref,"Debugger detected!\n");
  return 1;
}
