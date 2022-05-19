#include <map>
#include <vector>

#include "User.h"
using std::map;
using std::vector;
/**
 * @brief 控制类
 * 控制程序的启动、关闭、更新等
 */
class Controller {
   private:
    vector<Person*> personList;
    map<string, Person*> personMap;
    void addPerson(Person*);

   public:
    /**
     * @brief Construct a new Controller object
     *
     */
    Controller();
    /**
     * @brief Destroy the Controller object
     *
     */
    ~Controller();
    /**
     * @brief 控制类的主函数
     * （其实是个死循环，监听各类操作
     */
    void run();

    //////////////////////////////////////////////////////////////////////////////
    // User 区
    //////////////////////////////////////////////////////////////////////////////
    /**
     * @brief 用户注册
     *
     */
    void registerUser();
    /**
     * @brief 用户登录
     *
     */
    void loginUser();
    /**
     * @brief 用户修改密码
     *
     */
    void changePassword();
    /**
     * @brief 用户查询余额
     *
     */
    void queryBalance();
    /**
     * @brief 用户充值
     *
     */
    void recharge();
    /**
     * @brief 用户发送快递
     *
     */
    void sendExpress();
    /**
     * @brief 用户接受快递
     *
     */
    void receiveExpress();
    /**
     * @brief 用户查询快递
     *
     */
    void queryExpress();

    //////////////////////////////////////////////////////////////////////////////
    // Admin 区
    //////////////////////////////////////////////////////////////////////////////

    /**
     * @brief 物流公司管理员查询用户信息
     *
     */
    void queryUserInfo();
    /**
     * @brief 物流公司管理员查询历史快递信息
     *
     */
    void queryExpressInfo();
};