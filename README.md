# ft_traceroute

1. Internet Protocol
   [RFC791](https://datatracker.ietf.org/doc/html/rfc791)
1. Internet Control Message Protocol
   [RFC792](https://datatracker.ietf.org/doc/html/rfc792)
1. User Datagram Protocol
   [rfc768](https://datatracker.ietf.org/doc/html/rfc768)
1. IBM Man about the traceroute cmmand
   [IBM_MAN_TRACEROUTE](https://www.ibm.com/docs/fr/power8?topic=commands-traceroute-command)

## TCPDUMP FILTER

```sh
# don't resolve ip addresses
sudo tcpdump -n

# filter on ip.identification == 0x01a4 (420)
sudo tcpdump ip[4:2] == 0x01a4

# filter on icmp
sudo tcpdump icmp

# filter by interface
sudo tcpdump -i wlan0

# show raw packet in hex
sudo tcpdump -x

# all together
sudo tcpdump -xni wlan0 ip[4:2] == 0x01a4 or icmp
```

## TODO

1. Finish check
	1. add check for dst ip i TimeExceed original packet
1. Add time calculation
1. Make 3 ping instead of one
1. Add more flags
