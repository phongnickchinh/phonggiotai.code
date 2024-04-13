import os
import hashlib
""" Chương trình lấy video birthday.mp4, băm thành các block 1024 bytes, sau đó nối vào cuối mỗi block 256 bytes hash của block trước đó, tiếp tục băm
    đến khi hết video, cuối cùng lưu hash của block cuối cùng vào file the_last_hash.txt
    last_hash.txt sẽ được sử dụng để kiểm tra tính toàn vẹn của video
        
    LƯU Ý: Nếu bạn chạy lại chương trình này, việc ghi lại các block trong hash_video sẽ mất khoảng 2phút"""


path = 'ATTT20232/SHA256_Authenticate video files using a hash function/birthday.mp4'
# lưu file vào một biến
video = open(path, 'rb').read()
# lấy ra 1024 bytes cuối cùng, đồng thời cắt bỏ 1024 bytes cuối cùng
len_video = len(video)
def get_last_1024_bytes():
    global video
    if len(video) <= 1024:
        last_1024_bytes = video
        video = b''
        return last_1024_bytes
    last_1024_bytes=video[-1024:]
    video=video[:-1024]
    global len_video
    len_video = len(video)
    print(len_video)
    with open('log.txt', 'a') as f:
        f.write(str(len_video) + '\n')
    return last_1024_bytes

#hàm băm đoạn video
def hash_function(block):
    hash_string=hashlib.sha256(block).hexdigest()
    return hash_string

#nối đoạn phân mảnh với 256byté hash
def join_block_hash(block, _hash):
    _hash = bytes.fromhex(_hash)
    return block + _hash #trả về kiểu byte

#hàm băm và nối 2 block
def hash_and_connect(block, next_block):
    _hash = hash_function(block)
    video_with_hashcode = join_block_hash(next_block, _hash)
    return video_with_hashcode

#tiến hành với block cuối cùng
current_block = get_last_1024_bytes()
#lưu block cuối cùng này vào file 1.txt trong thư mục hash_video
with open('ATTT20232/SHA256_Authenticate video files using a hash function/hash_video/1.txt', 'a') as f:
    save_block = current_block.hex()
    #xoá toàn bộ nội dung cũ
    f.write('')
    f.write(save_block)

i=1
#tiến hành với các block còn lại
while len(video) > 0:
    next_block = get_last_1024_bytes()
    current_block = hash_and_connect(current_block, next_block)
    save_block = current_block.hex()
    i+=1
    #lưu block vào file
    with open('ATTT20232/SHA256_Authenticate video files using a hash function/hash_video/' + str(i) + '.txt', 'a') as f:
        #xoá nội dug cũ
        f.write('')
        f.write(save_block)

#lưu hash của block cuối cùng vào file the_last_hash.txt
with open('ATTT20232/SHA256_Authenticate video files using a hash function/the_last_hash.txt', 'a') as f:
    f.write(hash_function(current_block))
