
import base64

hs = "72bca9b68fc16ac7beeb8f849dca1d8a783e8acf9679bf9269f7bf"
br = bytes.fromhex(hs)
base64_encoded = base64.b64encode(br).decode('ascii')

print(base64_encoded)