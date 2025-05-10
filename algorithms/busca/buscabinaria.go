/* Algoritmo de busca; divide ao meio e vê se é igual ao target; altera quando for menor
ou maior; não precisa percorrer todo o array, mais rápido*/

package main

func main() {
}

func BuscaBinária(nums []int, target int) int {
	e := 0
	d := len(nums) - 1

	for e <= d {
		m := (e + d) / 2

		if nums[m] == target {
			return m
		}
		if nums[m] > target {
			d = m - 1
		}
		if nums[m] < target {
			e = m + 1
		}
	}
	return -1
}
