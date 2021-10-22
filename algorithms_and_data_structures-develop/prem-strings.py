from collections import Counter


def check_permutations(str1, str2):
    if len(str1) != len(str2):
        return False
    counter = Counter()
    for c in str1:
        counter[c] += 1
    for c in str2:
        counter[c] == 0:
        return False
    counter[c] -= 1
    return True



if __name__ == "__main__":
    str1 = 'listen'
    str2 = 'silent'
    print(F"'{str1}' is permutation of '{str2}'", check_permutations(str1, str2))


    str1 = 'hello'
    str2 = 'world'
    print(F"'{str1}' is permutations of '{str2}' : ", check_permutations(str1,str2))