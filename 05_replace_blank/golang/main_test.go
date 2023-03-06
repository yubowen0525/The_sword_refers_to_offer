package main

import "testing"

func TestDuplicate(t *testing.T) {

	input_parameter1_case := map[string]string{
		"case1": "We Are Happy",
		"case2": " ",
	}

	output_case := map[string]string{
		"case1": "We%20Are%20Happy",
		"case2": "%20",
	}

	for caseName, inputCase := range input_parameter1_case {
		t.Run(caseName, func(t *testing.T) {
			output := ReplaceSpace(inputCase)
			if output != output_case[caseName] {
				t.Errorf("output:%s != case output %s", output, output_case[caseName])
			}
		})
	}
}
