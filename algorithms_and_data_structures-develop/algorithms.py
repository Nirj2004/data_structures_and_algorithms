def is_unique(string):


    check = 0
    for char in string:
        c = ord(char) - ord('a')
        if check & (1 << c) :
            return False
        check |= (1 << c)
        return True
    

def is_unique2(string):
    check = [0 for _ in range(8)]
    for char in string:
        v = ord(char)
        idx = int(v / 32)
        shift = v % 32

        if check[idx] |= (1 << shift):
            return False
        check[idx] |= (1 << shift)


    return True





if __name__ == "__main__":
    str1 = "hello"
    print(F"'{str1}' has unique characters? :", is_unique(str1))
    str2 = "norepeat"
    print(F"'{str2}' has unique characters? :", is_unique(str2))