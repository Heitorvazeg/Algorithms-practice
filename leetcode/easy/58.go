package main

import (
	"fmt"
	"strings"
)

func main() {
	string := "luffy is still joyboy"
	s := lengthOfLastWord(string)
	fmt.Print(s)
}

func lengthOfLastWord(s string) int {
	slice := strings.Fields(s)
	s = strings.Join(slice, " ")
	array := strings.Split(s, " ")
	lenLast := len(array[len(array)-1])
	return lenLast
}
