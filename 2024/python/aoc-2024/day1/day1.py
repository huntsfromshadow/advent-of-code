
def day1():
    s1 = []
    s2 = []

    with open('day1-input.txt') as f:
        lines = f.read().splitlines()

        for l in lines:
            z = l.split(" ")
            s1.append(int(z[0]))
            s2.append(int(z[3]))

        s1.sort()
        s2.sort()

    sims = []

    for i in range(len(s1)):
        lv = s1[i]
        cnt = s2.count(lv)
        sims.append(lv * cnt)

    print( sum(sims))




if __name__ == "__main__":
    day1()