#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/csma-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main () {
    NodeContainer nodes;
    nodes.Create (20);

    CsmaHelper csma;
    csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));
    csma.SetChannelAttribute ("Delay", TimeValue (NanoSeconds (6560)));

    NetDeviceContainer devices = csma.Install (nodes);

    InternetStackHelper internet;
    internet.Install (nodes);

    Ipv4AddressHelper ip;
    ip.SetBase ("10.3.0.0", "255.255.255.0");
    ip.Assign (devices);

    AnimationInterface anim ("bus-topo.xml");

    for (uint32_t i = 0; i < nodes.GetN (); i++)
        anim.SetConstantPosition (nodes.Get (i), 20*i, 50);

    Simulator::Run ();
    Simulator::Destroy ();
}
