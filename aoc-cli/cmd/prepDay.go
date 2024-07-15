/*
Copyright © 2024 NAME HERE <EMAIL ADDRESS>
*/
package cmd

import (
	"errors"
	"fmt"
	"strconv"

	"github.com/huntsfromshadow/advent-of-code/aoc-cli/shared"
	"github.com/spf13/cobra"
)

// prepDayCmd represents the prepDay command
var prepDayCmd = &cobra.Command{
	Use:   "prepDay",
	Short: "Pulls down the day's challenge",
	Long:  `Pulls down the day's challenge`,
	Run: func(cmd *cobra.Command, args []string) {
		langflag, _ := cmd.Flags().GetString("language")
		yearflag, _ := cmd.Flags().GetInt16("year")

		// Check the number of args
		if len(args) == 0 {
			err := errors.New("MUST HAVE DAY ARGUMENT")
			fmt.Print(err)
			return
		}

		dayAsInt, err := strconv.Atoi(args[0])
		if err != nil {
			fmt.Println("Just put in the number of the day")
			return
		} else {
			shared.ProcessDay(langflag, int(yearflag), dayAsInt)
		}
	},
}

func init() {
	rootCmd.AddCommand(prepDayCmd)
	prepDayCmd.Flags().StringP("language", "l", "python", "Language to use")
	prepDayCmd.Flags().Int16P("year", "y", 2021, "Year to load the puzzle from")
}
