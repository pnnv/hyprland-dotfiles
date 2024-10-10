
import base64
from Crypto.Util.number import *

m = "label"
arr = [chr(ord(ch)^13) for ch in m]
print(arr)