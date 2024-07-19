import click

def create_template(path: str, lang: str, data):
    match lang:
        case 'python':
            process_files(path, python, data)
        case _:
            click.echo("Lang ${lang} does not have a template")


def process_files(path: str, template_list: list[tuple[str,str]], data):
    for fd in template_list:
        newfname = handle_tags(fd[0], data)
        newftxt = handle_tags(fd[1], data)
        f = open(path + f'/{newfname}', 'w')
        f.write(newftxt)
        f.close()


def handle_tags(strin: str, data) -> str:
    # We only support certain tags
    retval = strin
    retval = retval.replace("{day}", data['day'])
    return retval

# Templates below.
#  Each tuple is file to place
#  Supported Interpolations {day}

python = [
    ('day{day}.py', """
import argparse

def day{day}_process(input_data: str):
    # Code Implmentation Here
    print(input_data)
    pass

#################
# Boiler Plate
def get_input(file_name: str) -> str:
    f = open(file_name)
    return f.read()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='AOC Day {day}')
    parser.add_argument('input_file', type=str, help='Data File to Process')
    args = parser.parse_args()
    
    data = get_input(args.input_file)
    day{day}_process(data)""")
]


