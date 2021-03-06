#pragma once
#include <ctime>
#include <fstream>
#include <string>

#include "ExpressState.h"

using std::ifstream;
using std::string;
extern string EXPRESS_DIR;

/**
 * @brief 快递类
 *
 */
class Express {
   private:
    /**
     * @brief 快递单号
     *
     */
    string expressId;
    /**
     * @brief 快递状态
     *
     */
    ExpressState state;
    /**
     * @brief 寄送时间
     *
     */
    time_t sendTime;
    /**
     * @brief 接收时间
     *
     */
    time_t receiveTime;
    /**
     * @brief 寄件用户
     *
     */
    string sender;
    /**
     * @brief 收件用户
     *
     */
    string receiver;
    /**
     * @brief 物品描述
     *
     */
    string description;
    /**
     * @brief 保存快递信息到本地
     *
     */
    void save();
    /**
     * @brief 获取保存文件的路径
     *
     * @return string 保存文件的路径
     */
    string getFilePath();

   public:
    /**
     * @brief 接收快递
     *
     */
    void Receive();

    /**
     * @brief 从文件中读取快递信息
     *
     * @param file 文件路径
     * @return Express* 快递指针
     */
    static Express* load(string file);
    ////////////////////////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////////////////////////

    Express(ifstream& in);
    Express(string sender, string receiver,
            string description = "No description");

    ////////////////////////////////////////////////////////////////////////////////
    // Getter and Setter
    ////////////////////////////////////////////////////////////////////////////////

    ExpressState getState();
    time_t getSendTime();
    time_t getReceiveTime();
    string getSender();
    string getReceiver();
    string getDescription();
    string getExpressId();
    string toString();
};