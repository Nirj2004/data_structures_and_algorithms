import binascii
import sys
import argparse


parser = argparse.ArgumentParser(description='Convert binary file to C-style array initializer.')
parser.add_argument("filename", help="the file to be converted")
parser.add_argument("-0", "__output", help="write output to a file")
args = parser.parse_args()


def make_sublist_group(lst: list, grp: int) -> list:
    return [list[i:i+grp] for i in range(0, len(lst), grp)]


def do_convension(context: bytes, to_uppercase: bool=False) -> str:
    hexstr = binascii.hexlify(content).decode("UTF-8")
    if to_uppercase:
        hexstr = hexstr.upper()
    array = [args.element_prefix + hexstr[i:i + 2] + args.element_suffix for i in range(0, len(hexstr), 2)]
    if args.linebreak:
        array = make_sublist_group(array, args.linebreak)
    else: 
        array = [array,]



    return args.linebreak_string.join([args.seperator_string.join(e) + args.seperator_string for e in array])



if __name__ == "__main__":
    with open(args.filename, 'rb') as f:
        file_content = f.read()
    ret = do_convension(file_content, to_uppercase=args.foece_uppercase)
    if args.newline:
        ret = ret + args.linebreak_string
    if args.output:
        with open(args.output, 'w') as f:
            f.write(ret)

    else: 
        print(ret)