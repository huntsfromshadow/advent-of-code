import requests
from utils.config import CONFIG


def get_aoc_input(year: int, day: int) -> str:
    token = CONFIG["SessionCookie"]

    cookies = dict(session=token)
    r = requests.get(
        f"https://adventofcode.com/{str(year)}/day/{str(day)}/input", cookies=cookies
    )
    return r.text


def post_answer(year: int, day: int, answer: str, level: int):
    url = f"https://adventofcode.com/{year}/day/{day}/answer"
    headers = {
        "Cookie": f'session={CONFIG["SessionCookie"]}',
        "cache-control": "no-cache",
        "Content-Type": "application/x-www-form-urlencoded",
    }
    body = {"level": level, "answer": answer}
    r = requests.post(url, headers=headers, data=body)
    if r.text.find("That's not the right answer.") != -1:
        print("Incorrect Answer")
    elif r.text.find('You gave an answer too recently') != -1:
        print('Still in Timeout')
        s = r.text.find('You have')
        e = r.text.find('left to wait.')

        timeout = r.text[s:e] + r.text[e:e+len('left to wait.')]
        print(timeout)
    else:
        print("yea!")
        print(r.text)
