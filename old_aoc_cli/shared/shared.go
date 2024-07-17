package shared

import (
	"fmt"
	"log"
	"os"
	"strconv"
)

func ProcessDay(lang string, year int, day int) {
	// first check if we have the year directory
	var err error
	yearAsString := strconv.Itoa(year)
	dayAsString := strconv.Itoa(day)

	_, err = os.Stat(yearAsString)

	if !os.IsExist(err) {
		// Does not exist we need to make it
		err := os.Mkdir(yearAsString, 0750)
		if err != nil && !os.IsExist(err) {
			log.Fatal(err)
			return
		}
	}

	// Move into directory
	err = os.Chdir(yearAsString)
	if err != nil && !os.IsExist(err) {
		log.Fatal(err)
		return
	}

	dayDirec := "day" + dayAsString
	_, err = os.Stat(dayDirec)
	if err == nil {
		fmt.Println(dayDirec + " already exists")
	} else {
		err := os.Mkdir(dayDirec, 0750)
		if err != nil && !os.IsExist(err) {
			log.Fatal(err)
			return
		}
	}

	err = os.Chdir(dayDirec)
	if err != nil && !os.IsExist(err) {
		log.Fatal(err)
		return
	}

	// Handle the global
	handleDayShared(year, day)

	_, err = os.Stat(lang)
	if err == nil {
		log.Fatal(lang + " already exists")
		return
	} else {
		err := os.Mkdir(lang, 0750)
		if err != nil && !os.IsExist(err) {
			log.Fatal(err)
			return
		}
	}

	err = os.Chdir(lang)
	if err != nil && !os.IsExist(err) {
		log.Fatal(err)
		return
	}

	handleLanguage(lang, year, day)
}
