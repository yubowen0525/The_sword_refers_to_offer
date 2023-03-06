package main

import "testing"

func TestDuplicate(t *testing.T) {

	input_parameter1_case := map[string][]int{
		"case1": {1, 2, 3},
		"case2": {67, 0, 24, 58},
	}

	output_case := map[string][]int{
		"case1": {3, 2, 1},
		"case2": {58, 24, 0, 67},
	}

	for caseName, inputCase := range input_parameter1_case {
		t.Run(caseName, func(t *testing.T) {
			intput := NewList(inputCase)
			output := PrintListFromTailToHead(intput)
			if !IsEqualList(output, output_case[caseName]) {
				t.Errorf("output:%+v != case output %+v", output, output_case[caseName])
			}
		})
	}
}

func IsEqualList(list1, list2 []int) bool {

	if len(list1) != len(list2) {
		return false
	}

	for i := 0; i < len(list1); i++ {
		if list1[i] != list2[i] {
			return false
		}
	}

	return true
}
