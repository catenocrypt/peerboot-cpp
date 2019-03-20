#include "../../include/peerboot.hpp"
#include <iostream>

using namespace pebo;
using namespace std;

void notification_cb(pebo::peer_t peer_in)
{
    cout << "Notification: " << (peer_in.removed ? "Removed" : "added  ") << " " << peer_in.service << " " << peer_in.endpoint << " " << peer_in.last_seen << endl;
}

int main()
{
    cout << "Sample PeerBoot Client, v" << PEBO_VERSION_MAJOR << "." << PEBO_VERSION_MINOR << endl;

    pebo::service_t service ("sample.peerboot.io");
    pebo::endpoint_t endpoint ("dummy_endpoint");
    pebo::errorCode err = pebo::init(service, endpoint, ::notification_cb);
    if (err)
    {
        cerr << "Could not initialize PeerBoot library, err: " << err << " service: " << service << " endpoint: " << endpoint << endl;
        return err;
    }
    cout << "PeerBoot library initialized, service: " << service << " endpoint: " << endpoint << endl;

    cout << "Press Enter to exit ...";
    cin.get();
    cout << endl;

    err = pebo::deinit();
    cout << "PeerBoot library deinitialized, err: " << err << endl;
}
