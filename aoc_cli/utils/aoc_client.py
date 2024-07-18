import requests


def get_aoc_input(year: int, day: int) -> str:
    global config
    print(config['DEFAULT']['SessionToken'])

    cookies = dict(session=SESSION_TOKEN)
    r = requests.get(
        f'https://adventofcode.com/{str(year)}/day/{str(day)}/input',
        cookies=cookies
    )
    return r.text
