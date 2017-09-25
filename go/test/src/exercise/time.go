package main

import (
	"fmt"
	"time"
)

func timeFormat() {
	t, _ := time.Parse(time.UnixDate, "Sat Mar  7 11:06:39 PST 2015")
	do := func(name, layout, want string) {
		got := t.Format(layout)
		if want != got {
			fmt.Printf("error: for %q got %q; expected %q\n", layout, got, want)
			return
		}
		fmt.Printf("%-15s %q gives %q\n", name, layout, got)
	}

	// Print a header in our output.
	fmt.Printf("\nFormats:\n\n")

	// A simple starter example.
	do("Basic", "Mon Jan 2 15:04:05 MST 2006", "Sat Mar 7 11:06:39 PST 2015")
	do("No pad", "<2>", "<7>")
}
