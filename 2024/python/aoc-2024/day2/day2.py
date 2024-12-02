def check_level(leveldat) -> bool:
    b1 = check_inc_dec(leveldat)
    b2 = check_change(leveldat)

    return b1 and b2

def check_change(leveldat):
    previous = None
    for e in leveldat:
        if previous is None:
            previous = e
            continue

        if abs(previous - e) == 1 or abs(previous - e) == 2 or abs(previous - e) == 3:
            previous = e
            continue
        else:
            print(f"Jump by {abs(previous - e)} - Fail")
            return False

    return True

def check_inc_dec(leveldat) -> bool:
    previous = None
    incdec = None

    for e in leveldat:
        if previous is None:
            previous = e
            continue

        if incdec is None:
            if e > previous:
                incdec = "increasing"
                previous = e
            elif e < previous:
                incdec = "decreasing"
                previous = e
            else:
                print("Two values same. - Fail")
                return False
        else:
            if e > previous and incdec == "decreasing":
                print("Move from increasing to decreasing - Fail")
                return False
            if e < previous and incdec == "increasing":
                print("Move from decreasing to increasing - Fail")
                return False
            if e == previous:
                print("Two values same. - Fail")
                return False

            previous = e
    return True



def day2():
    input = []

    with open("day2-input.txt") as f:
        dat = f.read()
        lines = dat.splitlines()

        for l in lines:
            elems = l.split(" ")
            input.append(
                list(map(lambda x: int(x), elems)))

    final = []
    for level in input:
        res = check_level(level)
        final.append(res)

    print(final)

    print("\n")
    print( final.count(True) )


if __name__ == '__main__':
    day2()