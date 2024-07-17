package shared

import (
	"bufio"
	"io"
	"log"
	"net/http"
	"os"
	"regexp"
	"strconv"

	md "github.com/JohannesKaufmann/html-to-markdown"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func handleDayShared(year int, day int) {
	// We know we are in the right direc
	// Does the day instructions exist?
	dayInst := "day" + strconv.Itoa(day) + ".md"
	_, err := os.Stat(dayInst)
	if err != nil {
		mdDat := grabInstructions(year, day)

		f, err := os.Create(dayInst)
		check(err)
		defer f.Close()

		w := bufio.NewWriter(f)
		_, err2 := w.WriteString(mdDat)
		check(err2)
		w.Flush()
	}

	dayInput := "input.txt"
	_, err3 := os.Stat(dayInput)
	if err3 != nil {
		txtDat := grabInput(year, day)

		f, err := os.Create(dayInput)
		check(err)
		defer f.Close()

		w := bufio.NewWriter(f)
		_, err2 := w.WriteString(txtDat)
		check(err2)
		w.Flush()
	}
}

func grabInput(yearNumber int, dayNumber int) string {
	linkTxt := "https://adventofcode.com/" +
		strconv.Itoa(yearNumber) + "/day/" +
		strconv.Itoa(dayNumber) + "/input"

	res, err := http.Get(linkTxt)
	if err != nil {
		log.Fatal(err)
	}
	content, err := io.ReadAll(res.Body)
	res.Body.Close()
	if err != nil {
		log.Fatal(err)
	}
	return string(content)
}

func grabInstructions(yearNumber int, dayNumber int) string {
	linkTxt := "https://adventofcode.com/" +
		strconv.Itoa(yearNumber) + "/day/" +
		strconv.Itoa(dayNumber)

	res, err := http.Get(linkTxt)
	if err != nil {
		log.Fatal(err)
	}
	content, err := io.ReadAll(res.Body)
	res.Body.Close()
	if err != nil {
		log.Fatal(err)
	}

	var re = regexp.MustCompile(`(?ms)<article.*>(.*)</article>`)
	match := re.FindStringSubmatch(string(content))

	converter := md.NewConverter("", true, nil)
	html := match[0]
	markdown, err := converter.ConvertString(html)
	if err != nil {
		log.Fatal(err)
	}
	return markdown

}
