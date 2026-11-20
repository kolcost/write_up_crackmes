ID = 0x1337beef
DAT_140004018 = 0xA5A5A5A5
_DAT_140004014 = 0x13579BDF
_DAT_140004010 = 0xDEADBEEF


A = DAT_140004018 ^ ID
A &= 0xFFFFFFFF

B = (A << 5) | (A >> 0x1b)
B &= 0xFFFFFFFF

C = B + _DAT_140004014
C &= 0xFFFFFFFF

password = C ^ _DAT_140004010
password &= 0xFFFFFFFF

print("Pass of the program "+hex(password))