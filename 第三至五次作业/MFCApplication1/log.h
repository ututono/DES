#pragma once
#include"stdafx.h"
#include"targetver.h"

template <class Elem = char, class Tr = std::char_traits<Elem>>
class StandardOutputRedirector : public std::basic_streambuf<Elem, Tr> {
	typedef void(*cb_func_ptr)(const Elem*, std::streamsize count, void* data);
	//typedef void(*cb_func_ptr)(const Elem*, std::streamsize count);

public:
	StandardOutputRedirector(std::ostream& stream, cb_func_ptr cb_func,
		void* data)
		: stream_(stream), cb_func_(cb_func), data_(data) {
		buf_ = stream_.rdbuf(this);
	};

	~StandardOutputRedirector() { stream_.rdbuf(buf_); }

	std::streamsize xsputn(const Elem* ptr, std::streamsize count) {
		cb_func_(ptr, count, data_);
		return count;
	}

	typename Tr::int_type overflow(typename Tr::int_type v) {
		Elem ch = Tr::to_char_type(v);
		cb_func_(&ch, 1, data_);
		return Tr::not_eof(v);
	}

private:
	std::basic_ostream<Elem, Tr>& stream_;
	std::streambuf* buf_;
	cb_func_ptr cb_func_;
	void* data_;
};

StandardOutputRedirector<char, std::char_traits<char>>* cout_redirector_;

