#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main () {
    NodeContainer nodes;
    nodes.Create (16);

    InternetStackHelper internet;
    internet.Install (nodes);

    PointToPointHelper p2p;
    p2p.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
    p2p.SetChannelAttribute ("Delay", StringValue ("2ms"));

    Ipv4AddressHelper ip;
    ip.SetBase ("10.4.0.0", "255.255.255.0");

    for (uint32_t i = 0; i < nodes.GetN (); i++) {
        NetDeviceContainer dev =
          p2p.Install (nodes.Get(i), nodes.Get((i+1)%nodes.GetN()));
        ip.Assign (dev);
        ip.NewNetwork ();
    }

    AnimationInterface anim ("ring-topo.xml");

    Simulator::Run ();
    Simulator::Destroy ();
}
