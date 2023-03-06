package main

import "testing"

func TestDuplicate(t *testing.T) {

	input_parameter1_case := map[string]int{
		"normal": 7}

	input_parameter2_case := map[string][][]int{
		"normal": {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}}}

	output_case := map[string]bool{
		"normal": true,
	}

	for caseName, inputCase := range input_parameter1_case {
		t.Run(caseName, func(t *testing.T) {
			output := Find(inputCase, input_parameter2_case[caseName])
			if output != output_case[caseName] {
				t.Errorf("output:%t != case output %t", output, output_case[caseName])
			}
		})
	}
}
