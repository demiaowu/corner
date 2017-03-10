//
// Created by demiaowu on 17-3-10.
//

#include <gtest/gtest.h>

#include "Logging.h"

TEST(LoggingTest, usage) {

    LOG_TRACE << "trace" << "\n";
    LOG_DEBUG << "debug" << "\n";
    LOG_INFO << "info" << "\n";
    LOG_WARN << "warn" << "\n";
    LOG_ERROR << "error" << "\n";
    //LOG_FATAL << "fatal" << "\n";
    EXPECT_TRUE(1);

    Logger::setLogLevel(Logger::TRACE);
    LOG_TRACE << "trace" << "\n";
    LOG_DEBUG << "debug" << "\n";
    LOG_INFO << "info" << "\n";
    LOG_WARN << "warn" << "\n";
    LOG_ERROR << "error" << "\n";
    LOG_FATAL << "fatal" << "\n";

}
