from utils.aoc_tasks import setup_day
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

if __name__ == '__main__':
    cli()
