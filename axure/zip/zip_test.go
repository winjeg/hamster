package zip

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestZip(t *testing.T) {
	err := Unzip("../uploads/a.zip", "/abc")
	assert.Nil(t, err)
}
