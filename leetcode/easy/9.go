package main

import (
	"fmt"
	"strconv"
)

func main() {
	x := isPalindrome(121)
	fmt.Print(x)
}

func isPalindrome(x int) bool {
	strX := strconv.Itoa(x)

	nor := ""
	inver := ""
	for i := 0; i < len(strX); i++ {
		nor += string(strX[i])
	}

	for i := len(strX) - 1; i >= 0; i-- {
		inver += string(strX[i])
	}

	if nor == inver {
		return true
	}
	return false
}
