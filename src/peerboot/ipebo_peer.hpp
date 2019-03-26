#pragma once
#include "../include/peerboot.hpp"
#include "ipebo_peer_cb.hpp"

namespace pebo
{
    /**
     * Represents a PeerBoot peer.
     */
    class IPeboPeer
    {
    public:
        virtual void setNotifyCB(IPeboPeerCB* peboPeerCB_in) = 0;
        // Send a peer info towards this peer
        virtual errorCode send(PeerInfo const & peer_in) = 0;
    };
}