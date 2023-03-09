package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	hashmap := make(map[int]int) //value to index in array
	for i, val := range nums {
		complement := target - nums[i]
		compIndex, exists := hashmap[complement]
		if exists {
			return []int{i, compIndex}
		}

		hashmap[val] = i

	}
	return []int{0, 0}
}

func main() {
	input := []int{134, 2, 3, 456765, 5}
	target := 5
	fmt.Println(twoSum(input, target))
}
