#pragma once

#include <mastermyr/date_time.hpp>

#include <cstdint>
#include <string>
#include <optional>


namespace Did::Models {

class Task
{
public:

// private:
	uint64_t m_id;
	std::string m_description;
	bool m_completed;
	myr::DateTime<myr::TimeZone::UTC> m_created_time;
	myr::DateTime<myr::TimeZone::UTC> m_completed_time;
	std::optional<uint64_t> m_parent_id;
};

}
