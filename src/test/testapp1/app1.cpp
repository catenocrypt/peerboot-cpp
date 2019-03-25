#include "../../include/peerboot.hpp"
#include "../testlib/test_pebo_net.hpp"
#include "../../peerboot/shell.hpp"
#include <iostream>
#include <memory>

using namespace pebo;
using namespace std;

void notificationCB(pebo::PeerInfo peer_in)
{
    cout << "Notification: " << (peer_in.removed ? "Removed" : "new    ") << " " << peer_in.service << " " << peer_in.endpoint << " " << peer_in.last_seen << endl;
}

int main()
{
    cout << "PeerBoot TestApp1, v" << PEBO_VERSION_MAJOR << "." << PEBO_VERSION_MINOR << endl;

    pebo::service_t service ("sample.peerboot.io");
    pebo::endpoint_t endpoint ("dummy_endpoint");

    // Create components
    auto testPeboNet = shared_ptr<IPeboNet>(make_shared<TestPeboNet>());
    Shell* shell = new Shell();
    shell->setPeboNet(testPeboNet);
    testPeboNet->setNotifyCB(shell);
    pebo::errorCode err = shell->init(service, endpoint, ::notificationCB);
    if (err)
    {
        cerr << "Could not initialize PeerBoot library, err: " << err << " service: " << service << " endpoint: " << endpoint << endl;
        return err;
    }
    cout << "PeerBoot library initialized, service: " << service << " endpoint: " << endpoint << endl;

    cout << "Press Enter to exit ...";
    cin.get();
    cout << endl;

    err = shell->deinit();
    cout << "PeerBoot library deinitialized, err: " << err << endl;
}
