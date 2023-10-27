#pragma once

#include <memory>
#include <optional>

#include "Conf/Conf.h"
#include "MaaFramework/MaaDef.h"
#include "Utils/NoWarningCVMat.hpp"

MAA_DBG_CTRL_UNIT_NS_BEGIN

class ControllerAPI
{
public:
    virtual ~ControllerAPI() = default;

    virtual bool connect() = 0;
    virtual bool kill_server() = 0;

    virtual std::string get_uuid() const = 0;
    virtual cv::Size get_resolution() const = 0;
    virtual int get_orientation() const = 0;

    virtual bool start(const std::string& intent) = 0;
    virtual bool stop(const std::string& intent) = 0;

    virtual bool click(int x, int y) = 0;
    virtual bool swipe(int x1, int y1, int x2, int y2, int duration) = 0;

    virtual bool touch_down(int contact, int x, int y, int pressure) = 0;
    virtual bool touch_move(int contact, int x, int y, int pressure) = 0;
    virtual bool touch_up(int contact) = 0;

    virtual bool press_key(int key) = 0;

    virtual std::optional<cv::Mat> screencap() = 0;
};

std::shared_ptr<ControllerAPI> MAA_CONTROL_UNIT_API create_controller(MaaStringView read_path, MaaStringView write_path,
                                                                      MaaDbgControllerType type, MaaStringView config);

MAA_DBG_CTRL_UNIT_NS_END
