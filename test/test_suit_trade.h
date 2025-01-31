#ifndef _TEST_SUIT_H_
#define _TEST_SUIT_H_

#pragma once

#include <iostream>
#include <gtest/gtest.h>
#include "apiWrapper/ctp/MyCtpApi.h"

#ifdef ENVSIMNOW
const std::string brokerid = "9999";
const std::string userid = "123616";
const std::string pwd = "nanase4ever";
const std::string frontAddr = "tcp://180.168.146.187:10130";
//const std::string frontAddr = "tcp://180.168.146.187:10130";
    
const std::string appid = "simnow_client_test";
const std::string authcode = "0000000000000000";
#endif 


#ifdef ENVGTJA
const std::string brokerid = "2071";
const std::string userid = "00004703";
const std::string pwd = "888888";
const std::string frontAddr = "tcp://180.169.50.131:42205";
const std::string appid = "simnow_client_test";
const std::string authcode = "0000000000000000"; 
#endif


class TradeApiTest: public testing::Test {

    protected:

    virtual void SetUp() override {

        p_api = new MyCtpApi(brokerid, userid, pwd, frontAddr, appid, authcode);
        p_api->Init();
        usleep(1000000);
        EXPECT_EQ(p_api->GetConnectStatus(), true);
        p_api->ReqAuth();
        usleep(1000000);
        EXPECT_EQ(p_api->GetAuthStatus(), true);
        p_api->ReqUserLogin();
        usleep(1000000);
        EXPECT_EQ(p_api->GetLoginStatus(), true);

        p_api->ReqSettlementInfoConfirm();

        usleep(100000);
    };

    virtual void TearDown() override {
        delete p_api;
        p_api = nullptr;
    }

    MyCtpApi * p_api;
};




#endif