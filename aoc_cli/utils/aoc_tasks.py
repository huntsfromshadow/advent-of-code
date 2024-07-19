from .aoc_fs import handle_direcs, save_input, create_test_file
from .aoc_client import get_aoc_input
import os
import click


def setup_day(year: int, day: int, lang: str):
    # First figure existance
    handle_direcs(year, day, lang)
    input_text = get_aoc_input(year, day)

    create_test_file(year, day)
    if day < 10:
        pad = f'0{day}'
    else:
        pad = f'{day}'
    if not os.path.isfile(f"{year}/{day}/input{pad}.txt"):
        save_input(input_text, year, day)
    else:
        click.echo("Input file already exists")

def submit_answer(year: int, day: int, answer: str):
    pass
