import requests
from utils.config import CONFIG

def get_aoc_input(year: int, day: int) -> str:
    token = CONFIG["SessionCookie"]

    cookies = dict(session=token)
    r = requests.get(
        f'https://adventofcode.com/{str(year)}/day/{str(day)}/input',
        cookies=cookies
    )
    return r.text
