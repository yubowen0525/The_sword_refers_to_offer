package main

func findRepeatNumber(nums []int) int {
	i := 0
	for {
		if i >= len(nums) {
			break
		}

		if nums[i] == i {
			i++
			continue
		}

		if nums[nums[i]] == nums[i] {
			return nums[i]
		}

		tem := nums[nums[i]]
		nums[nums[i]] = nums[i]
		nums[i] = tem

		// nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
	}

	return -1
}

func main() {
	nums := []int{2, 3, 1, 0, 2, 5, 3}
	findRepeatNumber(nums)
}
