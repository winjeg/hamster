package store

import (
	"database/sql"
	"time"
)

const (
	addSitesSql  = `INSERT INTO sites(author, mapping, created, updated) VALUES(?, ?, ?, ?)`
	checkSiteSql = `SELECT COUNT(*) FROM sites WHERE dir = ? or mapping = ?`
	getAllSql    = `SELECT id, author, mapping, created, updated FROM sites`
)

// you can implement other stores if you want it
func NewLiteStore() *LiteStore {
	return &LiteStore{LiteDB: GetDb()}
}

type LiteStore struct {
	LiteDB *sql.DB
}

func (ls *LiteStore) Store(author, path string) error {
	now := time.Now().UnixNano() / int64(time.Second)
	_, err := ls.LiteDB.Exec(addSitesSql, author, path, now, now)
	return err
}

func (ls *LiteStore) Exists(s ...string) bool {
	for _, v := range s {
		var num int
		row := ls.LiteDB.QueryRow(checkSiteSql, v, v)
		err := row.Scan(&num)
		if err != nil || num != 0 {
			return true
		}
	}
	return false
}
func (ls *LiteStore) GetAll() []Site {
	rows, err := ls.LiteDB.Query(getAllSql)
	if err != nil {
		return nil
	}
	result := make([]Site, 0, 16)
	for rows.Next() {
		var site Site
		err := rows.Scan(&site.Id, &site.Author, &site.Mapping, &site.Created, &site.Updated)
		if err != nil {
			continue
		}
		t := time.Unix(*site.Created, 0).Format("2006/1/2 15:04:05")
		site.Time = &t
		result = append(result, site)
	}
	return result
}
