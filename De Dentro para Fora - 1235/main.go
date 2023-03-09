package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	numLines, _ := reader.ReadString('\n')
	numLines = numLines[:len(numLines)-1]

	numLinesInt, _ := strconv.Atoi(numLines)

	for i := 0; i <= numLinesInt; i++ {
		if i == 0 {
			continue
		}

		line, _ := reader.ReadString('\n')
		line = line[:len(line)-1]

		half := len(line) / 2

		var first string
		var second string

		for idx, ch := range line {
			if idx < half {
				first = string(ch) + first
			} else {
				second = string(ch) + second
			}
		}

		fmt.Println(first + second)
	}

}
