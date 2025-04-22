/* Raiz com busca binária; mudança na busca para evitar int overflow*/

package main

import "fmt"

func main() {
	x := 25
	sqrt := mySqrt(x)
	fmt.Print(sqrt)
}

func mySqrt(x int) int {
	if x < 2 {
		return x
	}

	e := 1
	d := x

	for e <= d {
		m := (e + d) / 2

		if x/m == m {
			return m
		}
		if x/m < m {
			d = m - 1
		}
		if x/m > m {
			e = m + 1
		}
	}
	return d
}
