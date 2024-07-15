package shared

import "fmt"

func handleLanguage(lang string, yearNumber int, dayNumber int) {
	switch lang {
	case "python":
		handlePython(yearNumber, dayNumber)
	default:
		fmt.Println("Unsupported Language")
		return
	}
}

func handlePython(yearNumber int, dayNumber int) {
	grabInstructions(yearNumber, dayNumber)
}
