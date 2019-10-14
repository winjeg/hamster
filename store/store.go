package store

type Site struct {
	Id      *int64  `json:"id"`
	Author  *string `json:"author"`
	Mapping *string `json:"mapping"`
	Created *int64  `json:"created"`
	Updated *int64  `json:"updated"`
	Time    *string `json:"time"`
}

type SiteStore interface {
	Store(author, path string) error
	Exists(...string) bool
	GetAll() []Site
}
