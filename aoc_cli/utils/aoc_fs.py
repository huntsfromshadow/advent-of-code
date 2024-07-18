from enum import Enum
import os
import click

class ExistenceResult(Enum):
    NO_YEAR = 1
    NO_DAY = 2
    NO_LANG = 3
    EXIST = 4


def figure_existence(year: int, day: int, lang: str) -> ExistenceResult:
    # Check year first
    if not os.path.isdir(str(year)):
        return ExistenceResult.NO_YEAR
    
    # Check day
    if not os.path.isdir(str(year) + "/" + str(day)):
        return ExistenceResult.NO_DAY
    
    # Check Lang
    if not os.path.isdir(str(year) + "/" + str(day) + "/" + str(lang)):
        return ExistenceResult.NO_LANG
    
    return ExistenceResult.EXIST


def handle_direcs(year: int, day: int, lang: str):
    eres = figure_existence(year, day, lang)
    match eres:
        case ExistenceResult.EXIST:
            click.echo("Already Exists")
        case _:
            pth = f'{str(year)}/{str(day)}/{lang}'
            os.makedirs(pth)

      
def save_input(input_text: str, year: int, day: int):
    f = open(f'{str(year)}/{str(day)}/input.txt', 'w')
    f.write(input_text)
    f.close()


def create_test_file(year: int, day: int):
    if not os.path.exists(f'{str(year)}/{str(day)}/test.txt'):
        f = open(f'{str(year)}/{str(day)}/test.txt', 'w')
        f.write("Replace me")
        f.close()
    else:
        click.echo('test file already exists')
