
import base64
from Crypto.Util.number import *

l = 11515195063862318899931685488813747395775516287289682636499965282714637259206269
byts = long_to_bytes(l)
hx = byts.hex()
ascii_bytes = bytes.fromhex(hx)
