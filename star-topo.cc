#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main ()
{
    uint32_t nSpokes = 15;

    NodeContainer hub;
    hub.Create (1);

    NodeContainer spokes;
    spokes.Create (nSpokes);

    InternetStackHelper internet;
    internet.Install (hub);
    internet.Install (spokes);

    PointToPointHelper p2p;
    p2p.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
    p2p.SetChannelAttribute ("Delay", StringValue ("2ms"));

    Ipv4AddressHelper ip;
    ip.SetBase ("10.1.0.0", "255.255.255.0");

    for (uint32_t i = 0; i < nSpokes; ++i)
    {
        NetDeviceContainer devices =
            p2p.Install (hub.Get (0), spokes.Get (i));

        ip.Assign (devices);
        ip.NewNetwork ();   // ✅ THIS IS THE KEY
    }

    AnimationInterface anim ("star-topo.xml");
    anim.SetConstantPosition (hub.Get (0), 50, 50);

    for (uint32_t i = 0; i < nSpokes; ++i)
    {
        anim.SetConstantPosition (spokes.Get (i),
                                  10 + i * 5, 10);
    }

    Simulator::Run ();
    Simulator::Destroy ();
    return 0;
}

