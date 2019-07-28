#include "RE/BSString.h"

#include "skse64/GameTypes.h"  // BSString

#include <cassert>  // assert
#include <string>  // char_traits


namespace RE
{
	BSString::BSString() :
		_data(0),
		_dataLen(0),
		_bufLen(0),
		_pad0C(0)
	{
		set_cstr("");
	}


	BSString::BSString(const BSString& a_rhs) :
		_data(0),
		_dataLen(0),
		_bufLen(0),
		_pad0C(0)
	{
		set_cstr(a_rhs.c_str());
	}


	BSString::BSString(BSString&& a_rhs) :
		_data(std::move(a_rhs._data)),
		_dataLen(std::move(a_rhs._dataLen)),
		_bufLen(std::move(a_rhs._bufLen)),
		_pad0C(0)
	{
		a_rhs._data = 0;
		a_rhs._dataLen = 0;
		a_rhs._bufLen = 0;
	}


	BSString::BSString(const char* a_rhs) :
		_data(0),
		_dataLen(0),
		_bufLen(0),
		_pad0C(0)
	{
		set_cstr(a_rhs);
	}


	BSString::BSString(const std::string_view& a_rhs)
	{
		set_cstr(a_rhs.data(), a_rhs.size());
	}


	BSString::~BSString()
	{
		free(_data);
		_data = 0;
	}


	BSString& BSString::operator=(const BSString& a_rhs)
	{
		set_cstr(a_rhs.c_str());
		return *this;
	}


	BSString& BSString::operator=(BSString&& a_rhs)
	{
		_data = std::move(a_rhs._data);
		a_rhs._data = 0;

		_dataLen = std::move(a_rhs._dataLen);
		a_rhs._dataLen = 0;

		_bufLen = std::move(a_rhs._bufLen);
		a_rhs._bufLen = 0;

		return *this;
	}


	BSString& BSString::operator=(const char* a_rhs)
	{
		set_cstr(a_rhs);
		return *this;
	}


	BSString& BSString::operator=(const std::string_view& a_rhs)
	{
		set_cstr(a_rhs.data(), a_rhs.size());
		return *this;
	}


	auto BSString::operator[](size_type a_pos)
		-> reference
	{
		return _data[a_pos];
	}


	auto BSString::operator[](size_type a_pos) const
		-> const_reference
	{
		return _data[a_pos];
	}


	char& BSString::front()
	{
		return operator[](0);
	}


	const char& BSString::front() const
	{
		return operator[](0);
	}


	char& BSString::back()
	{
		return operator[](size() - 1);
	}


	const char& BSString::back() const
	{
		return operator[](size() - 1);
	}


	const char* BSString::data() const noexcept
	{
		return _data ? _data : "";
	}


	char* BSString::data() noexcept
	{
		return _data ? _data : "";
	}


	const char* BSString::c_str() const noexcept
	{
		return data();
	}


	BSString::operator std::string_view() const noexcept
	{
		return { data(), size() };
	}


	[[nodiscard]] bool BSString::empty() const noexcept
	{
		return length() == 0;
	}


	auto BSString::size() const noexcept
		-> size_type
	{
		return (_dataLen != kMaxSize) ? _dataLen : std::char_traits<char>::length(_data);
	}


	auto BSString::length() const noexcept
		-> size_type
	{
		return size();
	}


	void BSString::clear() noexcept
	{
		set_cstr("");
	}


	bool BSString::set_cstr(const char* a_str, UInt32 a_len)
	{
		using func_t = function_type_t<decltype(&BSString::set_cstr)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSString, Set, func_t*);
		bool result = func(this, a_str, a_len);
		assert(result == true);
		return result;
	}
}
