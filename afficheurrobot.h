#ifndef AFFICHEURROBOT_H
#define AFFICHEURROBOT_H
#include "robot.h"
#include "goto_xy_windows.h"
#include <windows.h>

class afficheurRobot : public observateur
{
    public:
        void update(const robot &r) override;
        virtual void afficherStatistique() override{};
};

#endif // AFFICHEURROBOT_H
