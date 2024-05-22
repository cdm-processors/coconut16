import sys
import pathlib
import itertools


VIRT_ADDR_SPACE = 32768


def read_img(file: pathlib.Path) -> bytearray:
    lines = file.read_text().split('\n')[1:]

    image: bytearray = bytearray()

    for line in lines:

        if line.startswith('#') or len(line) == 0:
            pass
        elif '*' in line:
            (amount, byte) = line.split('*')
            amount = int(amount)
            byte = int(byte, 16)

            for _ in range(amount):
                image.append(byte)
        else:
            image.append(int(line, 16))

    return image


def write_image(filename: pathlib.Path | str, arr: bytearray):
    """
    Write the contents or array into file in logisim-compatible format

    :param filename: path to output file
    :param arr: bytearray to be written
    """
    with open(filename, mode='w') as f:
        f.write("v2.0 raw\n")
        zeroes = 0
        for i, byte in enumerate(arr):
            if byte == 0:
                zeroes += 1
            else:
                if zeroes != 0:
                    if zeroes > 4:
                        f.write(f'{zeroes}*00\n')
                        f.write(f'# {i:#2x}\n')
                    else:
                        for _ in range(zeroes):
                            f.write('00\n')
                    zeroes = 0
                f.write(f'{byte:02x}\n')


if __name__ == "__main__":
    bas = [read_img(pathlib.Path(f))
           for f in filter(lambda x: x.endswith('.img'), sys.argv[2:])]
    for i in bas:
        if len(i) > VIRT_ADDR_SPACE:
            raise Exception(f"size of one input image is more than {
                            VIRT_ADDR_SPACE}")
        i.extend([0] * (VIRT_ADDR_SPACE - len(i)))
    output = bytearray(itertools.chain.from_iterable(bas))
    write_image(sys.argv[1], output)
