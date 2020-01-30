/**
 * @file Logger.cpp
 *
 * @brief Implements logging modules
 *
 * © 2018 Tarsha Systems Co.
 * All rights reserved
 * See the license file which came with this software for more details
 *
 */

#include "layer_management/Logger.hpp"
#include <time.h>
#include <string.h>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/sinks/syslog_backend.hpp>

namespace logging   = boost::log;
namespace sinks     = boost::log::sinks;
namespace src       = boost::log::sources;
namespace expr      = boost::log::expressions;
namespace attrs     = boost::log::attributes;
namespace keywords  = boost::log::keywords;

static bool gInitialized;

char *getTime()
{
    static char name[20];
    time_t now = time(0);

    strftime(name, sizeof(name), "%Y%m%d_%H%M%S", localtime(&now));

    std::cout << name;

    return name;

}

void InitLogger(const std::string & TagArg, boost::log::trivial::severity_level LogLevelArg, const std::string & LogDir)
{
    gInitialized = true;

    logging::add_common_attributes();

    logging::formatter formatter = expr::stream
        << expr::attr< unsigned int >("LineID") << ": "
        << "[Tid = " << expr::attr< boost::log::attributes::current_thread_id::value_type >("ThreadID") << "] "
        << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
        << " <" << expr::attr< logging::trivial::severity_level >("Severity") << "> "
        << TagArg << ": "
        << expr::message;

    logging::core::get()->set_filter
    (
        expr::attr< logging::trivial::severity_level >("Severity") >= LogLevelArg
    );

    // Creating a syslog sink.
    boost::shared_ptr< boost::log::sinks::synchronous_sink< boost::log::sinks::syslog_backend > > sink;

    sink.reset(new boost::log::sinks::synchronous_sink< boost::log::sinks::syslog_backend >
    (
            keywords::use_impl = boost::log::v2_mt_posix::sinks::syslog::native,
            keywords::facility = boost::log::v2_mt_posix::sinks::syslog::local3
    ));
    sink->set_formatter(formatter);

    // We'll have to map our custom levels to the syslog levels
    boost::log::sinks::syslog::custom_severity_mapping< logging::trivial::severity_level > mapping("Severity");
    mapping[logging::trivial::debug]    = boost::log::v2_mt_posix::sinks::syslog::debug;
    mapping[logging::trivial::info]     = boost::log::v2_mt_posix::sinks::syslog::info;
    mapping[logging::trivial::warning]  = boost::log::v2_mt_posix::sinks::syslog::warning;
    mapping[logging::trivial::error]    = boost::log::v2_mt_posix::sinks::syslog::error;
    mapping[logging::trivial::fatal]    = boost::log::v2_mt_posix::sinks::syslog::critical;
    sink->locked_backend()->set_severity_mapper(mapping);
    boost::log::core::get()->add_sink(sink);

    std::string name;
    time_t now = time(0);
    name += LogDir;
    name += "pcap_";
    name +=  (std::string) getTime();

    name += "_%N.log";

    logging::add_file_log
    (
        //TODO: get it from config; append timestamp
        keywords::file_name             = name, 
        keywords::rotation_size         = 10 * 1024 * 1024,
        keywords::time_based_rotation   = sinks::file::rotation_at_time_point(0, 0, 0)
    )->set_formatter(formatter);

    logging::add_console_log()->set_formatter(formatter);
}

void InitLogger()
{
    if (!gInitialized)
    {
        gInitialized = true;
        InitLogger(std::string("TAG"), logging::trivial::severity_level::debug,"./");
    }
}
