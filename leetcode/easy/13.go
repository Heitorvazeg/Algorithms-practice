package main

import "fmt"

func main() {
	str := "MCMXCIV"
	valor := romanToInt(str)
	fmt.Print(valor)
}

func romanToInt(s string) int {
	romamValues := map[rune]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	soma := 0
	acc := 10000

	for _, value := range s {
		if romamValues[value] <= acc {
			soma += romamValues[value]
		}
		if romamValues[value] > acc {
			valor := romamValues[value] - 2*acc
			soma += valor
		}
		acc = romamValues[value]
	}
	return soma
}
