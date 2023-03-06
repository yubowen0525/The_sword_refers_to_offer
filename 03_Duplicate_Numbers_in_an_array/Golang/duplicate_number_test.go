package main

import "testing"

func TestDuplicate(t *testing.T) {
	input_case := map[string][]int{
		"normal": {2, 3, 1, 0, 2, 5, 3},
	}

	output_case := map[string]int{
		"normal": 2,
	}
	for caseName, inputCase := range input_case {
		t.Run(caseName, func(t *testing.T) {
			output := FindRepeatNumber(inputCase)
			if output != output_case[caseName] {
				t.Errorf("output:%d != case output %d", output, output_case[caseName])
			}
		})
	}
}
