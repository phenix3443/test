// Code generated by protoc-gen-validate. DO NOT EDIT.
// source: addressbook.proto

package tutorial

import (
	"bytes"
	"errors"
	"fmt"
	"net"
	"net/mail"
	"net/url"
	"regexp"
	"strings"
	"time"
	"unicode/utf8"

	"github.com/golang/protobuf/ptypes"
)

// ensure the imports are used
var (
	_ = bytes.MinRead
	_ = errors.New("")
	_ = fmt.Print
	_ = utf8.UTFMax
	_ = (*regexp.Regexp)(nil)
	_ = (*strings.Reader)(nil)
	_ = net.IPv4len
	_ = time.Duration(0)
	_ = (*url.URL)(nil)
	_ = (*mail.Address)(nil)
	_ = ptypes.DynamicAny{}
)

// define the regex for a UUID once up-front
var _addressbook_uuidPattern = regexp.MustCompile("^[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}$")

// Validate checks the field values on Person with the rules defined in the
// proto definition for this message. If any rules are violated, an error is returned.
func (m *Person) Validate() error {
	if m == nil {
		return nil
	}

	// no validation rules for Name

	if val := m.GetId(); val <= 0 || val >= 10 {
		return PersonValidationError{
			field:  "Id",
			reason: "value must be inside range (0, 10)",
		}
	}

	// no validation rules for Email

	if v, ok := interface{}(m.GetPhones()).(interface{ Validate() error }); ok {
		if err := v.Validate(); err != nil {
			return PersonValidationError{
				field:  "Phones",
				reason: "embedded message failed validation",
				cause:  err,
			}
		}
	}

	if v, ok := interface{}(m.GetLastUpdated()).(interface{ Validate() error }); ok {
		if err := v.Validate(); err != nil {
			return PersonValidationError{
				field:  "LastUpdated",
				reason: "embedded message failed validation",
				cause:  err,
			}
		}
	}

	return nil
}

// PersonValidationError is the validation error returned by Person.Validate if
// the designated constraints aren't met.
type PersonValidationError struct {
	field  string
	reason string
	cause  error
	key    bool
}

// Field function returns field value.
func (e PersonValidationError) Field() string { return e.field }

// Reason function returns reason value.
func (e PersonValidationError) Reason() string { return e.reason }

// Cause function returns cause value.
func (e PersonValidationError) Cause() error { return e.cause }

// Key function returns key value.
func (e PersonValidationError) Key() bool { return e.key }

// ErrorName returns error name.
func (e PersonValidationError) ErrorName() string { return "PersonValidationError" }

// Error satisfies the builtin error interface
func (e PersonValidationError) Error() string {
	cause := ""
	if e.cause != nil {
		cause = fmt.Sprintf(" | caused by: %v", e.cause)
	}

	key := ""
	if e.key {
		key = "key for "
	}

	return fmt.Sprintf(
		"invalid %sPerson.%s: %s%s",
		key,
		e.field,
		e.reason,
		cause)
}

var _ error = PersonValidationError{}

var _ interface {
	Field() string
	Reason() string
	Key() bool
	Cause() error
	ErrorName() string
} = PersonValidationError{}

// Validate checks the field values on AddressBook with the rules defined in
// the proto definition for this message. If any rules are violated, an error
// is returned.
func (m *AddressBook) Validate() error {
	if m == nil {
		return nil
	}

	for idx, item := range m.GetPeople() {
		_, _ = idx, item

		if v, ok := interface{}(item).(interface{ Validate() error }); ok {
			if err := v.Validate(); err != nil {
				return AddressBookValidationError{
					field:  fmt.Sprintf("People[%v]", idx),
					reason: "embedded message failed validation",
					cause:  err,
				}
			}
		}

	}

	return nil
}

// AddressBookValidationError is the validation error returned by
// AddressBook.Validate if the designated constraints aren't met.
type AddressBookValidationError struct {
	field  string
	reason string
	cause  error
	key    bool
}

// Field function returns field value.
func (e AddressBookValidationError) Field() string { return e.field }

// Reason function returns reason value.
func (e AddressBookValidationError) Reason() string { return e.reason }

// Cause function returns cause value.
func (e AddressBookValidationError) Cause() error { return e.cause }

// Key function returns key value.
func (e AddressBookValidationError) Key() bool { return e.key }

// ErrorName returns error name.
func (e AddressBookValidationError) ErrorName() string { return "AddressBookValidationError" }

// Error satisfies the builtin error interface
func (e AddressBookValidationError) Error() string {
	cause := ""
	if e.cause != nil {
		cause = fmt.Sprintf(" | caused by: %v", e.cause)
	}

	key := ""
	if e.key {
		key = "key for "
	}

	return fmt.Sprintf(
		"invalid %sAddressBook.%s: %s%s",
		key,
		e.field,
		e.reason,
		cause)
}

var _ error = AddressBookValidationError{}

var _ interface {
	Field() string
	Reason() string
	Key() bool
	Cause() error
	ErrorName() string
} = AddressBookValidationError{}

// Validate checks the field values on Person_PhoneNumber with the rules
// defined in the proto definition for this message. If any rules are
// violated, an error is returned.
func (m *Person_PhoneNumber) Validate() error {
	if m == nil {
		return nil
	}

	// no validation rules for Number

	// no validation rules for Type

	return nil
}

// Person_PhoneNumberValidationError is the validation error returned by
// Person_PhoneNumber.Validate if the designated constraints aren't met.
type Person_PhoneNumberValidationError struct {
	field  string
	reason string
	cause  error
	key    bool
}

// Field function returns field value.
func (e Person_PhoneNumberValidationError) Field() string { return e.field }

// Reason function returns reason value.
func (e Person_PhoneNumberValidationError) Reason() string { return e.reason }

// Cause function returns cause value.
func (e Person_PhoneNumberValidationError) Cause() error { return e.cause }

// Key function returns key value.
func (e Person_PhoneNumberValidationError) Key() bool { return e.key }

// ErrorName returns error name.
func (e Person_PhoneNumberValidationError) ErrorName() string {
	return "Person_PhoneNumberValidationError"
}

// Error satisfies the builtin error interface
func (e Person_PhoneNumberValidationError) Error() string {
	cause := ""
	if e.cause != nil {
		cause = fmt.Sprintf(" | caused by: %v", e.cause)
	}

	key := ""
	if e.key {
		key = "key for "
	}

	return fmt.Sprintf(
		"invalid %sPerson_PhoneNumber.%s: %s%s",
		key,
		e.field,
		e.reason,
		cause)
}

var _ error = Person_PhoneNumberValidationError{}

var _ interface {
	Field() string
	Reason() string
	Key() bool
	Cause() error
	ErrorName() string
} = Person_PhoneNumberValidationError{}
