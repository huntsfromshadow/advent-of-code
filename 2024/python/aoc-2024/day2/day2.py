def check_level(leveldat) -> bool:
    b1 = check_inc_dec(leveldat)
    b2 = check_change(leveldat)

    return b1 and b2

def check_change(leveldat):
    previous = None
    absorbed = False

    for e in leveldat:
        if previous is None:
            previous = e
            continue

        if abs(previous - e) == 1 or abs(previous - e) == 2 or abs(previous - e) == 3:
            previous = e
            continue
        else:
            if absorbed:
                print(f"Jump by {abs(previous - e)} - Fail")
                return False
            else:
                print(f"Jump by {abs(previous - e)} - Absorbing")
                absorbed = True
                continue

    return True

def check_inc_dec(leveldat) -> bool:
    previous = None
    incdec = None
    absorbed_level = False

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
                if absorbed_level:
                    print("Two values same. - Fail")
                    return False
                else:
                    print("Two values same. - Absorbing")
                    absorbed_level = True
                    previous = e
                    continue
        else:
            if e > previous and incdec == "decreasing":
                if absorbed_level:
                    print("Move from increasing to decreasing - Fail")
                    return False
                else:
                    print("Move from increase to decrease - absorbing")
                    absorbed_level = True
                    continue

            if e < previous and incdec == "increasing":
                if absorbed_level:
                    print("Move from decreasing to increasing - Fail")
                    return False
                else:
                    print("Move from decreasing to increasing - Absorbing")
                    absorbed_level = True
                    continue

            if e == previous:
                if absorbed_level:
                    print("Two values same. - Fail")
                    return False
                else:
                    print("Two values same. - Absorbing")
                    absorbed_level = True
                    continue

            previous = e
    return True



def day2():
    input = []

    with open("edge-cases.txt") as f:
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