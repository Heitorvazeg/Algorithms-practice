package main

import "fmt"

func main() {
	slice := []int{3, 2, 3}
	a := twoSum(slice, 6)
	fmt.Print(a)
}

func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return []int{-1, -1}
}
