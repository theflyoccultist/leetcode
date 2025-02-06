package main

func tupleSameProduct(nums []int) int {
	gobsemMap := make(map[int]int)
	result := 0

	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			gobsem := nums[i] * nums[j]

			if count, found := gobsemMap[gobsem]; found {
				result += count * 8
			}
			gobsemMap[gobsem]++
		}
	}
	return result
}
