//
// Created by demiaowu on 17-3-10.
//

#include "Logging.h"

Logger::LogLevel initLogLevel() {
    return Logger::INFO;
}

void defaultOutput(const char* msg, int len) {
    size_t n = ::fwrite(msg, 1, len, ::stdout);
    (void)n;    // Eliminate the warning
}

void defaultFlush() {
    ::fflush(::stdout);
}

Logger::LogLevel g_logLevel = initLogLevel();
Logger::OutputFunc g_output = defaultOutput;
Logger::FlushFunc g_flush = defaultFlush;

const char* LogLevelNames[Logger::NUM_LOG_LEVELS] = {
        "TRACE",
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR",
        "FATAL",
};

Logger::~Logger() {
    g_output(stream_.oss_.str().c_str(), stream_.oss_.str().size());
    if (level_ == FATAL) {
        g_flush();
        ::abort();
    }
}

Logger::LogLevel Logger::logLevel() {
    return g_logLevel;
}

void Logger::setLogLevel(Logger::LogLevel level) {
    g_logLevel = level;
}

void Logger::setOutput(Logger::OutputFunc out) {
    g_output = out;
}

void Logger::setFlush(Logger::FlushFunc flush) {
    g_flush = flush;
}

Logger::Logger(const char* file, int line, Logger::LogLevel level, const char *func) {
    level_ = level;
    stream_<< file << line << LogLevelNames[level_] << func;
}
