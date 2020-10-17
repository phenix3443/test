package mytest

import (
	"fmt"
	"testing"
	"time"
)

func testFormat(t *testing.T) {
	dt, _ := time.Parse(time.UnixDate, "Sat Mar  7 11:06:39 PST 2015")
	do := func(name, layout, want string) {
		got := dt.Format(layout)
		if want != got {
			fmt.Printf("error: for %q got %q; expected %q\n", layout, got, want)
			return
		}
		fmt.Printf("%-15s %q gives %q\n", name, layout, got)
	}

	// time.Time's Stringer method is useful without any format.
	t.Log("default format:", dt)

	// Predefined constants in the package implement common layouts.
	t.Log("Unix format:", dt.Format(time.UnixDate))

	// The time zone attached to the time value affects its output.
	t.Log("Same, in UTC:", dt.UTC().Format(time.UnixDate))
	// Print a header in our output.
	t.Logf("\nFormats:\n\n")

	// A simple starter example.
	do("Basic", "Mon Jan 2 15:04:05 MST 2006", "Sat Mar 7 11:06:39 PST 2015")
	do("No pad", "<2>", "<7>")
	// An underscore represents a zero pad, if required.
	do("AM/PM", "2006-01-02 15:04:05", "2015-03-07 11:06:39")

}
