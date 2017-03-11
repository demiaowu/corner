//
// Created by demiaowu on 17-3-10.
//

#include <gtest/gtest.h>

#include "Logging.h"

TEST(LoggingTest, usage) {

    LOG_TRACE << "trace";
    LOG_DEBUG << "debug";
    LOG_INFO << "info";
    LOG_WARN << "warn";
    LOG_ERROR << "error";
    //LOG_FATAL << "fatal";
    EXPECT_TRUE(1);

    Logger::setLogLevel(Logger::TRACE);
    LOG_TRACE << "trace" << "ceshi";
    LOG_DEBUG << "debug" << "ceshi" << "cecshi1";
    LOG_INFO << "info" << "ceshi" << "ceshi1" << "ceshi2";
    LOG_WARN << "warn";
    LOG_ERROR << "error";
    LOG_FATAL << "fatal";

}
