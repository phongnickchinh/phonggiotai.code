import os
import hashlib
""" checkHash.py: Chương trình kiểm tra tính toàn vẹn của video bằng cách so sánh hash của từng block với hash của block trước đó
    Nếu file nào bị thay đổi, chương trình sẽ dừng lại và in ra thông báo
    Cuối cùng, chương trình sẽ nối các block thành video và lưu vào final_video.mp4
    Đầu vào: thư mục hash_video chứa các file block, file the_last_hash.txt chứa hash của block cuối cùng
    Đầu ra: final_video.mp4 chứa video sau khi nối các block"""


path='ATTT20232/SHA256_Authenticate video files using a hash function/hash_video'
list_file=os.listdir(path)
#đếm số file trong thư mục hash_video
count_file=len(list_file)
last_file = list_file[count_file-1]
hash_string_check= open('ATTT20232/SHA256_Authenticate video files using a hash function/the_last_hash.txt', 'r').read()
print(hash_string_check)
video = b''

def hash_function(block):
    hash_string=hashlib.sha256(block).hexdigest()
    return hash_string

#kiểm tra hash của từng block
def check_hash(hash_string_check, block):
    #so sánh hash_string_check với hash của block
    block = bytes.fromhex(block)
    #kiểm tra 2 string
    if hash_function(block) == hash_string_check:
        return True
    else:
        return False
    
#chuyển block thành dạng byte và nối vào video
def join_block_video(block, i):
    block = bytes.fromhex(block)
    with open('ATTT20232/SHA256_Authenticate video files using a hash function/final_video.mp4', 'ab') as f:
        f.write(block)





#đọc từng file trong thư mục hash_video
j=0
for i in range(count_file, 0, -1):
    #đọc file i
    print(i)
    with open (path + '/' + str(i) + '.txt', 'r') as f:
        block = f.read()
    #kiểm tra hash của block
    if check_hash(hash_string_check, block):
        j+=1
        hash_string_check = block[-64:]
        block = block[:-64]
        join_block_video(block,j)
    else:
        print('File bị thay đổi, bạn nên vứt nó ra chuồng gà')
        break

