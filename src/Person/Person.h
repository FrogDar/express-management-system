#pragma once
#include <fstream>
#include <string>
using std::ifstream;
using std::string;

extern string USER_DIR;

/**
 * @brief 用户类型
 *
 */
enum class PersonType {
    /**
     * @brief 普通用户
     *
     */
    USER,
    /**
     * @brief 管理员
     *
     */
    ADMIN
};

/**
 * @brief 各种用户的基类
 *
 */
class Person {
   protected:
    /**
     * @brief 账户余额
     *
     */
    double balance = 0;
    /**
     * @brief 用户名
     *
     */
    string username;
    /**
     * @brief 姓名
     *
     */
    string nickname;
    /**
     * @brief 密码
     *
     */
    string password;
    /**
     * @brief 用户类型
     *
     */
    PersonType type;
    /**
     * @brief 保存文件至本地
     *
     */
    virtual void save();

   public:
    /**
     * @brief 从文件中获取指针
     *
     * @return Person*
     */
    static Person* load(string file);
    /**
     * @brief 简要信息
     *
     * @return string 简要信息
     */
    string toString();
    /**
     * @brief 具体信息
     *
     * @return string 具体信息
     */
    virtual string toDetailString() = 0;

    Person(ifstream& in);
    Person() = default;

    ////////////////////////////////////////////////////////////////////////////////
    // Getter and Setter
    ////////////////////////////////////////////////////////////////////////////////

    PersonType getType();
    void setBalance(double balance);
    double getBalance();
    void setUsername(string username);
    string getUsername();
    void setNickname(string nickname);
    string getNickname();
    void setPassword(string password);
    bool checkPassword(string password);
};
