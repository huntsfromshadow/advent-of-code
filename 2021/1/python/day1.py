
import argparse

def day1_process(input_data: str):
    lines = input_data.splitlines()

    numinc = 0
    lastval = lines.pop(0)

    for d in lines:
        if d > lastval:
            numinc = numinc + 1
            print("\tincrease")
        else:
            print("decrease")

        lastval = d    

    print(f"\nFinal Inc Count: {numinc}")
        

#################
# Boiler Plate
def get_input(file_name: str) -> str:
    f = open(file_name)
    return f.read()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='AOC Day 1')
    parser.add_argument('input_file', type=str, help='Data File to Process')
    args = parser.parse_args()
    
    data = get_input(args.input_file)
    day1_process(data)