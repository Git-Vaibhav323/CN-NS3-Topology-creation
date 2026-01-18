#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/csma-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main () {
    NodeContainer hub;
    hub.Create (1);

    NodeContainer starNodes;
    starNodes.Create (10);

    NodeContainer busNodes;
    busNodes.Create (14);

    InternetStackHelper internet;
    internet.InstallAll ();

    PointToPointHelper p2p;
    p2p.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));

    Ipv4AddressHelper ip;
    ip.SetBase ("10.5.0.0", "255.255.255.0");

    for (uint32_t i = 0; i < starNodes.GetN (); i++) {
        NetDeviceContainer dev = p2p.Install (hub.Get(0), starNodes.Get(i));
        ip.Assign (dev);
        ip.NewNetwork ();
    }

    CsmaHelper csma;
    csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));

    NodeContainer busAll;
    busAll.Add (hub);
    busAll.Add (busNodes);

    NetDeviceContainer busDev = csma.Install (busAll);
    ip.Assign (busDev);

    AnimationInterface anim ("hybrid-topo.xml");

    Simulator::Run ();
    Simulator::Destroy ();
}
