import hashlib
import os

def md5_of_file(file_path, block_size=4096):
    md5 = hashlib.md5()
    with open(file_path, 'rb') as f:
        for block in iter(lambda: f.read(block_size), b''):
            md5.update(block)
    return md5.hexdigest()
# Replace 'path_to_your_file.mp4' with the path to your MP4 file
# md5_hash = md5_of_file('DSA_Template_Python/test.mp4')
# md5_hash = md5_of_file('DSA_Template_Python/FinalModelMP4.mp4')
print("MD5 Hash:", md5_hash)

# print(os.getcwd())

