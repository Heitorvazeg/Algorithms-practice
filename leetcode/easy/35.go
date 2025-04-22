package main

import "fmt"

func main() {
	nums := []int{1, 3, 5, 6}

	x := searchInsert(nums, 2)
	fmt.Print(x)
}

func searchInsert(nums []int, target int) int {
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
	return e
}
