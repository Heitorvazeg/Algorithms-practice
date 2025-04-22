package main

import "fmt"

func main() {
	digits := []int{1, 2, 9}
	d := plusOne(digits)
	fmt.Print(d)
}

func plusOne(digits []int) []int {
	if digits[len(digits)-1] == 9 {
		digits[len(digits)-1] = 0

		i := len(digits) - 2
		for i >= 0 && digits[i] == 9 {
			digits[i] = 0
			i--
		}
		if digits[0] == 0 {
			array := append([]int{1}, digits...)
			return array
		}
		digits[i] += 1

	} else {
		digits[len(digits)-1] += 1
	}
	return digits
}
