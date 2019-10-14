package store

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLiteStore_GetAll(t *testing.T) {
	st := NewLiteStore()
	err := st.Store("winjeg", "/static")
	assert.Nil(t, err)
	assert.True(t, st.Exists("/static"))
	r := st.GetAll()
	assert.NotNil(t, r)
}
