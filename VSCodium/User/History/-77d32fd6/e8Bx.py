
import base64
from Crypto.Util.number import *

m = "label"
arr = [ord(ch) for ch in m]
for a in arr:
  a = a ^ 13
nm = [chr(n) for n in arr]
print(nm)