/**
 * @file Logger.hpp
 *
 * @brief Logging module
 *
 * Logging module used to log all messages. Based on the
 * how it's configured, it can log to syslog, log file and
 * console.
 *
 * © 2018 Tarsha Systems Co.
 * All rights reserved
 * See the license file which came with this software for more details
 *
 */ 
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/attributes/mutable_constant.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

#define LogDebug \
  BOOST_LOG_SEV(gGlobalLoggerMt::get(), logging::trivial::debug) << __FILE__  << ":" << __LINE__ << " " << BOOST_CURRENT_FUNCTION << " "

#define LogInfo \
  BOOST_LOG_SEV(gGlobalLoggerMt::get(), logging::trivial::info) << __FILE__  << ":" << __LINE__ << " " << BOOST_CURRENT_FUNCTION << " "

#define LogWarning \
  BOOST_LOG_SEV(gGlobalLoggerMt::get(), logging::trivial::warning) << __FILE__  << ":" << __LINE__ << " " << BOOST_CURRENT_FUNCTION << " "

#define LogError \
  BOOST_LOG_SEV(gGlobalLoggerMt::get(), logging::trivial::error) << __FILE__  << ":" << __LINE__ << " " << BOOST_CURRENT_FUNCTION << " "

#define LogFatal \
  BOOST_LOG_SEV(gGlobalLoggerMt::get(), logging::trivial::fatal) << __FILE__  << ":" << __LINE__ << " " << BOOST_CURRENT_FUNCTION << " "

namespace logging   = boost::log;
namespace src       = boost::log::sources;

void InitLogger();
void InitLogger(const std::string & TagArg, boost::log::trivial::severity_level LogLevelArg,  const std::string & LogDir);

typedef boost::log::sources::severity_logger_mt<logging::trivial::severity_level> GlobalLoggerMtType;

BOOST_LOG_INLINE_GLOBAL_LOGGER_INIT(gGlobalLoggerMt, GlobalLoggerMtType)
{
    InitLogger();
    GlobalLoggerMtType aGlobalSeverityLogger;
    return aGlobalSeverityLogger;
}

#endif /* LOGGER_HPP */
