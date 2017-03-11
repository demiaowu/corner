//
// Created by demiaowu on 17-3-10.
//

#ifndef CORNER_LOGGING_H
#define CORNER_LOGGING_H

#include <sstream>


class LogStream {
public:
    template<typename T>
    LogStream& operator<<(const T& t) {
        oss_ << t << " ";
        return *this;
    }

private:
    friend class Logger;
    std::ostringstream oss_;
};

class Logger {
public:
    enum LogLevel {
        TRACE = 0,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        NUM_LOG_LEVELS,
    };
    //TODO
    class SourceFile {

    };

    Logger(const char* file, int line, LogLevel level, const char* func);
    ~Logger();

    LogStream& stream() {   return stream_; }

    static LogLevel logLevel();
    static void setLogLevel(LogLevel level);

    typedef void (*OutputFunc)(const char*msg, int len);
    typedef void (*FlushFunc)();

    static void setOutput(OutputFunc);
    static void setFlush(FlushFunc);

private:
    LogLevel level_;
    LogStream stream_;
};




#define LOG_TRACE if( Logger::logLevel() <= Logger::TRACE )  \
    Logger(__FILE__, __LINE__, Logger::TRACE, __func__).stream()

#define LOG_DEBUG if( Logger::logLevel() <= Logger::DEBUG ) \
    Logger(__FILE__, __LINE__, Logger::DEBUG, __func__).stream()

#define LOG_INFO if( Logger::logLevel() <= Logger::INFO ) \
    Logger(__FILE__, __LINE__, Logger::INFO, __func__).stream()

#define LOG_WARN Logger(__FILE__, __LINE__, Logger::WARN, __func__).stream()

#define LOG_ERROR Logger(__FILE__, __LINE__, Logger::ERROR, __func__).stream()

#define LOG_FATAL Logger(__FILE__, __LINE__, Logger::FATAL, __func__).stream()

//#define LOG_WARN if( Logger::logLevel() <= Logger::WARN ) \
//    Logger(__FILE__, __LINE__, Logger::WARN, __func__).stream()
//
//#define LOG_ERROR if( Logger::logLevel() <= Logger::ERROR ) \
//    Logger(__FILE__, __LINE__, Logger::ERROR, __func__).stream()
//
//#define LOG_FATAL if( Logger::logLevel() <= Logger::FATAL ) \
//    Logger(__FILE__, __LINE__, Logger::FATAL, __func__).stream()

#endif //CORNER_LOGGING_H
