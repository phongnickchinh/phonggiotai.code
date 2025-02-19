import gmpy2
from gmpy2 import mpz, isqrt, ceil, invert, powmod
import binascii

def find_modulo(N):
    N = mpz(N)
    A = isqrt(N)
    x2 = A * A - N

    print(f"A: {A}")
    print(f"x2: {x2}")

    # Kiểm tra và xử lý nếu x2 là số âm
    if x2 < 0:
        raise ValueError("Cannot compute the square root of a negative number")
    
    x = isqrt(x2)
    
    p = A - x
    q = A + x
    
    return (p - 1) * (q - 1)

def hex_string_to_ascii(hex_str):
    if len(hex_str) % 2 != 0:
        print("Invalid hex string.")
        return
    
    ascii_str = binascii.unhexlify(hex_str).decode('ascii', errors='ignore')
    print("Plaintext (hexa) =", hex_str)
    print("ASCII =", ascii_str)

def find_plaintext(m):
    s = m.digits(16)
    print("Plaintext with padding (hexa) =", s)
    
    # Find the position of '00'
    pos = s.find('00')
    if pos != -1:
        hex_str = s[pos + 2:]
        hex_string_to_ascii(hex_str)

# Số N cần giải mã
N = ("179769313486231590772930519078902473361797697894230657273430081157732675805"
        "50562068698537944921298295958550138753716401571013985864783377860692558349754108519659161512805"
        "75759407526350074759352887108236499499407718956170543611494748650467110151015639406805275400715"
        "84560878577663743040086340742855278549092581")

# Số c (bản mã)
c = ("22096451867410381776306561134883418017410069787892831071731839143676135600120"
        "53800428232965047350942434394621975151225646583996794288946076454204058156474"
        "89880137348641204523252293201764879166664029975091887299716905260832220677716"
        "00019329260870009579993724077458967773697817571267229951148662959627934791540")

# Chuyển đổi N và c sang kiểu mpz
N = mpz(N)
c = mpz(c)

# Tìm mô-đun (phi N)
modulo = find_modulo(N)

# Khóa công khai e
e = mpz(65537)

# Tìm khóa bí mật d
d = invert(e, modulo)

# Giải mã bản mã
m = powmod(c, d, N)

# Tìm văn bản ASCII từ kết quả giải mã
find_plaintext(m)
