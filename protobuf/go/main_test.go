package tutorial

import (
	"testing"
)

func TestValid(t *testing.T) {
	pn := Person_PhoneNumber{}

	t.Logf("%v", pn.Validate())
}
