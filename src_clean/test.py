import gRASPA as g

from copy import deepcopy, copy

# Set a value in the C++ library
RN = g.RandomNumber()

RN.randomsize = 1000

RN.AllocateRandom()

all_attributes = dir(RN)

attributes = [attr for attr in all_attributes if not callable(getattr(RN, attr)) and not attr.startswith("__")]

print(f"attributes: {attributes}\n")

print(f"RN.host_random: {RN.host_random.z}\n")

RN.DeviceRandom()

print(f"RN.host_random: {RN.host_random.z}\n")

import os
os.chdir("CO2-MFI")
print(f"files: {os.listdir()}")
g.RUN()
