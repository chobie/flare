/**
 *  storage_sqlite3.h
 *
 *  @author Daniel Perez <tuvistavie@hotmail.com>
 *
 *  $Id$
 */
#ifndef __STORAGE_SQLITE3_H__
#define __STORAGE_SQLITE3_H__

#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#endif // HAVE_STDLIB_H

#ifdef HAVE_STDINT_H
# include <stdint.h>
#endif // HAVE_STDINT_H

#include "storage.h"
#include "sqlite3.h"

using namespace std;

namespace gree {
namespace flare {

/**
 *  storage class
 */
class storage_sqlite3 : public storage {
protected:
	static const type					_type = storage::type_sqlite3;

	string							  		_data_path;
	sqlite3* _db;
//	kyotocabinet::DB::Cursor*	_cursor;
//	kyotocabinet::LZOCompressor<kyotocabinet::LZO::RAW> _comp;

	virtual int _get_header(string key, entry &e);

public:
	storage_sqlite3(string data_dir, int mutex_slot_size, uint32_t storage_ap, uint64_t storage_bucket_size, int storage_cache_size, string storage_compess, bool storage_large, int32_t storage_dfunit);
	virtual ~storage_sqlite3();

	virtual int open();
	virtual int close();
	virtual int set(entry &e, result &r, int b = 0);
	virtual int incr(entry &e, uint64_t value, result &r, bool increment, int b = 0);
	virtual int get(entry &e, result &r, int b = 0);
	virtual int remove(entry &e, result &r, int b = 0);
	virtual int truncate(int b = 0);
	virtual int iter_begin();
	virtual iteration iter_next(string &key);
	virtual int iter_end();
	virtual uint32_t count();
	virtual uint64_t size();

	virtual type get_type() {
		return this->_type;
	};
	virtual bool is_capable(capability c);

private:
	bool _iter_first;
};

}   // namespace flare
}   // namespace gree

#endif  // __STORAGE_SQLITE3_H__
// vim: foldmethod=marker tabstop=2 shiftwidth=2 autoindent