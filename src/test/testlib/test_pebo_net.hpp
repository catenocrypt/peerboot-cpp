#pragma once
#include "../../peerboot/ipebo_net.hpp"

namespace pebo
{
    class TestPeboNet : public IPeboNet
    {
    public:
        TestPeboNet() = default;
        void setNotifyCB(IPeboNetCB* peboNetCB_in);
        errorCode init();
        errorCode broadcast(peer_t peer_in);

    private:
        errorCode doClientCallback(peer_t peer_in);

    private:
        IPeboNetCB* myPeboNetCB;
    };
}