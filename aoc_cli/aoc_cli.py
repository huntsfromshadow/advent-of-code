from utils.aoc_tasks import setup_day, submit_answer
from utils.aoc_client import post_answer
import click
from utils.config import CONFIG

@click.group()
def cli():
    click.echo("\n")

@cli.command()
@click.argument('year')
@click.argument('day')
@click.argument('lang')
def setup(year, day, lang):
    click.echo(f'Setting Up Day\nYear: {year} Day: {day} Lang: {lang}')
    setup_day(year, day, lang)
    click.echo("\n")

@cli.command()
def status():
    pass

@cli.command()
@click.argument('year')
@click.argument('day')
@click.argument('answer')
def submit(year, day, answer):
    click.echo(f'Submitting Answer\nYear: {year} Day: {day} Answer: {answer}')
    #submit_answer(year, day, answer)
    post_answer(year, day, answer)

if __name__ == '__main__':
    cli()

